#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 1;
const double eps = 1e-8;

int n, a , b, dp[N], h1[N], h2[N], pi[N];
string s;
bool check(int len, int pos)
{
    string c = "";
    for (int i = pos - len + 1; i <= pos; i++)
        c += s[i];
    c += '#';
    for (int i = 0; i <= pos - len; i++)
        c += s[i];
    for (int i = 1; i < c.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && c[i] != c[j])
            j = pi[j - 1];
        if (c[i] == c[j]) j++;
        pi[i] = j;
    }
    /*cout << c << endl;
    for (int i = 1; i < c.size(); i++)
        cout << pi[i] << ' ';
    cout << endl;
    */for (int i = 1; i < c.size(); i++)
        if (pi[i] == len)
        return 1;
    return 0;
}

signed main()
{/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin >> n >> a >> b >> s;

    dp[0] = a;
    string c ="";
    c += s[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + a;
        int l = 1, r = i + 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (check(m, i))
                l = m;
            else
                r = m;
        }
       // cout << l << ' ' << check(2, i) << endl;
        if (check(l, i))
        for (int j = 1; j <= l; j++)
            dp[i] = min(dp[i], dp[i - j] + b);
       // cout << dp[i] << endl;
    }
    cout << dp[n - 1];
    return 0;
}