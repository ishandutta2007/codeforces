
#include<bits/stdc++.h>

#define endl '\n'
using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef multiset<int> ms;

const int oo = 0x3f3f3f3f;
const int maxn = 300000 + 10;

int n;
int64 val[maxn];

int sg(int64 v){
	if (v == 0) return 0;
	return v > 0 ? 1 : -1;
}

struct data{
	set<pii> I;
	multiset<int> SZ;

	void insert(pii a){
		if (a.second <= a.first)
			return;

		I.insert(a);
		SZ.insert(a.second - a.first);
	}

	int value(){
		return *SZ.rbegin() + 1;
	}

	void erase(pii a){
		I.erase(a);
		SZ.erase(SZ.find(a.second - a.first));
	}

	pii getinterval(int p){
		auto it = I.upper_bound(pii(p, oo));
		it--;
		return *it;
	}
};

void change(int p, int64 prev, int64 cur, data &D){
//	cout << p << " " << prev << " " << cur << endl;
	if (sg(prev) == sg(cur)) return;

	if (sg(cur) == 0){
		pii I = D.getinterval(p);

		D.erase(I);

		D.insert(pii(I.first, p));
		D.insert(pii(p, p + 1));
		D.insert(pii(p + 1, I.second));
		return;
	}

	if (sg(prev) == 0){
//		cout << "here" << endl;
//		cout << p << " " << cur << " " << prev << endl;
		pii I = D.getinterval(p);
		D.erase(I);

		pii N(p, p + 1);

		if (p < n && val[p + 1] != 0 && sg(cur) >= sg(val[p + 1])){
			pii T = D.getinterval(p + 1);
			D.erase(T);

			N.second = T.second;
		}

		if (p > 2 && val[p - 1] != 0 && sg(val[p - 1]) >= sg(cur)){
			pii T = D.getinterval(p - 1);
			D.erase(T);

			N.first = T.first;
		}

		D.insert(N);
		return;
	}

	pii I = D.getinterval(p);
	D.erase(I);

	if (p + 1 == I.second && p < n && val[p + 1] != 0 && sg(cur) >= sg(val[p + 1])){
		pii T = D.getinterval(p + 1);
		D.erase(T);
		I.second = T.second;
	}

	if (p + 1 < I.second){
		if (sg(cur) < sg(val[p + 1])){
			D.insert(pii(p + 1, I.second));
			I.second = p + 1;
		}
	}

	if (p == I.first && p > 2 && val[p - 1] != 0 && sg(cur) <= sg(val[p - 1])){
		pii T = D.getinterval(p - 1);
		D.erase(T);
		I.first = T.first;
	}

	if (p > I.first){
		if (sg(val[p - 1]) < sg(cur)){
			D.insert(pii(I.first, p));
			I.first = p;
		}
	}

	D.insert(I);
}

void print(data &D){
	cout << "debug" << endl;
	for (int i = 2; i <= n; ++i)
		cout << val[i] << " ";
	cout << endl;
	for (int i = 2; i <= n; ++i)
		cout << sg(val[i]) << " ";
	cout << endl;

	for (auto p : D.I) cout << p.first << " " << p.second << endl;

	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> val[i];

	int tzero = 0;

	for (int i = n; i; --i){
		val[i] -= val[i - 1];
		if (val[i] == 0) tzero++;
	}

	data D;

	for (int i = 2, j; i <= n; i = j){

		if (val[i] == 0){
			D.insert(pii(i, i + 1));
			j = i + 1;
			continue;
		}

		bool pos = true;
		j = i;

		while (j <= n){
			if (val[j] == 0) break;

			if (sg(val[j]) == -1) pos = false;
			if (val[j] > 0 && !pos) break;

			++j;
		}

		D.insert(pii(i, j));
	}

	int q; cin >> q;

	while (q--){
		int x, y;
		int64 d;
		cin >> x >> y >> d;

		if (x > 1){
			int64 prev = val[x];
			val[x] += d;

			change(x, prev, val[x], D);

			if (prev == 0) tzero--;
			if (val[x] == 0) tzero++;

//			print(D);
		}

		if (y < n){
			int64 prev = val[y + 1];
			val[y + 1] -= d;

			if (prev == 0) tzero--;
			if (val[y + 1] == 0) tzero++;

			change(y + 1, prev, val[y + 1], D);
//			print(D);
		}

		if (tzero + 1 == n) cout << 1 << endl;
		else cout << D.value() << endl;

//		cout.flush();
	}
}
/*
2
3 3
1
1 2 3
 */