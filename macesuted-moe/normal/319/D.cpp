#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long a[50010], w[50010], p[50010];
char s[50010];

int get(int l, int r)
{ //l~r
    return ((w[r] - w[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

int n, now;

int lcp(int x, int y) //
{
    int l = 0, r = now;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (get(x - mid + 1, x) == get(y - mid + 1, y))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int lcs(int x, int y) //
{
    int l = 0, r = n - y + 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (get(x, x + mid - 1) == get(y, y + mid - 1))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    { //
        p[i] = p[i - 1] * 31 % mod;
        w[i] = (w[i - 1] * 31 + s[i] - 'a') % mod;
    }
    for (int len = 1; len <= n; len++)
    { //
        bool flag = false;
        int j = len, k = len << 1; //
        now = len;
        while (k <= n)
        {
            int LCP = lcp(j, k), LCS = lcs(j, k);
            if (LCP + LCS > len)
            {
                for (int i = j - LCP + 1; i <= j - LCP + len; i++)
                    a[i] = len; //
                now = LCP;      //LCSLCP
                flag = true;
            }
            else
                now = len; //
            j += len;      //
            k += len;
        }
        if (flag)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] != len)
                    s[++cnt] = s[i]; //
            n = cnt;
            for (int i = 1; i <= n; i++)
                w[i] = (w[i - 1] * 31 + s[i] - 'a') % mod; //
        }
    }
    for (int i = 1; i <= n; i++)
        putchar(s[i]);
    return 0;
}