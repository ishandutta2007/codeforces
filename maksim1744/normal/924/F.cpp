/*
    author:  Maksim1744
    created: 08.05.2021 14:33:51
*/

#pragma GCC target("popcnt")

#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

struct B {
    array<uint64_t, 3> a;

    B() {a.fill(0);}
    B(uint64_t x) {
        a = {x, 0, 0};
    }
    B(uint64_t x, uint64_t b, uint64_t c) {
        a = {c, b, x};
    }

    int operator[](int i) {
        return (a[i >> 6] >> (i & 63)) & 1;
    }

    void operator |= (const B &other) {
        a[0] |= other.a[0];
        a[1] |= other.a[1];
        a[2] |= other.a[2];
    }

    B operator | (const B &other) const {
        return B(a[2] | other.a[2], a[1] | other.a[1], a[0] | other.a[0]);
    }

    bool operator == (const B &other) const {
        return a == other.a;
    }
    bool operator != (const B &other) const {
        return a != other.a;
    }

    bool operator < (const B &other) const {
        if (a[2] != other.a[2]) return a[2] < other.a[2];
        if (a[1] != other.a[1]) return a[1] < other.a[1];
        if (a[0] != other.a[0]) return a[0] < other.a[0];
        return false;
    }
};
B operator << (const B &b, int x) {
    if (!x) return b;
    return B((b.a[2] << x) | (b.a[1] >> (-x)), (b.a[1] << x) | (b.a[0] >> (-x)), (b.a[0] << x));
}

struct hash_my {
    size_t operator()(int x) const {
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = (x >> 16) ^ x;
        return x;
    }

    size_t operator()(long long x) const {
        x = (x ^ (x >> 30)) * (0xbf58476d1ce4e5b9ll);
        x = (x ^ (x >> 27)) * (0x94d049bb133111ebll);
        x = x ^ (x >> 31);
        return x;
    }

    size_t operator()(unsigned long long x) const {
        x = (x ^ (x >> 30)) * (0xbf58476d1ce4e5b9ll);
        x = (x ^ (x >> 27)) * (0x94d049bb133111ebll);
        x = x ^ (x >> 31);
        return x;
    }

    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        long long h1 = (*this)(p.first);
        long long h2 = (*this)(p.second);
        return (*this)(h1 ^ (h2 << 32) ^ (h2 >> 32));
    }

    template<typename T, typename U, typename X>
    size_t operator()(const tuple<T, U, X> &p) const {
        long long h1 = (*this)(get<0>(p));
        long long h2 = (*this)(get<1>(p));
        long long h3 = (*this)(get<2>(p));
        return (*this)(h1 ^ (h2 << 22) ^ (h2 >> 22) ^ (h3 << 44) ^ (h3 >> 44));
    }

    size_t operator()(const B &p) const {
        long long h1 = (*this)(p.a[0]);
        long long h2 = (*this)(p.a[1]);
        long long h3 = (*this)(p.a[2]);
        return (*this)(h1 ^ (h2 << 22) ^ (h2 >> 22) ^ (h3 << 44) ^ (h3 >> 44));
    }
};

int calc_min(ll n) {
    B b = 1;
    int s = 0;
    while (n) {
        s += n % 10;
        b |= (b << (n % 10));
        n /= 10;
    }
    for (int i = (s + 1) / 2;; ++i) {
        if (b[i]) {
            return i - (s - i);
        }
    }
}

array<array<ll, 20>, 20> C;
array<array<array<ll, 10>, 37176>, 20> dp;
vector<B> al;
vector<int> lens;

template<typename T, size_t N>
void operator += (array<T, N> &a, const array<T, N> &b) {
    for (int i = 0; i < N; ++i) {
        a[i] += b[i];
    }
}

template<typename T, size_t N>
array<T, N> operator * (array<T, N> a, ll x) {
    for (int i = 0; i < N; ++i) {
        a[i] *= x;
    }
    return a;
}

gp_hash_table<B, int, hash_my> where;

void test_case(int test) {
    ll l, r, k;
    cin >> l >> r >> k;
    auto calc = [&](ll n) {
        vector<int> v;
        {
            ll m = n;
            while (n) {
                v.pb(n % 10);
                n /= 10;
            }
            n = m;
            reverse(v.begin(), v.end());
        }
        B b = 1;
        array<ll, 10> ans; ans.fill(0);

        for (int dif = 0; dif < v.size(); ++dif) {
            int ln = v.size() - dif - 1;
            for (int d = 0; d < v[dif]; ++d) {
                ans += dp[ln][where[b | (b << d)]];
            }
            b |= (b << v[dif]);
        }

        ans[calc_min(n)]++;
        ll tot = 0;
        for (int i = 0; i <= k; ++i)
            tot += ans[i];

        return tot;
    };
    cout << calc(r) - calc(l - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    {
        for (int i = 0; i < C.size(); ++i) {
            C[0][i] = 0;
            C[i][0] = 1;
        }
        for (int i = 1; i < C.size(); ++i)
            for (int j = 1; j < C.size(); ++j)
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    {
        set<B> als;
        const int N = 18;
        auto calc = y_combinator([&](auto calc, B b, int s, int ln, int mn, ll cnt, int last) -> void {
            als.insert(b);
            if (ln != N) {
                calc(b | (b << mn), s + mn, ln + 1, mn, cnt, last + 1);
                for (int a = mn + 1; a < 10; ++a) {
                    calc(b | (b << a), s + a, ln + 1, a, cnt * C[ln][last], 1);
                }
            }
        });
        calc(1, 0, 0, 0, 1, 0);
        for (auto b : als) {
            al.pb(b);
            int s = 170;
            while (!b[s]) --s;
            lens.pb(s);
        }
        for (int i = 0; i < al.size(); ++i)
            where[al[i]] = i;
    }
    mclock;
    {
        for (int mn = 9; mn >= 1; --mn) {
            if (mn == 9)
            for (int i = 0; i < al.size(); ++i) {
                auto b0 = al[i];
                {
                    int s = lens[i];
                    int k = (s + 1) / 2;
                    while (!b0[k]) ++k;
                    dp[0][i].fill(0);
                    dp[0][i][k - (s - k)] = 1;
                }
            }
            for (int ln = 18; ln > 0; --ln) {
                for (int i = 0; i < al.size(); ++i) {
                    if (mn == 9) {
                        auto b = al[i];
                        for (int i = 0; i < ln; ++i) {
                            b |= (b << 9);
                        }
                        auto it = where.find(b);
                        if (it == where.end()) continue;
                        dp[ln][i] = dp[0][it->second];
                        continue;
                    }
                    if (lens[i] + ln * 9 > 18 * 9) break;
                    auto b = al[i];
                    array<ll, 10> cur; cur.fill(0);
                    for (int cnt = 0; cnt <= ln; ++cnt) {
                        auto it = where.find(b);
                        if (it == where.end()) break;
                        int ind = it->second;
                        cur += dp[ln - cnt][ind] * C[ln][cnt];
                        b |= (b << mn);
                    }
                    dp[ln][i] = cur;
                }
            }
        }

        for (int i = 0; i < al.size(); ++i) {
            for (int ln = 18; ln >= 0; --ln) {
                for (int l = ln - 1; l >= 0; --l) {
                    dp[ln][i] += dp[l][i] * C[ln][l];
                }
            }
        }
    }
    mclock;

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}