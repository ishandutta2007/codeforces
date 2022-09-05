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

const int N = 2e5 + 5;

int trie[N * 35][2], dp[N * 35];
int n, tot;

void dfs1(int u) {
    dp[u] = 1;
    for (int i = 0; i <= 1; i++) {
        if (trie[u][i]) {
            dfs1(trie[u][i]);
            dp[u] = max(dp[u], dp[trie[u][i]] + (trie[u][i ^ 1] > 1));
        }
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        int a, now = 0; read(a);
        for (int j = 30; j >= 0; j--) {
            int x = (a >> j) & 1;
            if (!trie[now][x]) trie[now][x] = ++tot;
            now = trie[now][x];
        }
    }
    dfs1(0);
    print(n - dp[0], '\n');
    return 0;
}