#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 998244353;

bool a[N], b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    long long ans = 0;
    long long r = n;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == s[0])
            r = i;
        else
            break;
    long long l = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == s[0])
            l = i;
        else
            break;
   // cout << l << ' '<< r << endl;
    ans += (l + 2) * (n - 1 - r + 2);
    //cout << ans << endl;
    ans %= M;
    r = n;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == s[n-1])
            r = i;
        else
            break;
    l = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == s[n-1])
            l = i;
        else
            break;
    //cout << l << ' ' << r << endl;
    if (s[n - 1] != s[0])
        ans += (l + 2) * (n - 1 - r + 2), ans--;
    ans %= M;
    cout << ans;
    return 0;
}