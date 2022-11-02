#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)2e9;

long long absll(long long a)
{
    if (a > 0)
        return a;
    else
        return -a;
}

int get_changed(const vector<long long> &a, long long diff)
{
    vector<long long> dp(a.size());
    for (int pos = 0; pos < a.size(); pos++)
        dp[pos] = pos;
    for (int pos = 1; pos < a.size(); pos++)
        for (int last = 0; last < pos; last++)
            if (absll(a[pos] - a[last]) <= (pos - last) * diff)
                dp[pos] = min(dp[pos], dp[last] + pos - last - 1);
    long long res = INF;
    for (int pos = 0; pos < a.size(); pos++)
        res = min((long long)res, dp[pos] + a.size() - pos - 1);
    return (int)res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &elem: a)
        cin >> elem;
    long long low = 0;
    long long high = INF;
    while (low < high)
    {
        long long mid = (low + high) >> 1;
        if (get_changed(a, mid) <= k)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low;

    return 0;
}