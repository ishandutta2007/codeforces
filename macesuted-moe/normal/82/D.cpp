#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int f[maxn][maxn], a[maxn];
int n;

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];
    if (y == n + 1) return f[x][y] = a[x];
    if (y == n) return f[x][y] = max(a[x], a[y]);
    return f[x][y] = min(
               max(a[x], a[y]) + dfs(y + 1, y + 2),
               min(max(a[x], a[y + 1]) + dfs(y, y + 2),
                   max(a[y], a[y + 1]) + dfs(x, y + 2)));
}

void write(int x, int y) {
    if (y == n + 1) return void(printf("%d\n", x));
    if (y == n) return void(printf("%d %d\n", x, y));
    if (f[x][y] == max(a[x], a[y]) + f[y + 1][y + 2])
        printf("%d %d\n", x, y), write(y + 1, y + 2);
    else if (f[x][y] == max(a[x], a[y + 1]) + f[y][y + 2])
        printf("%d %d\n", x, y + 1), write(y, y + 2);
    else
        printf("%d %d\n", y, y + 1), write(x, y + 2);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    printf("%d\n", dfs(1, 2));
    write(1, 2);
    return 0;
}