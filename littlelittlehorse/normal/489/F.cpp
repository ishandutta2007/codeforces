#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, p, a[501];
long long f[501][501];
char str[1011];

int main(){
    scanf("%d%d%d", &n, &m, &p);
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", str + 1);
        for (int j = 1; j <= n; j++) 
            if (str[j] == '1') ++a[j];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) 
        if (a[i] == 1) ++cnt1;
        else if (a[i] == 0) ++cnt2;
    memset(f, 0, sizeof(f));
    f[cnt1][cnt2] = 1;
    for (int i = m + 1; i <= n; i++)
        for (int k = 0; k <= cnt2; k++)
            for (int j = 0; j <= n; j++)
                if (f[j][k]) 
                {
                    if (j > 1) 
                        f[j - 2][k] += f[j][k] * j * (j - 1) / 2, f[j - 2][k] %= p;
                    if (k > 1)
                        f[j + 2][k - 2] += f[j][k] * k * (k - 1) / 2, f[j + 2][k - 2] %= p;
                    if (j && k)
                        f[j][k - 1] += f[j][k] * j * k, f[j][k - 1] %= p;
                    f[j][k] = 0;
                }
    printf("%d\n", f[0][0]);
}