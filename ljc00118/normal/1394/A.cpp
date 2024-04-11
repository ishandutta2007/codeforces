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

const int N = 1e5 + 5;

ll a[N], b[N];
int n, d, m, al, bl;
ll ans;

int main() {
	read(n); read(d); read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		if (x > m) a[++al] = x;
		else b[++bl] = x;
	}
	sort(a + 1, a + al + 1); reverse(a + 1, a + al + 1);
	sort(b + 1, b + bl + 1); reverse(b + 1, b + bl + 1);
	for (int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];
	for (int i = 0; i <= al; i++) {
		ll cnt = n - 1ll * d * max(0, i - 1) - i;
		if (cnt >= 0) ans = max(ans, a[i] + b[cnt]);
	}
	print(ans, '\n');
    return 0;
}