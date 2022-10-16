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

#include <experimental/optional>

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n = 0, int m = 0)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m));
    }

} 

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    auto dp = board<int>(n + 1, m + 1);

    int answer = 0;

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);

            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);

            if (i > 0 && j > 0)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 4 - 2);
                else
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 2);
            }

            answer = max(answer, dp[i][j]);
        }

    cout << answer << endl;
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