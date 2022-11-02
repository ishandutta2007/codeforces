#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int r[21], test, n, v[21], f[2000011], g[2000011];
char str1[100011], str2[100011];
bool b[21];

int gf(int i) {
    if (i == r[i])
        return i;
    return r[i] = gf(r[i]);
}

int main() {
    for (int i = 0; i < 1 << 20; i++)
        for (int j = 0; j < 20; j++)
            if (i & (1 << j))
                ++g[i];
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d%s%s", &n, str1 + 1, str2 + 1);
        memset(v, 0, sizeof(v));
        memset(b, false, sizeof(b));
        int cnt = 0;
        for (int i = 0; i < 20; i++)
            r[i] = i;
        for (int i = 1; i <= n; i++) {
            int x = str1[i] - 'a', y = str2[i] - 'a';
            if (x != y)
                v[x] |= 1 << y;
            if (!b[x])
                b[x] = true, ++cnt;
            if (!b[y])
                b[y] = true, ++cnt;
            r[gf(x)] = gf(y);
        }
        memset(f, 255, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << 20; i++)
            if (f[i] >= 0)
                for (int j = 0; j < 20; j++)
                    if (b[j] && !(i & (1 << j)) && !(v[j] & i))
                        f[i + (1 << j)] = max(f[i + (1 << j)], f[i] + 1);
        
        int ans = 1 << 30;
        for (int i = 0; i < 1 << 20; i++)
            if (f[i] >= 0)
                ans = min(ans, 2 * cnt - g[i] - 1);
        cnt = 0;
        for (int i = 0; i < 20; i++)
            if (b[i] && gf(i) == i)
                ++cnt;
        ans -= cnt - 1;
        printf("%d\n", ans);
    }
}