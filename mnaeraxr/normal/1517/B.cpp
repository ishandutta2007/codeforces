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
    std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
    {
        bool start = true;

        for (auto x : vec)
        {
            if (start)
            {
                start = false;
            }
            else
            {
                out << " ";
            }

            out << x;
        }
        return out;
    }

} 

#include <experimental/optional>

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n, int m, T def)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m, def));
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &board)
    {
        bool first = true;

        for (auto &row : board)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                out << std::endl;
            }
            out << row;
        }
        return out;
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

    vec<pair<int, int>> a(n * m);

    auto res = board<int>(n, m, -1);

    for (int i = 0, p = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            a[p].second = i;
            cin >> a[p++].first;
        }

    sort(a.begin(), a.end());

    for (int i = 0; i < m; ++i)
        res[a[i].second][i] = a[i].first;

    vec<int> used(n);

    for (int i = m; i < n * m; ++i)
    {
        int row = a[i].second;
        while (res[row][used[row]] != -1)
            used[row]++;
        res[row][used[row]++] = a[i].first;
    }

    cout << res << endl;
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