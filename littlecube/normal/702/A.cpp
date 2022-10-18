#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, a[100000], dp[100000] = {0}, _max = 1;
    cin >> n;
    dp[0] = 1;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
        if (a[i] > a[i-1])
            dp[i] = dp[i - 1] + 1;
        _max = max(_max, dp[i]);
    }
    cout << _max;
}