#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)
#define RREP(i, j, k) for (int i = j; i >= k; i--)

typedef long long ll;

#define MOD 998244353
#define MAXN 500005

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

class modi {
	public:
	int v;
	modi() {v = 0;}
	modi(ll v): v(norm(v)) {}
	explicit operator int () const {
		return v;
	}
	int norm(ll v) const {
		return (v % MOD + MOD) % MOD;
	}
	modi operator+ (const modi& o) const {
		return norm(v + o.v);
	}
	modi operator- () const {
		return modi(-v);
	}
	modi operator- (const modi &o) const {
		return *this + -o;
	}
	modi operator* (const modi& o) const {
		return norm((ll) v * o.v);
	}
	modi operator^ (ll p) const {
		modi res = 1, b = *this;
		while (p) {
			if (p & 1) {
				res = res * b;
			}
			b = b * b;
			p >>= 1;
		}
		return res;
	}
	modi operator~ () const {
		return *this ^ (MOD - 2);
	}
	modi operator/ (const modi& o) const {
		return *this * ~o;
	}
};

int n, k;
modi fact[MAXN], ifact[MAXN];
modi ans;

modi choose(int n, int r) {
	if (r > n) return modi(0);
	return fact[n] * ifact[n - r] * ifact[r];
}

int main() {
	scanf("%d%d", &n, &k);
	fact[0] = 1;
	REP (i, 1, n + 1) {
		fact[i] = fact[i - 1] * modi(i);
	}
	ifact[n] = ~fact[n];
	RREP (i, n - 1, 0) {
		ifact[i] = ifact[i + 1] * modi(i + 1);
	}
	REP (i, 1, n + 1) {
		int cnt = n / i - 1;
		debug(" %d\n", cnt);
		ans = ans + choose(cnt, k - 1);
	}
	printf("%d\n", (int) ans);
	return 0;
}