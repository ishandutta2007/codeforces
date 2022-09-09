#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const ll P = 1e9 + 9;
const int N = 1e5 + 5;

ll power(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % P;
		y >>= 1; x = x * x % P;
	}
//	fprintf(stderr, "ans = %I64d\n", ans);
	return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {x = 1; y = 0; return a;}
	ll d = exgcd(b, a % b, x, y);
	ll t = x; x = y; y = t - a / b * y;
	return d;
}

ll inv(ll a) {
	ll x, y;
	exgcd(a, P, x, y);
	return (x % P + P) % P;
}

char c[N];
ll n, a, b, k, x, y;

int main() {
	cin >> n >> a >> b >> k; swap(a, b);
	y = a * inv(b) % P;
	scanf("%s", c + 1);
	ll now = power(b, n);
	x = now * (c[1] == '+' ? 1ll : -1ll);
	for(int i = 2; i <= k; i++) {
		now = now * y % P;
		ll fu = (c[i] == '+' ? 1ll : -1ll);
		x = ((x + now * fu) % P + P) % P;
	}
	y = power(y, k); //fprintf(stderr, "x = %I64d, y = %I64d\n", x, y);
	if(power(a, k) == power(b, k)) {
		cout << ((x * (n + 1ll) / k) % P + P) % P << endl;
		return 0;
	}
//	fprintf(stderr, "times = %I64d\n", (power(y, n / k + 1ll) - 1ll) * inv(y - 1ll) % P);
	cout << ((x * (power(y, n / k + 1ll) - 1ll) % P * inv(y - 1ll) % P + P) % P) << endl;
	return 0;
}