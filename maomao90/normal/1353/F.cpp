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
typedef tuple<ll, ll, ll> lll;
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
#define MAXN 105

const int dirr[] = {1, 0}, dirc[] = {0, 1};

int t;
int n, m;
ll a[MAXN][MAXN];
ll d[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		vll cand;
		REP (i, 1, n + 1) {
			REP (j, 1, m + 1) {
				scanf("%lld", &a[i][j]);
				int time = i + j - 2;
				cand.pb(a[i][j] - time);
			}
		}
		ll ans = LINF;
		for (ll c : cand) {
			if (a[1][1] < c) continue;
			ll tmp = a[1][1] - c;
			REP (i, 0, n + 1) {
				REP (j, 0, m + 1) {
					d[i][j] = LINF;
				}
			}
			d[1][1] = tmp;
			REP (i, 1, n + 1) {
				REP (j, 1, m + 1) {
					if (i == 1 && j == 1) {
						continue;
					}
					ll nc = c + i + j - 2;
					if (a[i][j] < nc) continue;
					ll cost = a[i][j] - nc;
					d[i][j] = min(d[i - 1][j], d[i][j - 1]) + cost;
				}
			}
			mnto(ans, d[n][m]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}