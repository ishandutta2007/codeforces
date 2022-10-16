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
    
    const int m1000000007 = 1000000007;
    
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

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
 
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

#include <utility>

namespace asl
{
    
    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&... args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

} 

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, k;
    cin >> n >> k;

    vec<int> a(n), b(k), s(n + 1, 1), wh(n + 1);
    cin >> a >> b;

    vec<int> le(n), ri(n);

    for (int i = 0; i < n; ++i)
        le[i] = i - 1, ri[i] = i + 1;

    for (int i = 0; i < n; ++i)
        wh[a[i]] = i;

    ri[n - 1] = -1;

    auto get_left = y_combinator([&](auto self, int u) -> int {
        int v = le[u];
        if (v != -1 && s[v] == 0)
            le[u] = self(v);
        return le[u];
    });

    auto get_right = y_combinator([&](auto self, int u) -> int {
        int v = ri[u];
        if (v != -1 && s[v] == 0)
            ri[u] = self(v);
        return ri[u];
    });

    for (auto u : b)
        s[wh[u]] = 2;

    Mint answer = 1;

    for (auto u : b)
    {
        int l = get_left(wh[u]);
        int r = get_right(wh[u]);

        int tot = int(l != -1 && s[l] != 2) + int(r != -1 && s[r] != 2);
        answer *= tot;
        s[wh[u]] = 1;

        if (l != -1 && s[l] != 2)
            s[l] = 0;
        else if (r != -1 && s[r] != 2)
            s[r] = 0;
        else
            break;
    }

    cout << answer << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m998244353);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}