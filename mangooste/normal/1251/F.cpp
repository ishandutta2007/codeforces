#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

namespace FFT {
    constexpr int MOD = 998'244'353;

    namespace mod_operations {
        inline int add(int a, int b) {
            a += b;
            return a - MOD * (a >= MOD);
        }

        inline int sub(int a, int b) {
            a -= b;
            return a + MOD * (a < 0);
        }

        inline int mult(int a, int b) {
            return int64_t(a) * b % MOD;
        }

        inline int power(int a, ll b) {
            int prod = 1;
            for (; b; b >>= 1, a = mult(a, a))
                if (b & 1)
                    prod = mult(prod, a);

            return prod;
        }

        inline int rev(int a) {
            return power(a, MOD - 2);
        }

        inline int div(int a, int b) {
            return mult(a, rev(b));
        }
    } // namespace mod_operations

    inline void fft(vector<int> &a) {
        using namespace mod_operations;

        if (a.empty())
            return;

        static auto get_primitive_root = [&]() {
            if (MOD == 998'244'353)
                return 3;

            vector<int> primes;
            int value = MOD - 1;
            for (int i = 2; i * i <= value; i++)
                if (value % i == 0) {
                    primes.push_back(i);
                    while (value % i == 0)
                        value /= i;
                }

            if (value != 1)
                primes.push_back(value);

            for (int r = 2;; r++) {
                bool ok = true;
                for (auto p : primes)
                    if (power(r, (MOD - 1) / p) == 1) {
                        ok = false;
                        break;
                    }

                if (ok)
                    return r;
            }
        };

        static int primitive_root = get_primitive_root();

        size_t n = a.size();
        assert((n & (n - 1)) == 0);
        size_t lg = __lg(n);

        static vector<size_t> reversed_mask;
        if (reversed_mask.size() != n) {
            reversed_mask.resize(n);
            for (size_t mask = 1; mask < n; mask++)
                reversed_mask[mask] = (reversed_mask[mask >> 1] >> 1) + ((mask & 1) << (lg - 1));
        }

        static vector<int> roots;
        if (roots.size() != lg) {
            roots.resize(lg);
            for (size_t i = 0; i < lg; i++)
                roots[i] = power(primitive_root, (MOD - 1) / (2 << i));
        }

        for (size_t i = 0; i < n; i++)
            if (reversed_mask[i] < i)
                swap(a[i], a[reversed_mask[i]]);

        for (size_t len = 1; len < n; len <<= 1) {
            int root = roots[__lg(len)], current;
            for (size_t i = 0; i < n; i += (len << 1)) {
                current = 1;
                for (size_t j = 0; j < len; j++, current = mult(current, root)) {
                    int value = mult(a[i + j + len], current);
                    a[i + j + len] = sub(a[i + j], value);
                    a[i + j] = add(a[i + j], value);
                }
            }
        }
    }

    inline vector<int> multiply(vector<int> a, vector<int> b) {
        using namespace mod_operations;

        if (a.empty() || b.empty())
            return {};

        size_t real_size = a.size() + b.size() - 1;
        size_t n = 1;
        while (n < real_size)
            n <<= 1;

        a.resize(n);
        b.resize(n);
        fft(a), fft(b);

        for (size_t i = 0; i < n; i++)
            a[i] = mult(a[i], b[i]);

        fft(a);
        reverse(a.begin() + 1, a.end());

        int rev_n = rev(n);
        a.resize(real_size);
        for (auto &x : a)
            x = mult(x, rev_n);

        return a;
    }
} // namespace FFT

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    using namespace FFT::mod_operations;
    vector<int> fact, rfact, p2;

    auto init_facts = [&](int n) {
        fact.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = mult(fact[i - 1], i);

        rfact.resize(n + 1, rev(fact[n]));
        for (int i = n; i > 0; i--)
            rfact[i - 1] = mult(rfact[i], i);

        p2.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p2[i] = add(p2[i - 1], p2[i - 1]);
    };

    auto choose = [&](int n, int k) {
        if (k < 0 || k > n || n < 0)
            return 0;

        return mult(fact[n], mult(rfact[k], rfact[n - k]));
    };

    int n, k;
    cin >> n >> k;
    init_facts(n);

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> b(k);
    for (auto &x : b)
        cin >> x;

    sort(all(a));
    sort(all(b));

    map<int, int> freq;
    array<int, 2> tot{};

    auto insert = [&](int x) {
        freq[x]++;
        if (freq[x] == 1)
            tot[0]++;
        else if (freq[x] == 2)
            tot[0]--, tot[1]++;
    };

    int pos = 0;
    vector<vector<int>> sum(k);
    for (int id = 0; id < k; id++) {
        while (pos < n && a[pos] < b[id])
            insert(a[pos++]);

        vector<int> first(tot[0] + 1);
        for (int i = 0; i <= tot[0]; i++)
            first[i] = mult(choose(tot[0], i), p2[i]);

        vector<int> second(2 * tot[1] + 1);
        for (int i = 0; i <= 2 * tot[1]; i++)
            second[i] = choose(2 * tot[1], i);

        sum[id] = FFT::multiply(first, second);
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x >>= 1;
        int answer = 0;
        for (int i = 0; i < k; i++) {
            if (b[i] >= x)
                break;

            int cnt = x - b[i] - 1;
            if (cnt < len(sum[i]))
                answer = add(answer, sum[i][cnt]);
        }
        cout << answer << '\n';
    }
}