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

    int maxbit(unsigned long long num)
    {
        if (num == 0)
            return -1;

        int res = 0;

        for (int i = 32; i; i >>= 1)
        {
            auto big = num >> i;
            if (big)
            {
                res += i;
                num = big;
            }
        }

        return res;
    }

    template <typename T = int>
    class RMQ
    {
    public:
        std::vector<std::vector<T>> dp;
        std::function<T(T &, T &)> combine;

        RMQ(
            std::vector<T> &a, std::function<T(T &, T &)> combine = [](T &a, T &b) { return std::min(a, b); }) : combine(combine)
        {
            int n = a.size(), lg = maxbit(n);
            dp.resize(lg + 1, std::vector<T>(n));
            dp[0] = a;
            for (int j = 0; j < lg; ++j)
                for (int i = 0; i + (2 << j) <= n; ++i)
                    dp[j + 1][i] = combine(dp[j][i], dp[j][i + (1 << j)]);
        }

        inline T query(int a, int b)
        {
            int l = maxbit(b - a);
            return combine(dp[l][a], dp[l][b - (1 << l)]);
        }

    };
} 

#include <experimental/optional>

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

        Mint &operator+=(const Mint &other)
        {
            val += other.val;
            if (val >= MOD)
                val -= MOD;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
 
    class SuffixArray
    {
    public:
        int n;
        std::vector<int> sa, lcp, rank;

        template <typename RAIter>
        SuffixArray(RAIter _begin, RAIter _end) : n(_end - _begin + 1), sa(n), lcp(n), rank(n)
        {
            std::vector<int> top(std::max(256, n));
            for (int i = 0; i < n; ++i)
                top[rank[i] = *(_begin + i) & 0xff]++;

            std::partial_sum(top.begin(), top.end(), top.begin());
            for (int i = 0; i < n; ++i)
                sa[--top[rank[i]]] = i;

            std::vector<int> tmp(n);
            for (int len = 1, j; len < n; len <<= 1)
            {
                for (int i = 0; i < n; ++i)
                {
                    j = sa[i] - len;
                    if (j < 0)
                        j += n;
                    tmp[top[rank[j]]++] = j;
                }

                sa[tmp[top[0] = 0]] = j = 0;
                for (int i = 1, j = 0; i < n; ++i)
                {
                    if (rank[tmp[i]] != rank[tmp[i - 1]] || rank[tmp[i] + len] != rank[tmp[i - 1] + len])
                        top[++j] = i;
                    sa[tmp[i]] = j;
                }

                copy(sa.begin(), sa.end(), rank.begin());
                copy(tmp.begin(), tmp.end(), sa.begin());
                if (j >= n - 1)
                    break;
            }

            int i, j, k;
            for (j = rank[lcp[i = k = 0] = 0]; i < n - 1; ++i, ++k)
            {
                while (k >= 0 && *(_begin + i) != *(_begin + sa[j - 1] + k))
                    lcp[j] = k--, j = rank[sa[j] + 1];
            }
        }

        template <typename T>
        SuffixArray(std::basic_string<T> &word) : SuffixArray(word.begin(), word.end()) {}
    };
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{

    int n;
    cin >> n;
    
    vector<int> starts(n + 1);
    vector<int> len(n + 1);

    string s = "";

    for (int i = 1; i <= n; ++i)
    {
        starts[i] = s.length();
        string x;
        cin >> x;
        
        len[i] = x.length();
        s += x;
    }

    SuffixArray sa(s);

    RMQ<int> rmq(sa.lcp);

    vec<Mint> dp(1, 1);

    auto lcp = [&](int a, int b) {
        if (a == b)
        {
            return int(s.length() - a);
        }

        a = sa.rank[a];
        b = sa.rank[b];

        if (a > b)
            swap(a, b);

        return rmq.query(a + 1, b + 1);
    };

    auto brute = [&](pair<int, int> a, pair<int, int> b) {
        string xa = "", xb = "";

        for (int i = 0; i < len[a.first]; ++i)
        {
            if (i == a.second)
                continue;
            xa += s[starts[a.first] + i];
        }

        for (int i = 0; i < len[b.first]; ++i)
        {
            if (i == b.second)
                continue;
            xb += s[starts[b.first] + i];
        }

        return xa < xb;
    };

    auto cmp = [&](pair<int, int> a, pair<int, int> b) {
        int sa = starts[a.first], la = len[a.first];
        int sb = starts[b.first], lb = len[b.first];
        int fa = a.second, fb = b.second;
        int pa = fa == 0, pb = fb == 0;

        while (pa < la && pb < lb && s[sa + pa] == s[sb + pb])
        {
            auto p = lcp(sa + pa, sb + pb);

            if (fa > pa)
                p = min(p, fa - pa);

            if (fb > pb)
                p = min(p, fb - pb);

            pa += p;
            pb += p;

            if (fa == pa)
                pa++;

            if (fb == pb)
                pb++;
        }

        bool res;

        if (pa >= la && pb >= lb)
            res = make_pair(la - (fa < la), a.first) < make_pair(lb - (fb < lb), b.first);
        else if (pa >= la)
            res = true;
        else if (pb >= lb)
            res = false;
        else
            res = s[sa + pa] < s[sb + pb];

        return res;
    };

    for (int i = 1; i <= n; ++i)
    {
        vec<Mint> ndp(len[i] + 1);

        vec<pair<int, int>> order;

        for (int p = i - 1; p <= i; ++p)
            for (int j = 0; j <= len[p]; ++j)
                order.push_back(make_pair(p, j));

        sort(order.begin(), order.end(), cmp);
        
        Mint acc = 0;

        for (auto [p, x] : order)
        {
            if (p == i - 1)
                acc += dp[x];
            else
                ndp[x] = acc;
        }

        ndp.swap(dp);
        
    }

    Mint res = 0;

    for (auto &x : dp)
        res += x;

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m1000000007);

    solve();

    return 0;
}