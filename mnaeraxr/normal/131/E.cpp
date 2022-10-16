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

    map<int, set<pair<int, int>>> a, b, c, d;

    vec<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].insert(make_pair(x, y));
        b[y].insert(make_pair(x, y));
        c[x + y].insert(make_pair(x, y));
        d[x - y].insert(make_pair(x, y));

        q.push_back(make_pair(x, y));
    }

    vec<int> sol(9);
    int t = 0;

    auto check = [&](set<pair<int, int>> &a, pair<int, int> cur) {
        auto it = a.lower_bound(cur);

        if (it != a.begin())
            ++t;
        if (++it != a.end())
            ++t;
    };

    for (auto p : q)
    {
        t = 0;
        check(a[p.first], p);
        check(b[p.second], p);
        check(c[p.first + p.second], p);
        check(d[p.first - p.second], p);
        sol[t]++;
    }

    cout << sol << endl;
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