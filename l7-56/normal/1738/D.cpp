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
int n, a[maxn], b[maxn];
vi e[maxn];
void work() {
    read(n);
    for (int i = 1; i <= n; ++i) read(b[i]);
    int k = 0;
    while (k < n && b[k + 1] > k + 1) ++k;
    for (int i = 1; i <= n; ++i) e[b[i]].push_back(i);
    int u = e[0].size() ? 0 : n + 1, m = 1;
    while (m <= n) {
        for (int x : e[u]) if (!e[x].size()) a[m++] = x;
        for (int x : e[u]) if (e[x].size()) { u = x, a[m++] = x; break; }
    }
    write(k, '\n');
    for (int i = 1; i <= n; ++i) write(a[i], " \n"[i == n]);
    for (int i = 0; i <= n + 1; ++i) e[i].resize(0);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}