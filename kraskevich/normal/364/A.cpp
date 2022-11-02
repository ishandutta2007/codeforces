#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    long long want;
    cin >> want;
    string s;
    cin >> s;

    int n = s.length();
    vector<long long> cnt(n * 10, 0);
    long long res = 0;
    for (int l = 0; l < n; l++)
    {
        long long cur = 0;
        for (int r = l; r < n; r++)
        {
            cur += s[r] - '0';
            cnt[cur]++;
        }
    }
    if (want)
    {
        for (long long sum = 1; sum < n * 10; sum++)
        {
            if (want % sum)
                continue;
            long long other = want / sum;
            if (other < cnt.size())
                res += cnt[sum] * cnt[other];
        }
    }
    else
    {
        res = cnt[0] * n * (n + 1) / 2;
        res += (n * (n + 1) / 2 - cnt[0]) * cnt[0];
    }

    cout << res;

    return 0;
}