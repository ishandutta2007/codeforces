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
#define MAXN 2005

int n;
int d[MAXN];
int cnt[5];
vii edges;

int main() {
	scanf("%d", &n);
	int remq = (n - 1) / 2 + 1;
	printf("? 1\n");
	fflush(stdout);
	REP (i, 1, n + 1) {
		scanf("%d", &d[i]);
		cnt[d[i] % 2]++;
	}
	remq--;
	cnt[0]--;
	if (cnt[0] <= remq) {
		REP (i, 1, n + 1) {
			if (d[i] == 1) {
			   	edges.pb(1, i);
			}
		}
		REP (i, 2, n + 1) {
			if (d[i] % 2 == 0) {
				remq--;
				printf("? %d\n", i);
				fflush(stdout);
				REP (j, 1, n + 1) {
					int k; scanf("%d", &k);
					if (k == 1) {
						edges.pb(i, j);
					}
				}
			}
		}
	} else {
		REP (i, 2, n + 1) {
			if (d[i] % 2 == 1) {
				remq--;
				printf("? %d\n", i);
				fflush(stdout);
				REP (j, 1, n + 1) {
					int k; scanf("%d", &k);
					if (k == 1) {
						edges.pb(i, j);
					}
				}
			}
		}
	}
	assert(remq >= 0);
	printf("!\n");
	for (auto [u, v] : edges) {
		printf("%d %d\n", u, v);
	}
	fflush(stdout);
	return 0;
}