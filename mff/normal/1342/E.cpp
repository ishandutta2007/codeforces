#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <experimental/optional>

namespace asl
{
    namespace modint
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

            static int mod_inv(int a, int m = MOD)
            {
                
                int g = m, r = a, x = 0, y = 1;

                while (r != 0)
                {
                    int q = g / r;
                    g %= r;
                    std::swap(g, r);
                    x -= q * y;
                    std::swap(x, y);
                }

                return x < 0 ? x + m : x;
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

            Mint &operator/=(const Mint &other)
            {
                return *this *= other.inv();
            }

            friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
            friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }

            Mint inv() const
            {
                return mod_inv(val);
            }

            Mint pow(long long p) const
            {
                assert(p >= 0);
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
    } 
 
    std::vector<modint::Mint> inv = {0, 1}, factorial = {1, 1}, inv_factorial = {1, 1};

    void prepare_factorials(int maximum, bool inverse = true)
    {
        factorial.resize(maximum + 1);

        for (int i = 2; i <= maximum; ++i)
        {
            factorial[i] = i * factorial[i - 1];
        }

        if (inverse)
        {

            inv.resize(maximum + 1);
            inv_factorial.resize(maximum + 1);

            for (int i = 2; i <= maximum; i++)
            {
                inv[i] = inv[modint::MOD % i] * (modint::MOD - modint::MOD / i);
                inv_factorial[i] = inv[i] * inv_factorial[i - 1];
            }
        }
    }

    modint::Mint choose(long long n, long long r)
    {
        if (r < 0 || r > n)
            return 0;
        return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
    }

    modint::Mint permute(long long n, long long k)
    {
        if (k < 0 || k > n)
            return 0;
        return factorial[n] * inv_factorial[n - k];
    }

    modint::Mint stirling2(long long n, long long k)
    {

        modint::Mint res;

        for (int i = 0; i <= k; ++i)
        {
            auto cur = choose(k, i) * modint::Mint(k - i).pow(n);

            if (i & 1)
            {
                res -= cur;
            }
            else
            {
                res += cur;
            }
        }

        return res / factorial[k];
    }
} 

using namespace std;
using namespace asl::modint;
using namespace asl;

#define endl '\n'

Mint solve(long long n, long long k)
{
    if (k >= n)
    {
        return 0;
    }
    else if (k == 0)
    {
        return factorial[n];
    }
    else
    {
        return 2 * stirling2(n, n - k) * permute(n, n - k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m998244353);

    long long n, k;
    cin >> n >> k;

    prepare_factorials(n);

    cout << solve(n, k) << endl;

    return 0;
}