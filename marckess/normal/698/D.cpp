#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005;
int n, k, ax[10], ay[10], x[MX], y[MX], pind[10][MX], pvec[10][MX], p[10], vis[MX], pv, res;
vvi v[10];

#define sq(n) (ll(n) * ll(n))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k >> n;
	forn (i, k) cin >> ax[i] >> ay[i];
	forn (i, n) cin >> x[i] >> y[i];

	forn (i, k) {
		map<ii, int> mp;

		forn (j, n) {
			int g = abs(__gcd(ax[i] - x[j], ay[i] - y[j]));
			ii m = {(ax[i] - x[j]) / g, (ay[i] - y[j]) / g};
			
			if (!mp.count(m)) {
				int sz = mp.size();
				mp[m] = sz;
				v[i].emplace_back(0);
			}

			pvec[i][j] = mp[m];
			v[i][mp[m]].push_back(j);
		}

		for (vi &v : v[i]) {
			sort(all(v), [&] (int it, int jt) {
				return sq(ax[i] - x[it]) + sq(ay[i] - y[it]) < sq(ax[i] - x[jt]) + sq(ay[i] - y[jt]);
			});

			forn(j, v.size())
				pind[i][v[j]] = j; 
		}
	}

	forn (j, n) {
		iota(p, p+k, 0);

		do {
			int f = 0;
			pv++;
			queue<int> q;

			vis[j] = pv;
			q.push(j);

			forn (i, k) {
				int u = q.front();
				q.pop();
				
				int in = pvec[p[i]][u];
				int ind = pind[p[i]][u];
				ind--;

				while (ind >= 0) {
					if (vis[v[p[i]][in][ind]] != pv) {
						int w = v[p[i]][in][ind];
						vis[w] = pv;
						q.push(w);
						if (q.size() > k) break;
					}
					ind--;
				}

				if (q.size() > k) break;
				if (q.empty()) {
					f = 1;
					break;
				}
			}

			if (f) {
				res++;
				break;
			}
		} while (next_permutation(p, p + k));
	}

	cout << res << endl; 

	return 0;
}