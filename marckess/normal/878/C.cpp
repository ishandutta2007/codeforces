#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 50005;
int n, k, s[MX][10], sz[MX];
int p[MX], mx[MX][10], mn[MX][10];
set<ii> st[10];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a);
	b = parent(b);

	if (a == b) return;

	forn (j, k) {
		mx[a][j] = max(mx[a][j], mx[b][j]);
		mn[a][j] = min(mn[a][j], mn[b][j]);
	}

	sz[a] += sz[b];
	p[b] = a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	forn (i, n) {
		forn (j, k) {
			cin >> s[i][j];
			mx[i][j] = s[i][j];
			mn[i][j] = s[i][j];
			st[j].emplace(s[i][j], i);
		}

		p[i] = i;
		sz[i] = 1;

		int f = 1;
		while (f) {
			f = 0;

			forn (j, k) {
				while (1) {
					auto it = st[j].upper_bound(ii(mx[parent(i)][j], 1e9));
					if (it == st[j].end()) break;

					int ot = parent(it->se);
					int x = 0, y = 0;

					forn (l, k) {
						x += mn[parent(i)][l] > mx[ot][l];
						y += mn[ot][l] > mx[parent(i)][l];
					}

					if (x < k && y < k) {
						join(i, ot);
						f = 1;
					} else {
						break;
					}
				}

				while (1) {
					auto it = st[j].lower_bound(ii(mn[parent(i)][j], -1));
					if (it == st[j].begin()) break;
					it--;

					int ot = parent(it->se);
					int x = 0, y = 0;

					forn (l, k) {
						x += mn[parent(i)][l] > mx[ot][l];
						y += mn[ot][l] > mx[parent(i)][l];
					}

					if (x < k && y < k) {
						join(i, ot);
						f = 1;
					} else {
						break;
					}
				}
			}
		}

		cout << sz[parent(st[0].rbegin()->se)] << endl;
	}

	return 0;
}