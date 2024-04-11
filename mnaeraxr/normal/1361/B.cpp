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

        friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
        
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
} 

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, p;
    cin >> n >> p;

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    if (p == 1)
    {
        cout << (n & 1) << endl;
        return;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int big = -1;
    vector<pair<int, int>> rem;

    for (auto k : v)
    {
        if (big == -1)
        {
            big = k;
            continue;
        }

        bool need_push = true;

        while (!rem.empty() && rem.back().first == k)
        {
            rem.back().second++;

            if (rem.back().second == p)
            {
                need_push = true;
                k = rem.back().first + 1;
                rem.pop_back();
            }
            else
            {
                need_push = false;
                break;
            }
        }

        if (need_push)
        {
            if (k == big)
            {
                assert(rem.empty());
                big = -1;
            }
            else
            {
                rem.push_back({k, 1});
            }
        }
    }

    Mint answer;

    if (big >= 0)
    {
        answer = Mint(p).pow(big);

        for (auto u : rem)
        {
            answer -= Mint(p).pow(u.first) * u.second;
        }
    }

    cout << answer << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m1000000007);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}