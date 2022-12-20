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

const int maxn = 1e5 + 10;
int n, a[maxn], x[maxn];
void work() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    vector <pii> vec;
    for (int i = 1; i < n; ++i)
        if (a[i] > a[i + 1]) vec.push_back({a[i] - a[i + 1], i + 1});
    sort(begin(vec), end(vec), greater <pii> ());
    int nw = n;
    for (pii p : vec) x[nw--] = p.sec;
    while (nw) x[nw--] = 1;
    for (int i = 1; i <= n; ++i) printf("%d%c", x[i], " \n"[i == n]);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}