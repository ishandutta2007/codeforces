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

namespace asl
{
    
    const int m1000000007 = 1000000007;
    const int m1000000009 = 1000000009;
    const int m998244353 = 998244353;

    int MOD = m1000000007;

    void set_mod(int mod)
    {
        MOD = mod;
    }

    class Mint
    {
    public:
        int val;

        Mint(long long v = 0)
        {
            if (v >= 0)
            {
                if (v < MOD)
                    val = v;
                else
                    val = v % MOD;
            }
            else
            {
                if (v >= -MOD)
                {
                    val = v + MOD;
                }
                else
                {
                    v %= MOD;
                    if (v < 0)
                        v += MOD;
                    val = v;
                }
            }
        }

        Mint &operator+=(const Mint &other)
        {
            val += other.val;
            if (val >= MOD)
                val -= MOD;
            return *this;
        }

        Mint &operator-=(const Mint &other)
        {
            val -= other.val;
            if (val < 0)
                val += MOD;
            return *this;
        }

        static unsigned fast_mod(uint64_t x, unsigned m = MOD)
        {
#if !defined(_WIN32) || defined(_WIN64)
            return x % m;
#endif
            
            unsigned x_high = x >> 32, x_low = (unsigned)x;
            unsigned quot, rem;
            asm("divl %4\n"
                : "=a"(quot), "=d"(rem)
                : "d"(x_high), "a"(x_low), "r"(m));
            return rem;
        }

        Mint &operator*=(const Mint &other)
        {
            val = fast_mod((uint64_t)val * other.val);
            return *this;
        }

        friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
        friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
        
        Mint &operator++()
        {
            val = val == MOD - 1 ? 0 : val + 1;
            return *this;
        }

        Mint operator++(int)
        {
            Mint before = *this;
            ++*this;
            return before;
        }
        
        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
 
#include <stdint.h>

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

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n = 0, int m = 0)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m));
    }

} 

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

vec<Mint> mult(vec<Mint> a, vec<Mint> b)
{
    vec<Mint> c(a.size() + b.size() - 1);

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            c[i + j] += a[i] * b[j];

    return c;
}

void solve()
{
    int n;
    cin >> n;

    auto b = board<int>(n, n);
    cin >> b;

    auto order = board<int>(n, n);
    
    for (int i = 0; i < n; ++i)
    {
        iota(order[i].begin(), order[i].end(), 0);
        sort(order[i].begin(), order[i].end(), [&](int u, int v) { return b[i][u] < b[i][v]; });
    }

    vec<Mint> last(n);
    vec<Mint> cur_h(n);
    map<int, int> map_hash_id;
    vec<set<int>> g;

    auto get_id = [&](Mint u) {
        int v = u.val;

        if (map_hash_id.find(v) == map_hash_id.end())
        {
            int s = map_hash_id.size();
            map_hash_id[v] = s;
            g.push_back({});
            return s;
        }
        else
        {
            return map_hash_id[v];
        }
    };

    Mint B = m1000000009;

    for (int i = 0; i < n; ++i)
    {
        cur_h[i] = last[i] = B - i;
        get_id(last[i]);
    }

    for (int j = 1; j < n; ++j)
    {
        map<int, int> freq;
        for (int i = 0; i < n; ++i)
        {
            cur_h[i] *= B - order[i][j];
            freq[cur_h[i].val]++;
        }

        set<int> good;

        for (auto [a, b] : freq)
            if (b == j + 1)
                good.insert(a);

        for (int i = 0; i < n; ++i)
            if (good.count(cur_h[i].val))
            {
                int u = get_id(cur_h[i]);
                int v = get_id(last[i]);
                g[u].insert(v);
                last[i] = cur_h[i];
            }
    }

    vec<vec<Mint>> answer(g.size());

    for (int i = 0; i < g.size(); ++i)
    {
        vec<Mint> &cur = answer[i];

        if (g[i].empty())
        {
            cur = {0, 1};
        }
        else
        {
            cur = {1};
            for (auto u : g[i])
            {
                cur = mult(cur, answer[u]);
            }
            cur[1]++;
        }

    }

    for (int i = 1; i <= n; ++i)
        cout << answer.back()[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m998244353);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}