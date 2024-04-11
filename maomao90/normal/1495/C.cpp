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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 505

int t;
int n, m;
char s[MAXN][MAXN];
char ans[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n) {
			scanf(" %s", s[i]);
			REP (j, 0, m) {
				ans[i][j] = s[i][j];
			}
			ans[i][m] = 0;
		}
		if (m == 1) {
			REP (i, 0, n) {
				ans[i][0] = 'X';
			}
			REP (i, 0, n) {
				printf("%s\n", ans[i]);
			}
			continue;
		}
		for (int i = (n % 3 == 1 ? 0 : 1); i < n; i += 3) {
			REP (j, 0, m) {
				ans[i][j] = 'X';
			}
		}
		for (int i = (n % 3 == 1 ? 0 : 1); i < n; i += 3) {
			if (i + 2 >= n) break;
			if (ans[i + 1][1] == 'X' || ans[i + 2][1] == 'X') {
				ans[i + 1][1] = ans[i + 2][1] = 'X';
			} else {
				ans[i + 1][0] = ans[i + 2][0] = 'X';
			}
		}
		REP (i, 0, n) {
			printf("%s\n", ans[i]);
		}
	}
	return 0;
}