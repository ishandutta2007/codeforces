#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100000 + 10;
const ll MOD = 1000000007LL;

int n, m;
ll a[N];
ll C[N + 100][110];
ll s[N][110];

int main() 
{
    for (int i = 0; i < N + 100; i ++) 
    {
        C[i][0] = 1;
        for (int j = 1; j <= min(i, 100); j ++) 
            C[i][j] = ((j == i) ? 1 : C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    memset(s, 0, sizeof(s));
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        scanf("%I64d", &a[i]);
    
    while (m --) 
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        s[l][k + 1] ++;
        for (int i = 0; i <= k + 1; i ++) 
            s[r + 1][i] = (s[r + 1][i] - C[r - l + k - i + 1][k - i + 1] + MOD) % MOD;
    }
    for (int i = 105; i >= 0; i --) 
        for (int j = 1; j <= n + 1; j ++) 
            s[j][i] = (s[j][i] + s[j - 1][i] + s[j][i + 1]) % MOD;
    for (int i = 1; i <= n; i ++) 
        printf("%I64d ", (a[i] + s[i][1]) % MOD);
    return 0;
}