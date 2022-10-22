#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 300005

int n, m;
vi adj[MAXN];
vector<vi> cats;
int ans[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, m) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	REP (i, 1, n + 1) {
		sort(ALL(adj[i]));
	}
	REP (i, 1, n + 1) {
		if (adj[i].size() == 0) {
			printf("-1\n");
			return 0;
		}
		bool found = 0;
		REP (j, 0, cats.size()) {
			if (cats[j].size() != adj[i].size()) continue;
			bool pos = 1;
			REP (k, 0, adj[i].size()) {
				if (adj[i][k] != cats[j][k]) {
					pos = 0;
					break;
				}
			}
			if (pos) {
				ans[i] = j;
				found = 1;
				break;
			}
		}
		if (!found) {
			ans[i] = cats.size();
			cats.pb(adj[i]);
		}
	}
	if (cats.size() != 3) {
		printf("-1\n");
	} else {
		REP (i, 1, n + 1) {
			printf("%d ", ans[i] + 1);
		}
		printf("\n");
	}
	return 0;
}