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

const int maxn = 110, N = 100;
int n, a[maxn], f[maxn][maxn][2];
void work() {
    read(n);
    int c[2] = {0, 0};
    for (int i = 1; i <= n; ++i) read(a[i]), c[a[i] & 1]++;
    int ans = f[c[0]][c[1]][0];
    write(ans ? "Alice\n" : "Bob\n");
}

int main() {
    for (int i = 1; i <= N; ++i) f[0][i][((i + 1) / 2) & 1] = 1, f[i][0][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            int s = j & 1;
            f[i][j][0] = (!f[i - 1][j][s ^ 1] || !f[i][j - 1][s ^ 1]);
            f[i][j][1] = (!f[i - 1][j][s] || !f[i][j - 1][s]);
        }
    int T; read(T);
    while (T--) work();
	return 0;
}