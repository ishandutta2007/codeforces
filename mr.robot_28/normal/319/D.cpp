#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5;
int p[N];
int n, now;
int hash1[N];
int vis[N];
string s;
void gethash()
{
    for(int i = 1; i <= n; i++)
    {
        hash1[i] = (hash1[i - 1] * 29 + s[i - 1] - 'a' + 1) % mod;
    }
}
int get(int l, int r)
{
    return (hash1[r] - hash1[l - 1] * p[r - l + 1] % mod + mod) % mod;
}
int getlcp(int x, int y)
{
    int l = 0, r = now + 1;
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        if(get(x - midd + 1, x) == get(y - midd + 1, y))
        {
            l = midd;
        }
        else{
            r = midd;
        }
    }
    return l;
}
int getlcs(int x, int y)
{
    int l = 0, r = n - y + 2;
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        if(get(x, x + midd - 1) == get(y, y + midd - 1))
        {
            l = midd;
        }
        else
        {
            r = midd;
        }
    }
    return l;
}
signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
    cin >> s;
    n = sz(s);
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 29 % mod;
    }
    gethash();
    string s1 = "";
    for(int len = 1; len <= n / 2; len++)
    {
        bool flag = 0;
        now = len;
    //    cout << len << "\n";
        for(int i = len, j = i + len; j <= n; i += len, j += len)
        {
            int lcp = getlcp(i, j);
            int lcs = getlcs(i, j);
            if(lcp + lcs > len)
            {
                for(int k = i - lcp + 1; k <= i + len - lcp; k++)
                {
                    vis[k] = len;
                }
                flag = 1;
                now = lcp;
            }
            else
            {
                now = len;
            }
        }
        if(flag)
        {
            for(int k = 1; k <= n; k++)
            {
                if(vis[k] != len)
                {
                    s1 += s[k - 1];
                }
            }
            s = s1;
            n = sz(s);
            s1 = "";
            gethash();
        }
    }
    cout << s;
    return 0;
}