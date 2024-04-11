#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_mask = 1100000, max_n = 77, max_m = 20, inf = 1e9, mod = 1e9 + 7;
int n;
bool s[max_n];

int dp[max_n][max_mask];
bool vis[max_n][max_mask] = {0};

bool pow2[max_mask] = {0};

int f(int lastcrop, int mask)
{
    if (vis[lastcrop][mask])
    {
        return dp[lastcrop][mask];
    }

    int ans = 0;

    if (pow2[mask])
    {
        ans = 1;
    }

    if (lastcrop == n)
    {
        return ans;
    }

    int num = 0;
    int curind = lastcrop;
    while (curind < n)
    {
        num = num << 1;
        num += s[curind];
        if (num > max_m) break;
        if (num)
        {
            ans += f(curind + 1, mask | (1 << (num - 1)));
            ans %= mod;
        }
        curind++;
    }

    vis[lastcrop][mask] = true;
    dp[lastcrop][mask] = ans;
    return ans;
}

int main()
{
    //ifstream cin("input.txt");
    cin >> n;
    string a;
    cin >> a;
    for (int i = 1; i < max_mask; i = (i << 1) + 1)
    {
        pow2[i] = true;
    }
    for (int i = 0; i < a.size(); ++i)
    {
        s[i] = a[i] == '0' ? 0 : 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += f(i, 0);
        //cout << f(i, 0) << endl;
        ans %= mod;
    }

    cout << ans;

    return 0;
}