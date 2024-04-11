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

void solve()
{
    int n;
    cin >> n;
    vec<int> a(n);
    cin >> a;

    vec<pair<int, int>> res;
    set<pair<int, int>> stk2;
    set<pair<int, int>> stk3;

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == 0)
        {
        }
        else if (a[i] == 1)
        {
            res.push_back({i + 1, n - i});
            stk2.insert({i + 1, n - i});
            stk3.insert({i + 1, n - i});
        }
        else if (a[i] == 2)
        {
            if (stk2.empty())
            {
                cout << -1 << endl;
                return;
            }

            int x, y;
            tie(x, y) = *stk2.begin();
            stk2.erase({x, y});
            stk3.erase({x, y});
            res.push_back({i + 1, y});
            stk3.insert({i + 1, y});
        }
        else
        {
            if (stk3.empty())
            {
                cout << -1 << endl;
                return;
            }

            int x, y;
            tie(x, y) = *stk3.begin();
            stk3.erase({x, y});
            stk2.erase({x, y});

            res.push_back({x, n - i});
            res.push_back({i + 1, n - i});
            stk3.insert({i + 1, n - i});
        }
    }

    cout << res.size() << endl;

    for (auto [x, y] : res)
        cout << n - y + 1 << " " << x << endl;
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