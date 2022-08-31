#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_len = 64;

ll dp[max_len][max_len];
bool vis[max_len][max_len] = {0};
ll n;
ll len;

int m[max_len];

ll poww(ll a, int pow1)
{
    /*if (pow > 18)
    {
        return -1;
    }*/
    //return a * pow(n, pow1)
    long double lda = a;
    ll st = 1;
    ld ldst = 1;

    for (int i = 0; i < pow1; ++i)
    {
        ldst *= (ld)n;
        if (ldst > 1e18)
        {
            return -1;
        }
    }

    for (int i = 0; i < pow1; ++i)
    {
        st *= n;
    }
    ld ans = lda * (ld) st;
    if (ans > 1e18)
    {
        return -1;
    }
    return st * a;
}

ll mult(ll a, ll b)
{
    ld lda = a;
    ld ldb = b;
    ld ldans = lda * ldb;
    if (ldans > 1e18)
    {
        return -1;
    }
    return a * b;
}

ll f(int lraz, int kolr)
{
    if (lraz == len)
    {
        if (kolr == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    if (lraz < len && kolr == 0)
    {
        return -1;
    }

    //if (dp[])
    ll ans = -1;
    if (m[lraz] == 0)
    {
        ans = f(lraz + 1, kolr - 1);
    }
    else
    {
        ll cur = 0;
        for (int i = lraz + 1; i <= len; ++i)
        {
            cur *= 10;
            cur += m[i - 1];
            if (cur >= n)
            {
                break;
            }
            ll right = f(i, kolr - 1);
            if (right == -1) continue;
            ll curans = poww(cur, kolr - 1);
            if (curans == -1) continue;
            curans += right;
            if (curans > 1e18 || curans < 0) continue;
            if (ans == -1)
            {
                ans = curans;
            }
            else
            {
                ans = min(ans, curans);
            }
        }
    }

    vis[lraz][kolr] = true;
    dp[lraz][kolr] = ans;
    return ans;
}


int main()
{
    //ifstream cin("input.txt");
    string s;
    cin >> n;
    cin >> s;
    len = s.size();
    for (int i = 0; i < s.size(); ++i)
    {
        m[i] = s[i] - 48;
    }

    ll ans = -1;
    for (int kolr = 1; kolr <= 60; ++kolr)
    {
        ll curans = f(0, kolr);
        if (curans == -1) continue;
        if (ans == -1)
        {
            ans = curans;
        }
        else
        {
            ans = min(ans, curans);
           // cout << kolr << ' ';
        }
    }

    cout << ans;

    return 0;
}