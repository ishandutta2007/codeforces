#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 605

int n, m;
ll grid[MAXN][MAXN];
bool visited[MAXN];
ll d[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		REP (j, 0, n) {
			grid[i][j] = LINF;
		}
	}
	REP (i, 0, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		mnto(grid[a][b], (ll) c);
	}
	REP (i, 0, n) {
		memset(visited, 0, sizeof visited);
		REP (j, 0, n) d[j] = grid[i][j];
		while (1) {
			int u = -1;
			REP (j, 0, n) {
				if (visited[j]) continue;
				if (u == -1 || d[j] < d[u]) {
					u = j;
				}
			}
			if (u == -1) break;
			visited[u] = 1;
			REP (j, 0, n) {
				mnto(d[(u + j) % n], d[u] + j);
			}
			REP (j, 0, n) {
				mnto(d[(d[u] + j) % n], d[u] + grid[u][j]);
			}
		}
		REP (j, 0, n) {
			if (i == j) printf("0 ");
			else printf("%lld ", d[j]);
		}
		printf("\n");
	}
	return 0;
}