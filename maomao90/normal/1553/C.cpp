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
#define MAXN 15

int t;
int n = 10;
char s[MAXN];

int sign(int x) {
	if (x == 0) return 0;
	if (x > 0) return 1;
	return -1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", s);
		int ans = n - 1;
		REP (m, 0, 1 << n) {
			char t[MAXN];
			strcpy(t, s);
			REP (i, 0, n) {
				if (t[i] != '?') continue;
				if (m & (1 << i)) {
					t[i] = '1';
				} else {
					t[i] = '0';
				}
			}
			int d = 0;
			REP (i, 0, n) {
				int p = t[i] - '0';
				if (i % 2 == 0) {
					d += p;
				} else {
					d -= p;
				}
				if (d > 0) {
					int td = d;
					td -= (n - i) / 2;
					if (sign(d) == sign(td)) {
						mnto(ans, i);
					}
				} else if (d < 0) {
					int td = d;
					td += (n - i - 1) / 2;
					if (sign(d) == sign(td)) {
						mnto(ans, i);
					}
				}
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}