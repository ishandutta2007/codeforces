#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n, l[5005], r[5005], a[5005], dp[5005], xxor, ls, rs;
bool used[5005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (l[a[i]] == 0)
            l[a[i]] = i;
        r[a[i]] = i;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ls = 999999999;
        rs = -1;
        for (int i = 0; i <= 5000; i++)
            used[i] = false;
        dp[i] = dp[i-1];
        xxor = 0;
        for (int j = i; j > 0; j--)
        {
            ls = min(ls, l[a[j]]);
            rs = max(rs, r[a[j]]);
            if (!used[a[j]])
            {
                used[a[j]] = true;
                xxor = xxor ^ a[j];
            }
            if (ls == j && rs == i)
                dp[i] = max(dp[i], xxor + dp[j-1]);
        }
    }
    cout << dp[n];
    return 0;
}