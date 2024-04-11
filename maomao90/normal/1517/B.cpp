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
#define MAXN 105

int t;
int n, m;
int b[MAXN][MAXN], ptr[MAXN];
bool visited[MAXN][MAXN];
priority_queue<iii, vector<iii>, greater<iii> > pq;
vi ans[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		while (!pq.empty()) pq.pop();
		REP (i, 0, n) {
			ans[i].clear();
			REP (j, 0, m) {
				visited[i][j] = 0;
				ptr[i] = m - 1;
				scanf("%d", &b[i][j]);
			}
			sort(b[i], b[i] + m);
			REP (j, 0, m) {
				pq.push(MT(b[i][j], i, j));
			}
		}
		while (!pq.empty()) {
			int v, i, j; tie(v, i, j) = pq.top(); pq.pop();
			if (visited[i][j]) continue;
			ans[i].pb(b[i][j]);
			REP (k, 0, n) {
				if (k == i) continue;
				while (ptr[k] >= 0 && visited[k][ptr[k]]) ptr[k]--;
				visited[k][ptr[k]] = 1;
				ans[k].pb(b[k][ptr[k]]);
			}
		}
		REP (i, 0, n) {
			for (int j : ans[i]) {
				printf("%d ", j);
			}
			printf("\n");
		}
	}
	return 0;
}