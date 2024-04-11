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
#define MAXL 20

int t;
int n, k;

struct base {
	int v[MAXL];
	void clear() {
		memset(v, 0, sizeof v);
	}
	base() {
		clear();
	}
	base(int num) {
		REP (i, 0, MAXL) {
			v[i] = num % k;
			num /= k;
		}
	}
	base plus(base b) {
		base res;
		REP (i, 0, MAXL) {
			res.v[i] = (v[i] + b.v[i]) % k;
		}
		return res;
	}
	base minus(base b) {
		base tmp;
		REP (i, 0, MAXL) {
			tmp.v[i] = (k - b.v[i]) % k;
		}
		return plus(tmp);
	}
	base minus(int i) {
		return minus(base(i));
	}
	base plus(int i) {
		return plus(base(i));
	}
	int toi() {
		int res = 0;
		int pw = 1;
		REP (i, 0, MAXL) {
			res += pw * v[i];
			pw *= k;
		}
		return res;
	}
};

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		base px;
		REP (i, 0, n) {
			base qi;
			if (i % 2 == 1) {
				qi = px.minus(i);
			} else {
				qi = px.plus(i);
			}
			printf("%d\n", qi.toi());
			fflush(stdout);
			int r; scanf("%d", &r);
			if (r == 1) {
				break;
			}
			px = qi.minus(px);
		}
	}
	return 0;
}