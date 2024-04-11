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
    typedef long long i64;
    
#include <stdint.h>

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

        Mint &operator+=(const Mint &other)
        {
            val += other.val;
            if (val >= MOD)
                val -= MOD;
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

        friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
        
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

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;

    vec<i64> a(n);
    cin >> a;

    vec<int> freq(60);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 60; ++j)
            freq[j] += a[i] >> j & 1;

    vec<Mint> p2(60);
    p2[0] = 1;

    for (int i = 1; i < 60; ++i)
        p2[i] = p2[i - 1] * 2;

    Mint res;

    for (int i = 0; i < n; ++i)
    {
        Mint aor, aand;

        for (int j = 0; j < 60; ++j)
        {
            if (a[i] >> j & 1)
            {
                aand += freq[j] * p2[j];
                aor += n * p2[j];
            }
            else
            {
                aor += freq[j] * p2[j];
            }
        }

        res += aor * aand;
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m1000000007);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}