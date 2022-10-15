#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second
typedef unsigned long long ULL;
const int N = 2e5 + 10;
 
namespace Pollard_Rho {
	void mul(LL &x, LL y, LL m) {
		x %= m, y %= m;
		unsigned long long t = (long long)((long double)x * y / m);
		x = (unsigned long long) x * y - t * m;
		x = (x % m + m) % m;
	}

	LL power(LL x, LL y, LL m) {
		LL ret = 1;
		for (x %= m; y; y >>= 1) {
			if (y & 1) mul(ret, x, m);
			mul(x, x, m);
		}
		return ret;
	}

	LL Rand() {
		static LL a = 2333333;
		a ^= a >> 12;
		a ^= a << 25;
		a ^= a >> 27;
		return a * 0x2545F4914F6CDD1D;
	}

	LL gcd(LL a, LL b) {
		while (b) {
			LL c = a;
			a = b; b = c % b;
		}
		return a;
	}

	const int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, -1};  
	vector<LL> D;

	bool witness(int p, LL x, int t, LL n) {
		LL y = power(p, x, n);
		if (y == 1) return 0;
		for (int i = 0; i < t; i++) {
			if (y == n - 1) return 0;
			if (y == 1) return 0;
			mul(y, y, n);
		}
		return 1;
	}

	bool MR(LL n) {
		if (n < 4) return 1;
		for (int i = 0; ~P[i]; i++) {
			if (n == P[i]) return 1;
			if (n % P[i] == 0) return 0;
		}
		LL x = n - 1; int t = 0;
		while (~x & 1) {
			++t;
			x >>= 1;
		}
		for (int i = 0; ~P[i]; i++) {
			if (witness(P[i], x, t, n)) return 0;
		}
		return 1;
	}

	void PR(LL n) {
		if (MR(n)) {
			D.push_back(n);
			return;
		}
		LL a, b, c, d;
		while (1) {
			c = Rand() % n;
			a = b = Rand() % n;
			mul(b, b, n); (b += c) %= n;
			while (a != b) {
				d = a > b ? a - b : b - a;
				d = gcd(d, n);
				if (d > 1 && d < n) {
					PR(d); PR(n / d);
					return;
				}
				mul(a, a, n); (a += c) %= n;
				mul(b, b, n); (b += c) %= n;
				mul(b, b, n); (b += c) %= n;
			}
		}
	}
	void solve(LL n) {
		D.clear();
		if (n < 2) return;
		PR(n);
		sort(D.begin(), D.end());
	}
}


int n;
LL a[N];
LL ans = 0;
vector <LL> pos;

void cnt(LL x) {
	LL ret = 0;
	for (int i = 1; i <= n; i++) {
		LL y = a[i] % x;
		ret += min(y + (y == a[i] ? x : 0), x - y);
	}
	ans = min(ans, ret);
}
void check(LL x) {
	while (x && x % 2 == 0) x /= 2;
	Pollard_Rho::solve(x);
	for (auto &v : Pollard_Rho::D) {
		cnt(v);
	}
}
mt19937 rnd(123121931);
int main() {
	time_t st = clock();
	read(n);
//	n = 2e5;
	for (int i = 1; i <= n; i++) {
//		a[i] = rnd() * 500LL + rnd();
		scanf("%lld", &a[i]);
	}
//	cerr << "start " <<endl;
	for (int i = 1; i <= n; i++) {
		ans += a[i] % 2;
	}
//	cerr << ans << endl;
	while (clock() - st < 1.9 * CLOCKS_PER_SEC) {
		int x = rnd() % n + 1;
		check(a[x] - 1);
		check(a[x]);
		check(a[x] + 1);
	}

	printf("%lld\n", ans);
}