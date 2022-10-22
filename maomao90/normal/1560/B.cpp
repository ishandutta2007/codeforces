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
int a, b, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a > b) swap(a, b);
		int gp = b - a;
		int n = gp * 2;
		debug(" %d\n", n);
		if (b > n) {
			printf("-1\n");
			continue;
		}
		int d = c - gp;
		if (d <= 0) {
			d = c + gp;
		}
		bool swp = 0;
		if (c > d) {
			swp = 1;
			swap(c, d);
		}
		if (d > n || d == b) {
			printf("-1\n");
			continue;
		}
		if (swp) {
			swap(c, d);
		}
		printf("%d\n", d);
	}
	return 0;
}