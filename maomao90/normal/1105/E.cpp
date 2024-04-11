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
#define MAXM 45
#define MAXL 20
#define MAXN 1100000

int n, m;
char tmp[MAXM];
map<string, int> mp;
bool g[MAXM][MAXM];
int dp1[MAXN], dp2[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	int ptr = 0;
	vi v;
	REP (i, 0, n + 1) {
		int t = 1;
		if (i < n) {
			scanf("%d", &t);
		}
		if (t == 2) {
			scanf(" %s", tmp);
			string cur = tmp;
			if (mp.find(cur) == mp.end()) {
				mp[cur] = ptr++;
			}
			v.pb(mp[cur]);
		} else {
			REP (j, 0, v.size()) {
				REP (k, 0, v.size()) {
					g[v[j]][v[k]] = 1;
				}
			}
			v.clear();
		}
	}
	assert(ptr == m);
	int mid = m / 2;
	int n1 = mid; int n2 = m - mid;
	REP (msk, 0, 1 << n1) {
		REP (i, 0, n1) {
			if (msk & (1 << i)) {
				int cmsk = msk ^ (1 << i);
				bool can = 1;
				REP (j, 0, n1) {
					if (cmsk & (1 << j)) {
						if (g[i][j]) {
							can = 0;
						}
					}
				}
				mxto(dp1[msk], dp1[cmsk] + can);
			}
		}
		debug("%s: %d\n", bitset<3>(msk).to_string().c_str(), dp1[msk]);
	}
	REP (msk, 0, 1 << n2) {
		REP (i, 0, n2) {
			if (msk & (1 << i)) {
				int cmsk = msk ^ (1 << i);
				bool can = 1;
				REP (j, 0, n2) {
					if (cmsk & (1 << j)) {
						if (g[i + mid][j + mid]) {
							can = 0;
						}
					}
				}
				mxto(dp2[msk], dp2[cmsk] + can);
			}
		}
		debug("%s: %d\n", bitset<3>(msk).to_string().c_str(), dp2[msk]);
	}
	int ans = 0;
	REP (msk, 0, 1 << n1) {
		int cmsk = (1 << n2) - 1;
		REP (i, 0, n1) {
			if (msk & (1 << i)) {
				REP (j, 0, n2) {
					if (g[i][j + mid]) {
						if (cmsk & (1 << j)) {
							cmsk ^= 1 << j;
						}
					}
				}
			}
		}
		mxto(ans, dp1[msk] + dp2[cmsk]);
	}
	printf("%d\n", ans);
	return 0;
}