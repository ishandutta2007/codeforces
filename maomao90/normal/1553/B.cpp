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
#define MAXN 1005

int q;
char s[MAXN], t[MAXN];

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf(" %s", s);
		scanf(" %s", t);
		bool pos = 0;
		int n = strlen(s), m = strlen(t);
		REP (i, 0, n) {
			REP (j, i, n) {
				int k = m - (j - i + 1);
				if (k < 0 || j - k < 0) continue;
				int ptr = 0;
				bool cpos = 1;
				REP (l, i, j + 1) {
					if (s[l] != t[ptr++]) {
					   	cpos = 0;
						break;
					}
				}
				if (!cpos) break;
				RREP (l, j - 1, j - k) {
					if (s[l] != t[ptr++]) {
					   	cpos = 0;
						break;
					}
				}
				pos |= cpos;
				if (pos) break;
			}
			if (pos) break;
		}
		if (pos) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}