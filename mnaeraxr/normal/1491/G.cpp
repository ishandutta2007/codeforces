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
    int n;
    cin >> n;
    vec<int> p(n + 1);
    vec<int> r(n + 1);
    vec<int> f(n + 1);

    vec<pair<int, int>> answer;

    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        r[p[i]] = i;
    }

    auto ch = [&](int x, int y) {
        assert(x != y);
        answer.push_back({x, y});
        swap(p[x], p[y]);
        r[p[x]] = x;
        r[p[y]] = y;
        f[p[x]] ^= 1;
        f[p[y]] ^= 1;
    };

    auto update_2 = [&](int x, int y) {
        
        ch(x, y);

        while (f[p[x]])
        {
            assert(f[p[x]] && f[p[y]]);
            if (p[x] != y)
                ch(x, p[x]);
            else
                ch(y, p[y]);
        }

        assert(!f[p[x]] && !f[p[y]]);
    };

    auto update_1 = [&](int a) {
        if (p[p[a]] == a)
        {
            assert(a != p[a]);
            int c = 1;
            int b = p[a];
            while (c == a || c == p[a])
                ++c;

            ch(a, c);
            ch(b, c);
            ch(a, c);
        }
        else
        {
            int v = p[a];
            ch(a, p[a]);
            ch(p[a], v);

            int x = a, y = v;
            assert(f[p[x]] && f[p[y]]);

            while (f[p[x]])
            {
                assert(f[p[x]] && f[p[y]]);
                if (p[x] != y)
                    ch(x, p[x]);
                else
                    ch(y, p[y]);
            }

            assert(!f[p[x]] && !f[p[y]]);
        }
    };

    vec<bool> seen(n + 1);
    int cur = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (seen[i])
            continue;

        int u = i;
        while (!seen[u])
        {
            seen[u] = true;
            u = p[u];
        }

        if (i == p[i])
            continue;

        if (cur == 0)
        {
            cur = i;
        }
        else
        {
            update_2(cur, i);
            cur = 0;
        }
    }

    if (cur != 0)
        update_1(cur);

    for (int i = 1; i <= n; ++i)
    {
        assert(!f[i]);
        assert(i == p[i]);
        assert(i == r[i]);
    }

    assert(answer.size() <= n + 1);
    
    cout << answer.size() << endl;
    for (auto [u, v] : answer)
        cout << u << " " << v << endl;
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