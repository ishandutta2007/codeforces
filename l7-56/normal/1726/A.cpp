#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 2010;
int n, a[maxn];
void work() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    if (n <= 2) return write(abs(a[n] - a[1]), '\n');
    int mn = 1000, mx = 0;
    for (int i = 2; i < n; ++i) mn = min(mn, a[i]), mx = max(mx, a[i]);
    int ans = max(a[n] - min(mn, a[1]), max(mx, a[n]) - a[1]);
    for (int i = 1; i < n; ++i) ans = max(ans, a[i] - a[i + 1]);
    write(ans, '\n');
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}