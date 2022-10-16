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
    std::vector<std::vector<T>> board(int n, int m, T def)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m, def));
    }

} 

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

bool close(pair<int, int> &a, pair<int, int> &b)
{
    return max(abs(a.first - b.first), abs(a.second - b.second)) <= 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> all;

    for (int i = 0; i + 1 < n; ++i)
        all.push_back({i, 0});
    for (int j = 0; j + 1 < m; ++j)
        all.push_back({n - 1, j});
    for (int i = n - 1; i > 0; --i)
        all.push_back({i, m - 1});
    for (int j = m - 1; j > 0; --j)
        all.push_back({0, j});

    vector<pair<int, int>> best;
    for (int s = 0; s < 3; ++s)
    {
        vector<pair<int, int>> cur;

        for (int i = 0; i < all.size(); ++i)
        {
            auto u = all[(i + s) % all.size()];

            bool ok = true;
            for (auto v : cur)
            {
                if (close(u, v))
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
                cur.push_back(u);
        }

        if (cur.size() > best.size())
            best = cur;
    }

    auto b = board(n, m, '0');
    for (auto [x, y] : best)
        b[x][y] = '1';

    for (auto row : b)
        cout << string(row.begin(), row.end()) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}