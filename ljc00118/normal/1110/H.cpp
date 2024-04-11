#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2005;

queue <int> q;
int ch[N * 10][10], tem[N * 10][10], dp[N][N], val[N * 10][N], nxt[N][N], fail[N * 10], opl[N * 10], opr[N * 10], good[N * 10], len[N * 10], qwq[N * 10];
char a[N], b[N];
int n, m, tot, lena, lenb;

void dfs1(int u, int x) {
    opl[u] = x;
    for (int i = 0; i < 10; i++) {
        if (ch[u][i]) {
            dfs1(ch[u][i], x);
        }
    }
}

void dfs2(int u, int x) {
    opr[u] = x;
    for (int i = 0; i < 10; i++) {
        if (ch[u][i]) {
            dfs2(ch[u][i], x);
        }
    }
}

void dfs3(int u) {
    for (int i = 0; i < 10; i++) {
        if (ch[u][i]) {
            len[ch[u][i]] = len[u] + 1;
            dfs3(ch[u][i]);
        }
    }
}

int main() {
    scanf("%s%s", a + 1, b + 1); read(n);
    lena = strlen(a + 1); lenb = strlen(b + 1);
    int now = 0;
    for (int i = 1; i <= lena; i++) {
        int x = a[i] - '0';
        if (!ch[now][x]) ch[now][x] = ++tot;
        now = ch[now][x]; good[now] = 1;
    }
    now = 0;
    for (int i = 1; i <= lenb; i++) {
        int x = b[i] - '0';
        if (!ch[now][x]) ch[now][x] = ++tot;
        now = ch[now][x]; good[now] = 1;
    }
    m = tot;
    for (int i = 0; i <= tot; i++) {
        if (good[i] || i == 0) {
            for (int j = 0; j < 10; j++) {
                if (!ch[i][j]) ch[i][j] = ++tot;
            }
        }
    }
    now = 0;
    for (int i = 1; i <= lena; i++) {
        int x = a[i] - '0';
        for (int j = 0; j < x; j++) dfs1(ch[now][j], -1);
        for (int j = x + 1; j < 10; j++) dfs1(ch[now][j], 1);
        now = ch[now][x];
    }
    now = 0;
    for (int i = 1; i <= lenb; i++) {
        int x = b[i] - '0';
        for (int j = 0; j < x; j++) dfs2(ch[now][j], -1);
        for (int j = x + 1; j < 10; j++) dfs2(ch[now][j], 1);
        now = ch[now][x];
    }
    dfs3(0);
    for (int i = 1; i <= tot; i++) {
        int L = lena + 1, R = lenb - 1;
        if (opl[i] != -1) --L;
        if (opr[i] != 1) ++R;
        if (good[i]) {
            if (L <= len[i] && len[i] <= R) val[i][0] = 1;
        } else if (i != ch[0][0]) {
            for (int j = max(0, L - len[i]); j <= R - len[i]; j++) val[i][j] = 1;
        }
        for (int j = 1; j <= n; j++) val[i][j] += val[i][j - 1];
    }
    for (int i = 0; i < 10; i++) q.push(ch[0][i]), tem[0][i] = ch[0][i];
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i <= n; i++) val[u][i] += val[fail[u]][i];
        for (int i = 0; i < 10; i++) {
            if (!ch[u][i]) {
                tem[u][i] = tem[fail[u]][i];
                continue;
            }
            tem[u][i] = ch[u][i];
            fail[ch[u][i]] = tem[fail[u]][i];
            q.push(ch[u][i]);
        }
    }
    for (int i = 1; i <= tot; i++) {
        int x = i;
        while (!good[x] && x) x = fail[x];
        qwq[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 10; k++) {
                int tmp = dp[qwq[tem[j][k]]][i - 1] + val[tem[j][k]][i - 1];
                if (tmp > dp[j][i]) dp[j][i] = tmp, nxt[j][i] = k;
            }
        }
    }
    print(dp[0][n], '\n');
    now = 0;
    for (int i = 1; i <= n; i++) {
        putchar(nxt[now][n - i + 1] + '0');
        now = qwq[tem[now][nxt[now][n - i + 1]]];
    }
    putchar('\n');
    return 0;
}