#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef complex<int> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int n;
vi pos[maxn];
vi mon[maxn];
int L[maxn];

pii get(vector<int> &P){
	int l = 0, h = n + 1;

	while (l + 1 < h){
		int m = (l + h) / 2;
		int tot = n - m + 1;
		int ctot = 0;

		for (auto &v : P){
			int idx = pos[v].end() - lower_bound(pos[v].begin(), pos[v].end(), m);
//			cout << v << " " << idx << endl;
			ctot += idx;
		}

//		cout << l << " " << h << " " << m << " " << ctot << " " << tot << endl;

		if (ctot == tot)
			h = m;
		else
			l = m;
	}

	int w = L[l];
	int idx = lower_bound(pos[w].begin(), pos[w].end(), l) - pos[w].begin();

	return pii(w, idx);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	pos[0].push_back(0);
	mon[0].push_back(0);

	for (int i = 1; i <= n; ++i){
		int a, b;
		cin >> a >> b;

		pos[a].push_back(i);
		mon[a].push_back(b);
		L[i] = a;
	}

	int q; cin >> q;

	while (q--){
		int t; cin >> t;

		vector<int> P(t);

		for (int i = 0; i < t; ++i)
			cin >> P[i];

		pii A = get(P);

//		cout << A.first << " " << A.second << endl;

		if (A.first == 0){
			cout << 0 << " " << 0 << endl;
		}
		else{
			P.push_back(A.first);
			pii B = get(P);

			int mom = pos[B.first][B.second];

			int idx = lower_bound(pos[A.first].begin(), pos[A.first].end(), mom) - pos[A.first].begin();

			cout << A.first << " " << mon[A.first][idx] << endl;
		}
	}

	return 0;
}
/*
6
1 10
2 100
3 1000
1 10000
2 100000
3 1000000
1
1 3
2 2 3
2 1 2
 */