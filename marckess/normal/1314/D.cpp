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
typedef vector<ii> vii;

const int MX = 200005;
int n, K, a[88][88], ex[88], b[88];
vii mn[88][88];
ll res = 2e9;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> K;
	
	forn (i, n) forn(j, n) cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				if (k != i && k != j)
					mn[i][j].emplace_back(a[i][k] + a[k][j], k);
			sort(all(mn[i][j]));
		}

	for (int i = 0; i <= 0; i++) {
		ex[i]++;
		b[0] = i;

		if (K == 2) {
			b[1] = b[0];
			ll p = 0;

			for (int r = 0; r < K / 2; r++) {
				int t = 0;
				while (t < mn[b[r]][b[r + 1]].size() && ex[ mn[b[r]][b[r + 1]][t].se ]) t++;
				if (t == mn[b[r]][b[r + 1]].size()) p = res;
				else p += mn[b[r]][b[r + 1]][t].fi;
			}

			res = min(res, p);
		} else for (int j = 0; j < n; j++) {
			ex[j]++;
			b[1] = j;

			if (K == 4) {
				b[2] = b[0];
				ll p = 0;

				for (int r = 0; r < K / 2; r++) {
					int t = 0;
					while (t < mn[b[r]][b[r + 1]].size() && ex[ mn[b[r]][b[r + 1]][t].se ]) t++;
					if (t == mn[b[r]][b[r + 1]].size()) p = res;
					else p += mn[b[r]][b[r + 1]][t].fi;
				}

				res = min(res, p);
			} else for (int k = 0; k < n; k++) {
				ex[k]++;
				b[2] = k;

				if (K == 6) {
					b[3] = b[0];
					ll p = 0;

					for (int r = 0; r < K / 2; r++) {
						int t = 0;
						while (t < mn[b[r]][b[r + 1]].size() && ex[ mn[b[r]][b[r + 1]][t].se ]) t++;
						if (t == mn[b[r]][b[r + 1]].size()) p = res;
						else p += mn[b[r]][b[r + 1]][t].fi;
					}

					res = min(res, p);
				} else for (int l = 0; l < n; l++) {
					ex[l]++;
					b[3] = l;

					if (K == 8) {
						b[4] = b[0];
						ll p = 0;

						for (int r = 0; r < K / 2; r++) {
							int t = 0;
							while (t < mn[b[r]][b[r + 1]].size() && ex[ mn[b[r]][b[r + 1]][t].se ]) t++;
							if (t == mn[b[r]][b[r + 1]].size()) p = res;
							else p += mn[b[r]][b[r + 1]][t].fi;
						}

						res = min(res, p);
					} else for (int m = 0; m < n; m++) {
						ex[m]++;
						b[4] = m;

						b[5] = b[0];
						ll p = 0;

						for (int r = 0; r < K / 2; r++) {
							int t = 0;
							while (t < mn[b[r]][b[r + 1]].size() && ex[ mn[b[r]][b[r + 1]][t].se ]) t++;
							if (t == mn[b[r]][b[r + 1]].size()) p = res;
							else p += mn[b[r]][b[r + 1]][t].fi;
						}

						res = min(res, p);

						ex[m]--;
					}

					ex[l]--;
				}

				ex[k]--;
			}

			ex[j]--;
		}

		ex[i]--;
	}

	cout << res << endl;

	return 0;
}