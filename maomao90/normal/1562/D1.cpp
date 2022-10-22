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
#define MAXN 300005

int t;
int n, q;
char s[MAXN];
int a[MAXN];
int suf[2][MAXN];
ii lr[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		scanf(" %s", s);
		REP (i, 0, n) {
			a[i] = (s[i] == '+') ? 1 : -1;
		}
		REP (i, 0, 2) {
			REP (j, 0, n + 3) {
				suf[i][j] = 0;
			}
		}
		REP (i, 0, 2) {
			//debug("%d:\n", i);
			RREP (j, n - 1, 0) {
				suf[i][j] += suf[i][j + 1];
				if ((i + j) % 2 == 0) {
					suf[i][j] += a[j];
				} else {
					suf[i][j] -= a[j];
				}
				//debug(" %d: %d\n", j, suf[i][j]);
			}
		}
		REP (i, 0, q) {
			scanf("%d%d", &lr[i].FI, &lr[i].SE);
			lr[i].FI--;
			lr[i].SE--;
		}
		REP (i, 0, q) {
			auto [l, r] = lr[i];
			if ((r - l + 1) % 2 == 1) {
				printf("1\n");
			} else if (suf[l & 1][l] - suf[l & 1][r + 1] == 0) {
				printf("0\n");
			} else {
				printf("2\n");
			}
		}
	}
	return 0;
}


/*
1
14 1
+--++---++-++-
1 14
*/