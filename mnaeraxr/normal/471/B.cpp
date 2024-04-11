#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int tot[2010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> V(n);
	for (int i = 0; i < n; ++i){
		cin >> V[i].first;
		V[i].second = i + 1;
		tot[V[i].first]++;
	}
	sort(V.begin(), V.end());

	pii a, b;

	for (int i = 0; i < 2010; ++i){
		pii cur = MP(tot[i], i);
		if (cur > a)
			b = a, a = cur;
		else if (cur > b)
			b = cur;
	}

	if (a.first >= 3 || b.first >= 2){
		cout << "YES" << endl;

		for (int i = 0; i < n; ++i)
			cout << V[i].second << " ";
		cout << endl;

		bool ok = true;
		for (int i = 0; i < n; ++i){
			if (ok && V[i].first == a.second){
				swap(V[i], V[i + 1]);
				ok = false;
			}
			cout << V[i].second << " ";
		}
		cout << endl;

		if (a.first >= 3){
			for (int i = n - 1; i >= 0; --i){
				if (V[i].first == a.second){
					swap(V[i], V[i  -1]);
					break;
				}
			}
		}
		else{
			for (int i = 0; i < n; ++i){
				if (V[i].first == b.second){
					swap(V[i], V[i + 1]);
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i)
			cout << V[i].second << " ";
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}