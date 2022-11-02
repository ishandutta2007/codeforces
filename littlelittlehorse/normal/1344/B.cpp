#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int D[2][2] = { {1, 0}, {0, 1}};
int n, m, f[1000001], a[1001][1001], c[1001], r[1001];
char str[1011][1011];

int gf(int i) {
    if (i == f[i])
        return i;
    return f[i] = gf(f[i]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] = ++cnt;
            if (str[i][j] == '#')
                f[cnt] = cnt;
            else
                f[cnt] = 0;
        }
        
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (str[i][j] == '#')
                ++c[i], ++r[j];
    
    for (int i = 1; i <= n; i++)
        if (!c[i]) {
            bool ok = false;
            for (int j = 1; j <= m; j++)
                if (!r[j])
                    ok = true;
            if (!ok) {
                printf("-1\n");
                return 0;
            }
        }
            
     
    for (int i = 1; i <= m; i++)
        if (!r[i]) {
            bool ok = false;
            for (int j = 1; j <= n; j++)
                if (!c[j])
                    ok = true;
            if (!ok) {
                printf("-1\n");
                return 0;
            }
        }
        
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            if (str[i][j] == '#')
            for (int k = 0; k < 2; k++) {
                int x = i + D[k][0], y = j + D[k][1];
                if (x > n || y > m || str[x][y] != '#')
                    continue;
                if (gf(a[i][j]) != gf(a[x][y]))
                    f[gf(a[i][j])] = gf(a[x][y]);
            }
    
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= m; j++)
            if (str[i][j] == '#') {
                if (c && (str[i][j - 1] != '#' || gf(a[i][j]) != c)) {
                    printf("-1\n");
                    return 0;
                }
                c = gf(a[i][j]);
            }
    }
    
    for (int j = 1; j <= m; j++) {
        int c = 0;
        for (int i = 1; i <= n; i++)
            if (str[i][j] == '#') {
                if (c && (str[i - 1][j] != '#' || gf(a[i][j]) != c)) {
                    printf("-1\n");
                    return 0;
                }
                c = gf(a[i][j]);
            }
    }
    
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        if (f[i] == i)
            ++ans;
    printf("%d\n", ans);
}