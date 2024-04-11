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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, q;
    cin >> n >> q;

    vec<pair<int, int>> a(q);
    cin >> a;

    vector<int> tot(n + 2);

    for (auto p : a)
    {
        tot[p.first]++;
        tot[p.second + 1]--;
    }

    vector<vector<int>> lst(3);

    int top = 0;

    for (int i = 1; i <= n + 1; ++i)
    {
        tot[i] += tot[i - 1];

        if (1 <= tot[i] && tot[i] <= 2)
            lst[tot[i]].push_back(i);

        if (tot[i])
            top++;
    }

    auto how = [&](int v, int x, int y) {
        return upper_bound(lst[v].begin(), lst[v].end(), y) -
               lower_bound(lst[v].begin(), lst[v].end(), x);
    };

    int best = top;

    for (int i = 0; i < q; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int x = how(1, a[i].first, a[i].second);
            int y = how(1, a[j].first, a[j].second);

            int u = max(a[i].first, a[j].first);
            int v = min(a[i].second, a[j].second);

            int z = 0;

            if (u <= v)
            {
                z = how(2, u, v);
            }

            best = min(best, x + y + z);
        }
    }

    cout << top - best << endl;
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