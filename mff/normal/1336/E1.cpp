#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

const long long mod = 998244353;

void add(long long &a, long long b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

long long swapbit(long long mask, int i, int j)
{
    long long bi = mask >> i & 1;
    long long bj = mask >> j & 1;
    mask &= ~((1LL << i) | (1LL << j));
    mask |= bi << j;
    mask |= bj << i;
    return mask;
}

int bit_count(long long mask)
{
    int ans = 0;
    while (mask)
    {
        if (mask & 1)
            ans++;
        mask >>= 1;
    }
    return ans;
}

const int M = 20;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> base(m);
    vector<long long> answer(m + 1);

    long long zero = 1;

    for (int i = 0; i < n; ++i)
    {
        long long u;
        cin >> u;

        bool found = false;

        for (int j = m - 1; j >= 0 && u; --j)
        {
            if (u >> j & 1)
            {
                if (base[j])
                    u ^= base[j];
                else
                {
                    swap(base[j], u);
                    found = true;
                }
            }
        }

        if (!found)
            add(zero, zero);
    }

    // TODO: Test this
    while (!base.empty() && base.back() == 0)
    {
        base.pop_back();
        m--;
    }

    for (int i = m - 2; i >= 0; --i)
    {
        int j = i;
        while (base[j] && !base[j + 1])
        {
            for (int k = 0; k < m; ++k)
                base[k] = swapbit(base[k], j, j + 1);
            swap(base[j], base[j + 1]);
            j++;
        }
    }

    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            if ((base[j] ^ base[i]) < base[j])
                base[j] ^= base[i];
        }
    }

    int t = 0;

    while (t < m && base[m - t - 1])
        ++t;

    if (t <= M)
    { // Brute Force
        for (int i = 0; i < (1 << t); ++i)
        {
            long long cur = 0;

            for (int j = 0; j < t; ++j)
                if (i >> j & 1)
                    cur ^= base[m - j - 1];
            add(answer[bit_count(cur)], 1LL);
        }
    }
    else
    {
        int rem = m - t;
        vector<vector<long long>> dp(t + 1, vector<long long>(1 << rem));
        dp[0][0] = 1;

        for (int i = 0; i < t; ++i)
        {
            long long u = base[m - i - 1];
            u ^= 1LL << (m - i - 1);
            assert(u < (1LL << rem));

            for (int j = i; j >= 0; --j)
                for (int m = 0; m < (1 << rem); ++m)
                    add(dp[j + 1][m ^ u], dp[j][m]);
        }

        for (int i = 0; i <= t; ++i)
            for (int m = 0; m < (1 << rem); ++m)
                add(answer[bit_count(m) + i], dp[i][m]);
    }

    for (auto x : answer)
        cout << 1LL * x * zero % mod << " ";
    cout << endl;

    return 0;
}