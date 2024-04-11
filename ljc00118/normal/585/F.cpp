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

const int N = 25005, md = 1e9 + 7;

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

queue <int> q;
int ch[N][10], fail[N], cat[N], dp[55][N][2];
char s[N], a[N], b[N];
int n, tot, d;

int calc(char *c) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j <= tot; j++) {
            for (int k = 0; k <= 1; k++) {
                if (!dp[i - 1][j][k]) continue;
                int up = (k == 1 ? c[i] - '0' : 9);
                for (int t = 0; t <= up; t++) {
                    addx(dp[i][ch[j][t]][k & (t == up)], dp[i - 1][j][k]);
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= tot; i++) {
        if (!cat[i]) continue;
        for (int j = 0; j <= 1; j++) addx(sum, dp[d][i][j]);
    }
    return sum;
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    scanf("%s%s", a + 1, b + 1); d = strlen(a + 1);
    for (int i = 1; i <= n - d / 2 + 1; i++) {
        int now = 0;
        for (int j = i; j < i + d / 2; j++) {
            int x = s[j] - '0';
            if (!ch[now][x]) ch[now][x] = ++tot;
            now = ch[now][x];
        }
        cat[now] = 1;
    }
    for (int i = 0; i <= 9; i++) if (ch[0][i]) q.push(ch[0][i]);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i <= 9; i++) {
            int v = ch[u][i];
            if (!v) {
                if (cat[u]) ch[u][i] = u;
                else ch[u][i] = ch[fail[u]][i];
                continue;
            }
            fail[v] = ch[fail[u]][i];
            q.push(v);
        }
    }
    --a[d];
    int pos = d;
    while (a[pos] == '0' - 1) a[pos] = '9', --a[pos - 1], --pos;
    print(sub(calc(b), calc(a)), '\n');
    return 0;
}