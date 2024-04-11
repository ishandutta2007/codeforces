#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5, p = 998244353;

int n, fac[N], inv[N];
ll ans = 0;

inline int mul(int x, int y) { return (ll)x * y % p; }

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int main() {
    cin >> n; fac[0] = inv[0] = 1;
    for(register int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % p;
    inv[n] = fpow(fac[n], p - 2);
    
    for(register int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % p;
    
    for(register int i = 1; i <= n; i++) ans = ((ll)ans + (ll)fac[n] * inv[i] % p * (fac[i] + p - 1) % p) % p;
    cout << (ans + 1) % p << endl;
    return 0;
}