#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5, md = 1e9 + 7;

int a[N];
ll need;
int T, n, p, las, pos, ans;

ll getpow(int x, int y) {
	ll ans = 1;
	while (y) {
		if (y & 1) ans = min((ll)N, ans * x);
		y >>= 1; x = min((ll)N, 1ll * x * x);
	}
	return ans;
}

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1ll * ans * x % md;
		y >>= 1; x = 1ll * x * x % md;
	}
	return ans;
}

int main() {
	read(T);
	while (T--) {
		read(n); read(p);
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + n + 1);
		need = ans = 0;
		for (int i = n; i >= 1; i--) {
			if (need) {
				need = min((ll)N, need * getpow(p, pos - a[i]));
				pos = a[i];
			}
			if (need == 0) {
				need = 1;
				pos = a[i];
				ans += fpow(p, a[i]);
				if (ans >= md) ans -= md;
				continue;
			}
			--need; ans -= fpow(p, a[i]);
			if (ans < 0) ans += md;
		}
		print(ans, '\n');
	}
    return 0;
}