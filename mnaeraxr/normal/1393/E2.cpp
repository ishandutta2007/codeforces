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
 
    void get_buckets(int *s, const int n, std::vector<int> &bkt, const int K, bool end)
    {
        for (int i = 0; i < K; ++i)
            bkt[i] = 0;
        for (int i = 0; i < n; ++i)
            ++bkt[s[i]];
        for (int i = 0, sum = 0; i < K; ++i)
        {
            sum += bkt[i];
            bkt[i] = end ? sum : sum - bkt[i];
        }
    }

    void induce_sort(int *s, int *sa, const int n, const std::vector<bool> &type, std::vector<int> &bkt, const int K)
    {
        get_buckets(s, n, bkt, K, false);
        for (int i = 0, j; i < n; ++i)
            if ((j = sa[i] - 1) >= 0 && !type[j])
                sa[bkt[s[j]]++] = j;
        get_buckets(s, n, bkt, K, true);
        for (int i = n - 1, j; i >= 0; --i)
            if ((j = sa[i] - 1) >= 0 && type[j])
                sa[--bkt[s[j]]] = j;
    }

    void sa_is(int *s, int *sa, const int n, std::vector<int> &bkt)
    {
        std::vector<bool> type(n);
        type[n - 1] = true;
        for (int i = n - 3; i >= 0; --i)
            type[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && type[i + 1]);
        const int K = *std::max_element(s, s + n) + 1;
        get_buckets(s, n, bkt, K, true);
        for (int i = 0; i < n; ++i)
            sa[i] = -1;
        auto isLMS = [&](int i) { return i > 0 && type[i] && !type[i - 1]; };
        for (int i = 1; i < n; ++i)
            if (isLMS(i))
                sa[--bkt[s[i]]] = i;
        induce_sort(s, sa, n, type, bkt, K);
        int n1 = 0;
        for (int i = 0; i < n; ++i)
            if (isLMS(sa[i]))
                sa[n1++] = sa[i];
        for (int i = n1; i < n; ++i)
            sa[i] = -1;
        int name = 0, prev = -1;
        for (int i = 0; i < n1; ++i)
        {
            int pos = sa[i];
            bool diff = false;
            for (int d = 0; d < n; ++d)
                if (prev == -1 || s[pos + d] != s[prev + d] || type[pos + d] != type[prev + d])
                {
                    diff = true;
                    break;
                }
                else if (d > 0 && (isLMS(pos + d) || isLMS(prev + d)))
                    break;
            if (diff)
            {
                name++;
                prev = pos;
            }
            pos /= 2;
            sa[n1 + pos] = name - 1;
        }
        for (int i = n - 1, j = n - 1; i >= n1; --i)
            if (sa[i] >= 0)
                sa[j--] = sa[i];
        int *sa1 = sa, *s1 = sa + n - n1;
        if (name < n1)
            sa_is(s1, sa1, n1, bkt);
        else
            for (int i = 0; i < n1; ++i)
                sa1[s1[i]] = i;
        get_buckets(s, n, bkt, K, true);
        for (int i = 1, j = 0; i < n; ++i)
            if (isLMS(i))
                s1[j++] = i;
        for (int i = 0; i < n1; ++i)
            sa1[i] = s1[sa1[i]];
        for (int i = n1; i < n; ++i)
            sa[i] = -1;
        for (int i = n1 - 1, j; i >= 0; --i)
        {
            j = sa[i];
            sa[i] = -1;
            sa[--bkt[s[j]]] = j;
        }
        induce_sort(s, sa, n, type, bkt, K);
    }

    template <typename RAIter>
    std::pair<std::vector<int>, std::vector<int>> suffix_array_inner(RAIter beg, RAIter end)
    {
        const int n = distance(beg, end);
        if (n < 2)
            return std::make_pair(std::vector<int>(n), std::vector<int>(n));
        std::vector<int> s(n + 1), sa(n + 1), rank(n);
        for (int i = 0; i < n; ++i)
            s[i] = (int)beg[i] + 1;
        int alpha = (n + 1) / 2;
        for (int i = 0; i < n; ++i)
            alpha = std::max(alpha, s[i]);
        if (alpha > 5000000) 
            throw std::invalid_argument("big alpha!!!");
        std::vector<int> bkt(alpha + 1);
        sa_is(&s[0], &sa[0], n + 1, bkt);
        assert(sa[0] == n);
        sa.erase(sa.begin());
        for (int i = 0; i < n; ++i)
            rank[sa[i]] = i;
        return std::make_pair(move(sa), move(rank));
    }

    class SuffixArray
    {
    public:
        int n;
        std::vector<int> sa, lcp, rank;

        SuffixArray(std::string s) : n(s.length() + 1), lcp(n)
        {
            s += (char)0;
            std::tie(sa, rank) = suffix_array_inner(s.begin(), s.end());

            int i, j, k;
            for (j = rank[lcp[i = k = 0] = 0]; i < n - 1; ++i, ++k)
            {
                while (k >= 0 && s[i] != s[sa[j - 1] + k])
                    lcp[j] = k--, j = rank[sa[j] + 1];
            }
        }
    };

} 

#include <random>

#include <utility>

#define endl '\n'

using namespace asl;
using namespace std;

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