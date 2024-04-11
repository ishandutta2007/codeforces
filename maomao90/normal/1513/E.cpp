#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)
#define RREP(i, j, k) for (int i = j; i >= k; i--)

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1 : 0;}

typedef long long ll;

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

#define MOD 1000000007
#define MAXN 100005

class modi {
	public:
		int x;
		modi(): x(0) {}
		modi(ll x): x(norm(x)) {}
		int norm(ll x) {
			return (x % MOD + MOD) % MOD;
		}
		explicit operator int () const {
			return x;
		}
		modi operator+ (const modi& o) const {
			return modi(x + o.x);
		}
		modi operator- () const {
			return modi(-x);
		}
		modi operator- (const modi& o) const {
			return *this + -o;
		}
		modi operator* (const modi& o) const {
			return modi((ll) x * o.x);
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

int n;
int a[MAXN];
modi fact[MAXN], ifact[MAXN];
map<int, int> cnt;
ll sum;
modi ans;

modi choose(int n, int r) {
	if (r < 0 || r > n) return 0;
	return fact[n] * ifact[n - r] * ifact[r];
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	fact[0] = 1;
	REP (i, 1, n + 1) {
		fact[i] = fact[i - 1] * modi(i);
	}
	ifact[n] = ~fact[n];
	RREP (i, n - 1, 0) {
		ifact[i] = ifact[i + 1] * modi(i + 1);
	}
	if (sum % n != 0) {
		printf("0\n");
		return 0;
	}
	ll avg = sum / n;
	int small = 0, big = 0, same = 0;
	REP (i, 0, n) {
		cnt[a[i]]++;
		if (a[i] < avg) {
			small++;
		} else if (a[i] > avg) {
			big++;
		} else {
			same++;
		}
	}
	debug("%d %d %d\n", small, big, same);
	if (small <= 1 || big <= 1) {
		ans = fact[n];
		for (auto [i, j] : cnt) {
			ans = ans / fact[j];
		}
		printf("%d\n", (int) ans);
		return 0;
	}
	ans = fact[small] * fact[big] * choose(n, same) * modi(2);
	for (auto [i, j] : cnt) {
		if (i == avg) continue;
		ans = ans / fact[j];
	}
	printf("%d\n", (int) ans);
	return 0;
}