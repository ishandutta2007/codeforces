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
#define MAXN 1000005
#define MULT 1000000
#define EPS 1e-9

int t;
int c, m, p, v;
ld memo[MAXN];

ld dp(int c, int m, int p, int rounds) {
	//if (memo[c][m] < 0) return memo[c][m];
	ld res = 0;
	if (c > 0) {
		int minus = min(v, c);
		int nc = c - minus;
		int nm = m, np = p;
		int cnt = 0;
		if (m != 0) cnt++;
		if (p != 0) cnt++;
		if (m != 0) {
			nm += minus / cnt;
		}
		if (p != 0) {
			np += minus / cnt;
		}
		res += c * dp(nc, nm, np, rounds + 1);
	}
	if (m > 0) {
		int minus = min(v, m);
		int nm = m - minus;
		int nc = c, np = p;
		int cnt = 0;
		if (c != 0) cnt++;
		if (p != 0) cnt++;
		if (c != 0) {
			nc += minus / cnt;
		}
		if (p != 0) {
			np += minus / cnt;
		}
		res += m * dp(nc, nm, np, rounds + 1);
	}
	if (p > 0) {
		res += p * rounds;
	}
	return memo[c] = res / MULT;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		ld tc, tm, tp, tv; scanf("%Lf%Lf%Lf%Lf", &tc, &tm, &tp, &tv);
		c = round(tc * MULT);
		m = round(tm * MULT);
		p = round(tp * MULT);
		v = round(tv * MULT);
		REP (i, 0, MAXN) {
			memo[i] = -1;
		}
		printf("%.9Lf\n", dp(c, m, p, 1));
	}
	return 0;
}