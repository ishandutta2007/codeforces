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

        friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
        friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
        friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }

        Mint inv() const
        {
            return mod_inv(val);
        }

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
 
    template <typename T>
    using vec = std::vector<T>;

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

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

vector<int> zfunction(const vec<char> &s)
{
    int n = s.size();
    vector<int> z(n, n);

    for (int i = 1, g = 0, f; i < n; ++i)
        if (i < g && z[i - f] != g - i)
            z[i] = min(z[i - f], g - i);
        else
        {
            for (g = max(g, i), f = i; g < n && s[g] == s[g - f]; ++g)
                ;
            z[i] = g - f;
        }

    return z;
}

std::vector<int> pip(const string &s)
{
    int n = s.size();
    std::vector<int> pi(n);

    for (int i = 1, k = 0; i < n; ++i)
    {
        while (k && s[i] != s[k])
            k = pi[k - 1];
        k += s[i] == s[k];
        pi[i] = k;
    }

    return pi;
}

int kmp(const string &text, const string &pattern)
{
    int n = text.size(), m = pattern.size();
    std::vector<int> pi = pip(pattern);
    int ans = 0;

    for (int i = 0, k = 0; i < n; ++i)
    {
        while (k && text[i] != pattern[k])
            k = pi[k - 1];
        k += text[i] == pattern[k];
        if (k == m)
        {
            ++ans;
            k = pi[k - 1];
        }
    }

    return ans;
}

const int inf = 1e9;

void solve()
{
    int n, m;
    cin >> n >> m;

    string s0, t;
    cin >> s0 >> t;

    Mint i2 = Mint(1) / 2;

    vec<Mint> p2(t.size() + 1);
    vec<int> str_size(t.size() + 1);
    auto acc = board<Mint>(26, t.size() + 1);

    str_size[0] = s0.size();
    p2[0] = 1;

    for (int i = 0; i < t.size(); ++i)
    {
        p2[i + 1] = p2[i] * 2;
        str_size[i + 1] = min(inf, 2 * str_size[i] + 1);

        for (int j = 0; j < 26; ++j)
            acc[j][i + 1] = acc[j][i] * 2;
        acc[t[i] - 'a'][i + 1] += 1;
    }
    
    vec<pair<int, string>> q(m);
    vec<Mint> res(m);

    int top = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> q[i].first >> q[i].second;
        top = max(top, (int)q[i].second.size());
    }

    vec<char> builder(s0.begin(), s0.end());
    int pos = 0;

    while (builder.size() < top && pos < t.size())
    {
        int cur = builder.size();
        builder.push_back(t[pos++]);
        for (int i = 0; i < cur; ++i)
        {
            char nxt = builder[i];
            builder.push_back(nxt);
        }
    }

    vec<char> a = builder, b = builder;
    reverse(b.begin(), b.end());
    vec<int> sizes;

    for (int i = 0; i < m; ++i)
    {
        int t = q[i].second.size();
        sizes.push_back(a.size());

        for (int j = 0; j < t; ++j)
        {
            a.push_back(q[i].second[j]);
            b.push_back(q[i].second[t - j - 1]);
        }
    }

    auto za = zfunction(a);
    za.push_back(0);

    auto zb = zfunction(b);
    zb.push_back(0);

    for (int i = 0; i < m; ++i)
    {
        
        int tot = q[i].second.size();

        Mint res;

        for (int j = 0; j < tot; ++j)
        {
            if (za[sizes[i] + j + 1] >= tot - j - 1 &&
                zb[sizes[i] + tot - j] >= j)
            {
                int hi = q[i].first;
                int m_side = max(j, tot - j - 1);
                int lo = lower_bound(str_size.begin(), str_size.end(), m_side) - str_size.begin() + 1;

                if (lo <= hi)
                {
                    char c = q[i].second[j] - 'a';
                    res += acc[c][hi] - acc[c][lo - 1] * p2[hi - lo + 1];
                }
            }
        }

        if (tot <= s0.size())
            res += p2[q[i].first] * kmp(s0, q[i].second);

        cout << res << endl;
    }
}

int main()
{
    set_mod(m1000000007);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}