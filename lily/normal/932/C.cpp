/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

const int MAXN = 1000005;

LL Abs(LL x) {
	return x > 0 ? x : -x;
}

void exgcd(LL a, LL b, LL & x, LL & y) {
	if(!b) {
		x = 1; y = 0;
	} else {
		exgcd(b, a % b, x, y);
		LL t = x; x = y; y = t - a / b * y;
	}
}

LL gcd(LL a, LL b) {
	LL x, y;
	exgcd(a = Abs(a), b = Abs(b), x, y);
	return a * x + b * y;
}

LL n, a, b;
int p[MAXN];

int main() {
	LL x, y;
	cin >> n >> a >> b;
	exgcd(a, b, x, y);
	LL g = gcd(a, b);
	// ax + by = g
	if(n % g) puts("-1");
	else {
		x *= n / g;
		y *= n / g;
		if(x < 0) {
			LL t = -x / (b / g);
			if(x + t * (b / g) < 0) t++;
			x += t * (b / g);
			y -= t * (a / g);
		}
		if(y < 0) {
			LL t = -y / (a / g);
			if(y + t * (a / g) < 0) t++;
			y += t * (a / g);
			x -= t * (b / g);
		}
		if(x < 0 || y < 0) {
			puts("-1");
		} else {
			for(int i = 1; i <= x; i++) {
				for(int j = (i - 1) * a + 1; j <= (i - 1) * a + a; j++) {
					p[j] = j + 1;
					if(j == i * a) p[j] = (i - 1) * a + 1;
				}
			}
			for(int i = 1; i <= y; i++) {
				for(int j = (i - 1) * b + 1; j <= (i - 1) * b + b; j++) {
					p[j + x * a] = j + 1 + x * a;
					if(j == i * b) p[j + x * a] = (i - 1) * b + 1 + x * a;
				}
			}
			for(int i = 1; i <= n; i++) {
				printf("%d ", p[i]);
			}
		}
	}
	return 0;
}