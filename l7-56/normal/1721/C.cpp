#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn], c[maxn], dx[maxn], dn[maxn];
void work() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    for (int i = 1; i <= n; ++i) read(b[i]), c[i] = upper_bound(a + 1, a + n + 1, b[i]) - a - 1 - i;
    for (int i = n, j = n, lim = n; i >= 1; --i) {
        while (j >= 1 && b[j] >= a[i]) {
            if (c[j] == 0) lim = j;
            --j;
        }
        dx[i] = b[lim] - a[i];
        dn[i] = (*lower_bound(b + 1, b + n + 1, a[i])) - a[i];
    }
    for (int i = 1; i <= n; ++i) write(dn[i], " \n"[i == n]);
    for (int i = 1; i <= n; ++i) write(dx[i], " \n"[i == n]);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}