// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5;

char str[N];
 
int n, m, s[N];

vector<char> g[N];

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        g[i].resize(m + 2);
        for (int j = 1; j <= m; j++) {
            g[i][j] = str[j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= m; j++) {
            if (g[i][j] == 'X' && g[i + 1][j - 1] == 'X') {
                s[j] = 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) s[i] += s[i - 1];
    int q; read(q);
    while (q--) {
        int l, r; read(l), read(r);
        if (l == r) puts("YES");
        else {
            int t = s[r] - s[l];
            puts(t ? "NO" : "YES");
        }
    }
    return 0;
}