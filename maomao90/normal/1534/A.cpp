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

#ifdef DEBUG
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
		va_list args;
			va_start(args, format);
				vprintf(format, args);
					va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 55

int t;
int n, m;
char s[MAXN][MAXN], ans[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n) {
			scanf(" %s", s[i]);
			memset(ans, 0, sizeof ans);
		}
		bool pos = 1;
		REP (i, 0, n) {
			REP (j, 0, m) {
				if ((i + j) % 2) {
					ans[i][j] = 'R';
				} else {
					ans[i][j] = 'W';
				}
				if (s[i][j] != '.' && s[i][j] != ans[i][j]) {
					pos = 0;
					break;
				}
			}
		}
		if (pos) {
			printf("YES\n");
			REP (i, 0, n) {
				printf("%s\n", ans[i]);
			}
			continue;
		}
		pos = 1;
		REP (i, 0, n) {
			REP (j, 0, m) {
				if ((i + j) % 2) {
					ans[i][j] = 'W';
				} else {
					ans[i][j] = 'R';
				}
				if (s[i][j] != '.' && s[i][j] != ans[i][j]) {
					pos = 0;
					break;
				}
			}
		}
		if (pos) {
			printf("YES\n");
			REP (i, 0, n) {
				printf("%s\n", ans[i]);
			}
			continue;
		}
		printf("NO\n");
	}
	return 0;
}