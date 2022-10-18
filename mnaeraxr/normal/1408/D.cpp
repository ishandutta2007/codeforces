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
    int n, m;
    cin >> n >> m;

    vec<pair<int, int>> a(n), b(m);
    cin >> a >> b;

    int top = 0;

    for (auto [u, v] : a)
        top = max(top, u);
    for (auto [u, v] : b)
        top = max(top, u);

    b.push_back({++top, -1});
    b.push_back({-1, 1e9});
    m += 2;

    vec<vec<pair<int, int>>> acc(top + 1);

    sort(b.begin(), b.end());

    int s = 0;

    for (int i = 0; i < m; ++i)
    {
        while (s > 0 && b[i].second >= b[s - 1].second)
            s--;
        b[s++] = b[i];
    }
    b.resize(s);

    const int inf = 1e9;

    multiset<int> ms;

    for (auto [x, y] : a)
    {
        ms.insert(inf);

        int last = inf;
        for (int i = 1; i < s; ++i)
        {
            if (b[i].first < x)
                continue;

            int delta_x = max(b[i - 1].first - x + 1, 0);
            int delta_y = max(b[i].second - y + 1, 0);

            acc[delta_x].push_back({last, delta_y});
            last = delta_y;
        }
    }

    int answer = inf;

    for (int i = 0; i < acc.size(); ++i)
    {
        for (auto [u, v] : acc[i])
        {
            ms.erase(ms.find(u));
            ms.insert(v);
        }

        answer = min(answer, i + *ms.rbegin());
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