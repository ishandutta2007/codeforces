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

const int maxn = 2010;
int n, fa[maxn], a[maxn][maxn];
int opp(int x) { return x > n ? x - n : x + n; }
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == opp(y)) return;
    fa[x] = y;
}

void work() {
    read(n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            read(a[i][j]);
    iota(fa + 1, fa + n * 2 + 1, 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] < a[j][i]) merge(i, j), merge(opp(i), opp(j));
            if (a[i][j] > a[j][i]) merge(i, opp(j)), merge(opp(i), j);
        }
    for (int i = 1; i <= n; ++i)
        if (get(i) <= n) {
            for (int j = 1; j <= n; ++j)
                swap(a[i][j], a[j][i]);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            printf("%d%c", a[i][j], " \n"[j == n]);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}