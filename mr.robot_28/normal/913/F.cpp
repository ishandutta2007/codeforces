
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b % 2 == 0)
    {
        int t = power(a, b / 2);
        return t * t % mod;
    }
    else
    {
        return a * power(a, b - 1) % mod;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    int power1[n + 1];
    int power2[n + 1];
    int t = power(b, mod - 2);
    power1[0] = power2[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        power1[i] = power1[i - 1] * (b - a) % mod * t % mod;
        power2[i] = power2[i - 1] * a % mod * t % mod;
    }
    int cp[n + 1][n + 1];
    for(int i = 0;i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cp[i][j] = 0;
        }
    }
    cp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        cp[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            cp[i][j] = cp[i - 1][j] * power1[j] % mod + cp[i - 1][j - 1] * power2[i - j] % mod;
            if(cp[i][j] >= mod)
            {
                cp[i][j] -= mod;
            }
     //       cout << cp[i][j] << " ";
        }
       // cout << "\n";
    }
    int strong[n + 1];
    strong[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        strong[i] = 1;
        for(int j = 1; j < i; j++)
        {
            strong[i] -= strong[j] * cp[i][j] % mod;
            if(strong[i] < 0)
            {
                strong[i] += mod;
            }
        }
    }
    int ans[n + 1];
    ans[0] = ans[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        ans[i]= 0;
        for(int j = 1; j < i; j++)
        {
            ans[i] += strong[j] * cp[i][j] % mod * (j * (i - j) % mod + j * (j - 1) / 2 + ans[j] + ans[i - j]) % mod;
            if(ans[i] >= mod)
            {
                ans[i] -= mod;
            }
        }
        int u1 = strong[i] % mod * ((i - 1) * i / 2) % mod;
        int k1 = 1 - strong[i] * cp[i][i] % mod;
        if(k1 < 0)
        {
            k1 += mod;
        }
        ans[i] += u1;
        if(ans[i] >= mod)
        {
            ans[i] -= mod;
        }
        ans[i] = ans[i] * power(k1, mod - 2) % mod;
    }
    cout << ans[n];
    return 0;
}