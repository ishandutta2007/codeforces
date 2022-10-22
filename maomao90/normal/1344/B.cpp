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
#define MAXN 1005

int dirr[] = {1, 0, -1, 0}, dirc[] = {0, 1, 0, -1};

int n, m;
char grid[MAXN][MAXN];
bool impos[MAXN][MAXN];
int ans;

bool visited[MAXN][MAXN];
void dfs(int r, int c) {
	REP (i, 0, 4) {
		int nr = r + dirr[i], nc = c + dirc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if (visited[nr][nc] || grid[nr][nc] == '.') continue;
		visited[nr][nc] = 1;
		dfs(nr, nc);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		REP (j, 0, m) {
			scanf(" %c", &grid[i][j]);
		}
	}
	REP (i, 0, n) {
		int start = -1, end = -1;
		REP (j, 0, m) {
			if (grid[i][j] == '#') {
				if (start == -1) {
					start = j;
				} else if (end != -1) {
					printf("-1\n");
					return 0;
				}
			} else if (end == -1 && start != -1) {
				end = j - 1;
			}
		}
		if (start != -1 && end == -1) end = m - 1;
		if (start != -1) {
			REP (j, 0, start) {
				impos[i][j] = 1;
			}
			REP (j, end + 1, m) {
				impos[i][j] = 1;
			}
		}
	}
	REP (j, 0, m) {
		int start = -1, end = -1;
		REP (i, 0, n) {
			if (grid[i][j] == '#') {
				if (start == -1) {
					start = i;
				} else if (end != -1) {
					printf("-1\n");
					return 0;
				}
			} else if (end == -1 && start != -1) {
				end = i - 1;
			}
		}
		if (start != -1 && end == -1) end = n - 1;
		if (start != -1) {
			REP (i, 0, start) {
				impos[i][j] = 1;
			}
			REP (i, end + 1, n) {
				impos[i][j] = 1;
			}
		}
	}
	REP (i, 0, n) {
		bool pos = 0;
		REP (j, 0, m) {
			if (!impos[i][j]) pos = 1;
		}
		if (!pos) {
			printf("-1\n");
			return 0;
		}
	}
	REP (j, 0, m) {
		bool pos = 0;
		REP (i, 0, n) {
			if (!impos[i][j]) pos = 1;
		}
		if (!pos) {
			printf("-1\n");
			return 0;
		}
	}
	REP (i, 0, n) {
		REP (j, 0, m) {
			if (grid[i][j] == '.' || visited[i][j]) continue;
			visited[i][j] = 1;
			dfs(i, j);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}