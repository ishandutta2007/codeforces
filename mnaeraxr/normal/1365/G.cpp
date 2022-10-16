#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
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
    
    void asl_assert(bool condition)
    {

    }
 
    int bitcount(unsigned long long c)
    {
        c = ((c >> 1) & 0x5555555555555555LL) + (c & 0x5555555555555555LL);
        c = ((c >> 2) & 0x3333333333333333LL) + (c & 0x3333333333333333LL);
        c = ((c >> 4) & 0x0f0f0f0f0f0f0f0fLL) + (c & 0x0f0f0f0f0f0f0f0fLL);
        c = ((c >> 8) & 0x00ff00ff00ff00ffLL) + (c & 0x00ff00ff00ff00ffLL);
        c = ((c >> 16) & 0x0000ffff0000ffffLL) + (c & 0x0000ffff0000ffffLL);
        c = ((c >> 32) & 0x00000000ffffffffLL) + (c & 0x00000000ffffffffLL);
        return c;
    }
} 

#include <experimental/optional>
#define optional std::experimental::optional

namespace asl
{
    
    template <typename T, typename U = T>
    optional<U> noop_get_lazy(T &p)
    {
        return optional<U>();
    }

    template <typename T>
    T add_merge(T &l, T &r) { return l + r; }

} 

namespace asl
{
    
    const int m1000000007 = 1000000007;
    
    int MOD = m1000000007;

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

        friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
        
    };
 
    std::vector<Mint> inv = {0, 1}, factorial = {1, 1}, inv_factorial = {1, 1};

    void prepare_factorials(int maximum)
    {
        factorial.resize(maximum + 1);
        inv.resize(maximum + 1);
        inv_factorial.resize(maximum + 1);

        for (int p = 2; p * p <= MOD; p++)
            asl_assert(MOD % p != 0);

        for (int i = 2; i <= maximum; ++i)
        {
            factorial[i] = i * factorial[i - 1];
            inv[i] = inv[MOD % i] * (MOD - MOD / i);
            inv_factorial[i] = inv[i] * inv_factorial[i - 1];
        }
    }

    Mint choose(long long n, long long r)
    {
        asl_assert(n < inv_factorial.size());
        asl_assert(n < factorial.size());

        if (r < 0 || r > n)
            return 0;
        return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
    }

} 

#include <random>

using namespace std;
using namespace asl;

long long query(vector<int> &q)
{
    cout << "?";
    cout << " " << q.size();

    for (auto x : q)
    {
        cout << " " << x;
    }
    cout << endl;
    cout.flush();

    long long res;
    cin >> res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prepare_factorials(13);

    int n;
    cin >> n;

    int bits = 1;

    while (choose(bits, bits / 2).val < n)
        bits++;

    vector<int> mask(n);
    int t = 0;

    for (int i = 0; i < (1 << bits) && t < n; ++i)
    {
        if (bitcount(i) == bits / 2)
        {
            mask[t++] = i;
        }
    }

    vector<long long> res(bits);

    for (int i = 0; i < bits; ++i)
    {
        vector<int> q;

        for (int j = 0; j < n; ++j)
            if (mask[j] >> i & 1)
                q.push_back(j + 1);

        res[i] = query(q);
    }

    cout << "!";

    for (int i = 0; i < n; ++i)
    {
        long long cur = 0;

        for (int j = 0; j < bits; ++j)
        {
            if ((mask[i] >> j & 1) == 0)
            {
                cur |= res[j];
            }
        }

        cout << " " << cur;
    }

    cout << endl;
    cout.flush();

    return 0;
}