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

const int maxn = 1010, maxm = maxn * maxn;
int n, m, a[maxn][maxn], e[maxn][maxn];
char s[maxm];
void work() {
    read(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            read(a[i][j]);
    scanf("%s", s + 1);
    int p[3] = {0, 1, 2}, c[3] = {0, 0, 0};
    for (int i = 1; i <= m; ++i) {
        if (s[i] == 'R') c[2]++;
        if (s[i] == 'L') c[2]--;
        if (s[i] == 'D') c[1]++;
        if (s[i] == 'U') c[1]--;
        if (s[i] == 'I') swap(p[0], p[2]), swap(c[0], c[2]);
        if (s[i] == 'C') swap(p[0], p[1]), swap(c[0], c[1]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int b[3] = {a[i][j], i, j};
            int d[3];
            for (int i = 0; i < 3; ++i) d[i] = ((b[p[i]] + c[i] - 1) % n + n) % n + 1;
            e[d[1]][d[2]] = d[0];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            write(e[i][j], " \n"[j == n]);
    write('\n');
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}