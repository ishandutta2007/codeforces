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
#define MAXN 200005

int t;
int n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		//*
		if (n <= 26) {
			REP (i, 0, n) {
				printf("%c", i + 'a');
			}
			printf("\n");
			continue;
		}
		//*/
		int f = (n - 1) / 2;
		REP (i, 0, f) {
			printf("a");
		}
		printf("b");
		REP (i, 1, f) {
			printf("a");
		}
		printf("c");
		if (n % 2 == 0) {
			printf("d");
		}
		printf("\n");
	}
	return 0;
}