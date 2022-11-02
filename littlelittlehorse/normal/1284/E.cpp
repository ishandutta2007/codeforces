#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

int xx(int x, int y) {
    if (x >= 0 && y >= 0)
        return 1;
    if (x < 0 && y >= 0)
        return 2;
    if (x < 0 && y < 0)
        return 3;
    return 4;
}

struct node {
    long long x, y;
    bool operator < (const node &A) const {
        if (xx(x, y) != xx(A.x, A.y))
            return xx(x, y) < xx(A.x, A.y);
        return x * A.y - y * A.x > 0;
    }
} e[6001];

int n;
long long a[2501][2];
bitset<2501> b[2501], c[2501];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d%I64d", &a[i][0], &a[i][1]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int m = 0;
        for (int j = 1; j <= n; j++) 
            if (i != j)
                e[++m].x = a[j][0] - a[i][0],
                e[m].y = a[j][1] - a[i][1];
        sort(e + 1, e + m + 1);
        for (int j = m + 1; j <= 2 * m; j++)
            e[j].x = e[j - m].x, e[j].y = e[j - m].y;
        int Left = 1;
        long long cur = 1LL * m * (m - 1) * (m - 2) / 6;
        for (int j = 1; j <= m; j++) {
            for (; Left < m + j && e[Left].x * e[j].y - e[Left].y * e[j].x <= 0; ++Left);
            cur -= max(0, (Left - j - 1) * (Left - j - 2) / 2); 
        }
        ans += cur;
    }        
    ans *= (n - 4);
    ans /= 2;
    printf("%I64d\n", ans);
}