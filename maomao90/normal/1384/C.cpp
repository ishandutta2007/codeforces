#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
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
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 100005

int t;
int n;
char a[MAXN], b[MAXN];
set<int> adj[25];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", a);
		scanf(" %s", b);
		REP (i, 0, 25) {
			adj[i].clear();
		}
		int ans = 0;
		REP (i, 0, n) {
			if (a[i] > b[i]) {
				ans = -1;
				break;
			}
			if (a[i] != b[i]) adj[a[i] - 'a'].insert(b[i] - 'a');
		}
		if (ans == -1) {
			printf("-1\n");
			continue;
		}
		REP (i, 0, 25) {
			if (adj[i].size() == 0) continue;
			ans++;
			int nxt = *adj[i].begin();
			for (auto &j : adj[i]) {
				if (j == nxt) continue;
				adj[nxt].insert(j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}