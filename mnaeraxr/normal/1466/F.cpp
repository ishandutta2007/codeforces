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
    
    void asl_assert(bool condition)
    {

    }
 
    const int m1000000007 = 1000000007;
    
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

        Mint pow(long long p) const
        {
            asl_assert(p >= 0);

            Mint a = *this, result = 1;

            while (p > 0)
            {
                if (p & 1)
                    result *= a;

                a *= a;
                p >>= 1;
            }

            return result;
        }

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
 
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

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

class DS
{
public:
    vec<int> ds, unit;

    DS(int n)
    {
        ds = vec<int>(n, -1);
        unit = vec<int>(n, 0);
    }

    int root(int a) { return ds[a] < 0 ? a : root(ds[a]); }

    bool join(int a, int b)
    {
        a = root(a), b = root(b);

        if (a == b)
            return false;

        if (unit[a] && unit[b])
            return false;

        bool is_unit = unit[a] | unit[b];

        if (ds[a] < ds[b])
            swap(a, b);

        ds[b] += ds[a];
        ds[a] = b;

        unit[b] = is_unit;

        return true;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    DS ds(m);

    vec<int> ans;

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        vec<int> a(k);
        cin >> a;

        if (k == 1)
        {
            int r = ds.root(a[0] - 1);

            if (!ds.unit[r])
            {
                ans.push_back(i + 1);
                ds.unit[r] = true;
            }
        }
        else
        {
            int u = a[0] - 1, v = a[1] - 1;

            if (ds.join(u, v))
            {
                ans.push_back(i + 1);
            }
        }
    }

    cout << Mint(2).pow(ans.size()) << " " << ans.size() << endl;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m1000000007);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}