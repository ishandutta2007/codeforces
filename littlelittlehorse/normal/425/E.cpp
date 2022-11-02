#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 1000000007;
long long f[501][501], v[250001];
int n, m;

int main(){
    //freopen("e.in", "r", stdin);
    //freopen("e.out", "w", stdout);
    v[0] = 1;
    for (int i = 1; i <= 250000; i++) v[i] = (v[i - 1] << 1) % P;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i <= 500; i++)
        for (int j = 0; j <= i; j++)
            if (f[i][j]) 
               for (int k = i + 1; k <= 500; k++)
                   f[k][j + 1] += f[i][j] * v[(k - i) * i] % P * (v[k - i] - 1) % P,
                   f[k][j + 1] %= P;
    scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = m; i <= n; i++) ans += f[i][m] * v[(n - i) * i] % P, ans %= P;
    printf("%d\n", ans);
}