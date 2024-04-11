#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int a[maxn], b[maxn], vis[maxn];
int n, m;
bool flag, color[maxn];

inline bool check(int i, int j) {
    return a[i] != a[j] && b[i] != b[j] &&
           (a[i] < a[j] && b[i] > a[j] && b[i] < b[j] || a[i] > a[j] && b[j] > a[i] && b[i] > b[j]);
}

void dfs(int p, bool col) {
    if (vis[p] && color[p] != col)
        flag = false;
    else if (!vis[p]) {
        vis[p] = true;
        color[p] = col;
        for (int i = 1; i <= m; i++)
            if (check(p, i)) dfs(i, !col);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", a + i, b + i);
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    flag = true;
    for (int i = 1; i <= m; i++)
        if (!vis[i]) dfs(i, false);
    if (flag)
        for (int i = 1; i <= m; i++)
            putchar(color[i] ? 'o' : 'i');
    else
        puts("Impossible");
    return 0;
}