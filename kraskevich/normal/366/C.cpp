#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 100 + 1;

bitset<N> dp[N];
int a[N];
int b[N];

int main()
{
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < N; i++)
        dp[i].reset();
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int s = N - 1; s >= a[i]; --s)
            dp[s] |= (dp[s - a[i]] << b[i]);
    for (int s = N - 1; s > 0; s--)
        if (s % k == 0 && dp[s][s / k])
        {
            cout << s;
            return 0;
        }
    cout << -1;

    return 0;
}