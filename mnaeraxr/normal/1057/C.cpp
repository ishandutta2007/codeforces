#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

namespace asl
{
    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

} 

#include <experimental/optional>

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

int dp[51][51][2001];

void solve()
{
    memset(dp, 0x3f, sizeof dp);

    int n, s, k;
    cin >> n >> s >> k;

    vec<int> r(n);
    string col;
    cin >> r >> col;
    col += '$';
    r.resize(n + 1);
    s--;

    int answer = 0;
    deque<tuple<int, int, int>> q;
    q.push_back({s, n, 0});
    dp[s][n][0] = 0;

    while (!q.empty())
    {
        int cur, prev, candies;
        tie(cur, prev, candies) = q.front();
        q.pop_front();

        if (candies >= k)
        {
            cout << dp[cur][prev][candies] << endl;
            exit(0);
        }

        if (r[cur] > r[prev] && col[cur] != col[prev] && dp[cur][cur][min(candies + r[cur], k)] > dp[cur][prev][candies])
        {
            dp[cur][cur][min(candies + r[cur], k)] = dp[cur][prev][candies];
            q.push_front({cur, cur, min(candies + r[cur], k)});
        }

        if (cur > 0 && dp[cur - 1][prev][candies] > dp[cur][prev][candies] + 1)
        {
            dp[cur - 1][prev][candies] = dp[cur][prev][candies] + 1;
            q.push_back({cur - 1, prev, candies});
        }

        if (cur + 1 < n && dp[cur + 1][prev][candies] > dp[cur][prev][candies] + 1)
        {
            dp[cur + 1][prev][candies] = dp[cur][prev][candies] + 1;
            q.push_back({cur + 1, prev, candies});
        }
    }

    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}