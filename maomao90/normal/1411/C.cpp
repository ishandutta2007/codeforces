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
#define MAXN 100005

int t;
int n, m;
int x[MAXN], y[MAXN];
int p[MAXN];
bool visited[MAXN];
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n + 5) {
		   	p[i] = -1;
		}
		REP (i, 0, m) {
			visited[i] = 0;
			scanf("%d%d", &x[i], &y[i]);
			p[y[i]] = i;
		}
		ans = 0;
		REP (i, 0, m) {
			if (x[i] == y[i]) continue;
			ans++;
			if (!visited[i]) {
				int cur = i;
				visited[cur] = 1;
				while (p[x[cur]] != -1 && p[x[cur]] != i) {
					cur = p[x[cur]];
					visited[cur] = 1;
				}
				if (p[x[cur]] != -1) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}