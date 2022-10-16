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
    int n, k;
    cin >> n >> k;

    vec<int> a(n);
    cin >> a;

    map<int, int> freq;

    for (int i = 0; i < n; ++i)
    {
        freq[a[i]]++;
    }

    set<pair<int, int>> s;

    auto pop = [&]() {
        auto it = s.end();
        --it;
        auto cur = *it;
        s.erase(it);
        return cur;
    };

    auto push = [&](int f, int v) {
        if (f > 0)
        {
            s.insert({f, v});
        }
    };

    for (auto p : freq)
    {
        push(p.second, p.first);
    }

    vec<pair<int, int>> ans;

    if ((n & 1) && s.size() >= 3)
    {
        auto a = pop();
        auto b = pop();
        auto c = pop();

        ans.push_back({a.second, b.second});
        ans.push_back({b.second, c.second});
        ans.push_back({c.second, a.second});

        push(a.first - 1, a.second);
        push(b.first - 1, b.second);
        push(c.first - 1, c.second);
    }

    while (s.size() >= 2)
    {
        auto a = pop();
        auto b = pop();

        ans.push_back({a.second, b.second});
        ans.push_back({b.second, a.second});

        push(a.first - 1, a.second);
        push(b.first - 1, b.second);
    }

    while (s.size() >= 1)
    {
        auto a = pop();

        ans.push_back({a.second, a.second});
        push(a.first - 1, a.second);
    }

    int total = 0;

    for (auto p : ans)
    {
        total += p.first != p.second;
    }

    cout << total << endl;

    for (auto [x, y] : ans)
    {
        cout << x << " " << y << endl;
    }
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