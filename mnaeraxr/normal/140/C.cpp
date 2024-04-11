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
    int n;
    cin >> n;

    vec<int> a(n);
    cin >> a;

    sort(a.begin(), a.end());

    set<pair<int, int>> freq;

    for (int i = 0, j; i < n; i = j)
    {
        for (j = i; j < n && a[j] == a[i]; ++j)
            ;

        freq.insert({i - j, a[i]});
    }

    vec<tuple<int, int, int>> ans;

    auto pop = [&]() {
        auto x = freq.begin();
        auto y = *x;
        freq.erase(x);
        return y;
    };

    while (freq.size() >= 3)
    {
        auto a = pop(), b = pop(), c = pop();
        ans.push_back({a.second, b.second, c.second});
        a.first++;
        b.first++;
        c.first++;

        if (a.first < 0)
            freq.insert(a);
        if (b.first < 0)
            freq.insert(b);
        if (c.first < 0)
            freq.insert(c);
    }

    cout << ans.size() << endl;

    for (auto [x, y, z] : ans)
    {
        vec<int> r = {x, y, z};

        sort(r.begin(), r.end());

        reverse(r.begin(), r.end());

        cout << r << endl;
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