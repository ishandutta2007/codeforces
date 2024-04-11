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
    
    template <typename A, typename B>
    std::istream &operator>>(std::istream &is, std::pair<A, B> &p)
    {
        return is >> p.first >> p.second;
    }

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

void solve()
{
    int r, n;
    cin >> r >> n;

    vec<pair<int, pair<int, int>>> cel(n);
    cin >> cel;
    reverse(cel.begin(), cel.end());
    cel.push_back({0, {1, 1}});
    reverse(cel.begin(), cel.end());
    n++;

    vec<int> dp(n), ac(n);

    int diff = 2 * (r - 1);
    int cur = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        int ti = cel[i].first, xi = cel[i].second.first, yi = cel[i].second.second;

        for (int j = i + 1; j < n; ++j)
        {
            int tj = cel[j].first, xj = cel[j].second.first, yj = cel[j].second.second;

            if (tj - ti >= diff)
            {
                dp[i] = max(dp[i], ac[j]);
                break;
            }
            else if (tj - ti >= abs(xi - xj) + abs(yi - yj))
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }

        dp[i]++;
        ac[i] = max(dp[i], cur);
        cur = ac[i];
    }

    cout << dp[0] - 1 << endl;
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