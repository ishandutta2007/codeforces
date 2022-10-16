#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int maxb = 30;
/*

2 3
0 0
1 1 1 1
1 1 2 2
2 1 2

 */
struct base{
	int b[maxb];

	base(){
		clear();
	}

	void clear(){
		memset(b, 0, sizeof b);
	}

	void add(int v){
		while (v){
			int p = __lg(v);
			if (b[p])
				v ^= b[p];
			else{
				b[p] = v;
				v = 0;
			}
		}
	}

	int value(){
		int ans = 0;
		for (int i = 0; i < maxb; ++i)
			if (b[i]) ++ans;
		return 1 << ans;
	}

	void print(){
		for (int i = 0; i < 2; ++i) cout << b[i] << " ";
		cout << endl;
	}
};

struct bit{
	int b[maxn];

	bit(){
		memset(b, 0, sizeof b);
	}

	void update(int idx, int v, bool print=false){
		for (;idx < maxn; idx += idx & -idx){
			b[idx] ^= v;
		}
	}

	int query(int idx){
		int ans = 0;
		for (;idx; idx -= idx & -idx)
			ans ^= b[idx];
		return ans;
	}
} B;

base merge(base a, base b){
	for (int i = 0; i < maxb; ++i)
		a.add(b.b[i]);
	return a;
}

base st[4 * maxn];
int value[maxn];

void build(int p, int b, int e){
	if (b + 1 == e) st[p].add(value[b]);
	else{
		int m = (b + e) >> 1;
		int l = p << 1, r = l | 1;
		build(l, b, m); build(r, m, e);
		st[p] = merge(st[l], st[r]);
	}
}

void update(int p, int b, int e, int x){
	if (b + 1 == e){
		st[p].clear();
		st[p].add(value[x]);
	}
	else{
		int m = (b + e) >> 1;
		int l = p << 1, r = l | 1;

		if (x < m) update(l, b, m, x);
		else update(r, m, e, x);

		st[p] = merge(st[l], st[r]);
	}
}

base query(int p, int b, int e, int x, int y){

	if (x <= b && e <= y) return st[p];
	int m = (b + e) >> 1;
	int l = p << 1, r = l | 1;
	base ans;
	if (x < m) ans = query(l, b, m, x, y);
	if (m < y) ans = merge(ans, query(r, m, e, x, y));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> value[i];

	for (int i = n; i; --i){
		value[i] ^= value[i - 1];
		B.update(i, value[i]);
	}

	int N = n + 1;

	build(1, 0, N);

	while (q--){
		int t, x, y, k;
		cin >> t;
		if (t == 1){
			cin >> x >> y >> k;

			B.update(x, k);
			value[x] ^= k;
			update(1, 0, N, x);

			if (y < N){
				B.update(y + 1, k, true);
				value[y + 1] ^= k;
				update(1, 0, N, y + 1);
			}
		}
		else{
			cin >> x >> y;

			base b = x < y ? query(1, 0, N, x + 1, y + 1) : base();
			b.add(B.query(x));
			cout << b.value() << endl;
		}
	}


	return 0;
}