/*
    author:  Maksim1744
    created: 03.06.2022 19:20:35
*/

#include "bits/stdc++.h"

using namespace std;

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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

struct Sieve {
    struct PrimeIterator {
        int prime;
        int count;
        int num;
        const Sieve& sieve;

        PrimeIterator(int num, const Sieve& sieve) : num(num), sieve(sieve) {
            step();
        }

        void step() {
            prime = sieve.mn[num];
            count = 0;
            while (num != 1 && sieve.mn[num] == prime) {
                num /= sieve.mn[num];
                ++count;
            }
        }

        bool operator == (const PrimeIterator& other) const {
            return tie(prime, count, num) == tie(other.prime, other.count, other.num);
        }
        bool operator != (const PrimeIterator& other) const {
            return !(*this == other);
        }

        PrimeIterator& operator ++ () {
            step();
            return *this;
        }

        pair<int, int> operator * () const {
            return {prime, count};
        }
    };

    struct PrimeIteratorContainer {
        int num;
        const Sieve& sieve;
        using iterator = PrimeIterator;

        PrimeIteratorContainer(int num, const Sieve& sieve) : num(num), sieve(sieve) {}

        PrimeIterator begin() const {
            return PrimeIterator(num, sieve);
        }

        PrimeIterator end() const {
            return PrimeIterator(1, sieve);
        }

        vector<pair<int, int>> collect() const {
            vector<pair<int, int>> result;
            for (auto p : *this)
                result.push_back(p);
            return result;
        }
    };

    template<typename U, typename V>
    struct DoubleIterator {
        U u;
        V v;
        U::iterator uit;
        V::iterator vit;
        int prime;
        int count;

        DoubleIterator(const U& u, const V& v, U::iterator uit, V::iterator vit) : u(u), v(v), uit(uit), vit(vit) {
            tie(prime, count) = this->operator*();
        }

        DoubleIterator& operator ++ () {
            if (uit == u.end()) {
                ++vit;
            } else if (vit == v.end()) {
                ++uit;
            } else if ((*uit).first < (*vit).first) {
                ++uit;
            } else if ((*uit).first > (*vit).first) {
                ++vit;
            } else {
                ++uit;
                ++vit;
            }
            return *this;
        }

        bool operator == (const DoubleIterator& other) const {
            return tie(uit, vit) == tie(other.uit, other.vit);
        }
        bool operator != (const DoubleIterator& other) const {
            return !(*this == other);
        }

        pair<int, int> operator * () const {
            if (uit == u.end()) return *vit;
            if (vit == v.end()) return *uit;
            if ((*uit).first < (*vit).first) return *uit;
            if ((*uit).first > (*vit).first) return *vit;
            return {(*uit).first, (*uit).second + (*vit).second};
        }
    };

    template<typename U, typename V>
    struct DoubleIteratorContainer {
        using iterator = DoubleIterator<U, V>;
        U u;
        V v;

        DoubleIteratorContainer(const U& u, const V& v) : u(u), v(v) {}

        iterator begin() const {
            return iterator(u, v, u.begin(), v.begin());
        }

        iterator end() const {
            return iterator(u, v, u.end(), v.end());
        }

        vector<pair<int, int>> collect() const {
            vector<pair<int, int>> result;
            for (auto p : *this)
                result.push_back(p);
            return result;
        }
    };

    vector<bool> isp;
    vector<int> primes;
    vector<int> mn;

    Sieve(int n, bool gen_primes = false, bool gen_mn = false) {
        isp.assign(n + 1, true); isp[0] = isp[1] = false;
        for (int i = 2; i * i <= n; ++i)
            if (isp[i])
                for (int j = i * i; j <= n; j += i)
                    isp[j] = false;

        if (gen_primes)
            for (int i = 2; i <= n; ++i)
                if (isp[i])
                    primes.push_back(i);

        if (gen_mn) {
            mn.assign(n + 1, -1);
            for (int i = 2; i <= n; ++i) {
                if (isp[i]) {
                    mn[i] = i;
                    if ((ll)i * i <= n)
                        for (int j = i * i; j <= n; j += i)
                            if (mn[j] == -1)
                                mn[j] = i;
                }
            }
        }
    }

    bool is_prime(int k) const {
        return isp[k];
    }

    bool operator[](int k) const {
        return isp[k];
    }

    // can be used as vector<pair<int, int>>, as in function phi() below
    // except doesn't create a vector to avoid heap allocations
    // can be transformed into vector<pair<int, int>> with .collect()
    auto get_prime_divs(int p) const {
        return PrimeIteratorContainer(p, *this);
    }

    // if you want to get prime divs for n = a * b * c where max(a, b, c) < size(sieve), then call get_prime_divs(a, b, c)
    template<typename... Args>
    auto get_prime_divs(int p, Args... args) const {
        return DoubleIteratorContainer(PrimeIteratorContainer(p, *this), get_prime_divs(args...));
    }

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto [p, c] : v)
            n = n / p * (p - 1);
        return n;
    }
};

Sieve sieve(1e6 + 20, false, true);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<int> primes;
    for (auto [p, c] : sieve.get_prime_divs(a[0]))
        primes.pb(p);
    for (auto [p, c] : sieve.get_prime_divs(a[1]))
        primes.pb(p);
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());

    vector<int> inds = {0, 1};

    const int inf = 1e9;
    for (int p : primes) {
        array<pair<int, int>, 2> mn = {make_pair(inf, inf), make_pair(inf, inf)};
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            int k = a[i];
            while (k % p == 0) {
                k /= p;
                ++cur;
            }
            pair<int, int> pr = {cur, i};
            for (auto& x : mn)
                if (pr < x)
                    swap(pr, x);
        }
        inds.pb(mn[0].second);
        inds.pb(mn[1].second);
    }
    sort(inds.begin(), inds.end());
    inds.erase(unique(inds.begin(), inds.end()), inds.end());

    auto get_ans = [&](const vector<int>& inds) {
        ll g = 0;
        for (int i = 0; i < inds.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                g = gcd(g, a[inds[i]] * a[inds[j]]);
            }
        }
        return g;
    };

    while (true) {
        bool ok = false;
        for (int i = 0; i < inds.size(); ++i) {
            auto u = inds;
            u.erase(u.begin() + i);
            if (get_ans(u) == get_ans(inds)) {
                inds.erase(inds.begin() + i);
                ok = true;
                break;
            }
        }
        if (!ok) break;
    }

    vector<int> mins;
    for (int p : primes) {
        array<pair<int, int>, 2> mn = {make_pair(inf, inf), make_pair(inf, inf)};
        for (int i : inds) {
            int cur = 0;
            int k = a[i];
            while (k % p == 0) {
                k /= p;
                ++cur;
            }
            pair<int, int> pr = {cur, i};
            for (auto& x : mn)
                if (pr < x)
                    swap(pr, x);
        }
        if (mn[1].first == mn[0].first) continue;
        mins.pb(mn[0].second);
    }

    sort(mins.begin(), mins.end());
    mins.erase(unique(mins.begin(), mins.end()), mins.end());

    auto make_gcd = [&](vector<int> inds) {
        auto get_gcd = [&](const vector<int>& i) {
            ll g = 0;
            for (int j : i)
                g = gcd(g, a[j]);
            return g;
        };

        while (true) {
            bool ok = false;
            for (int i = 0; i < inds.size(); ++i) {
                auto u = inds;
                u.erase(u.begin() + i);
                if (get_gcd(u) == get_gcd(inds)) {
                    inds.erase(inds.begin() + i);
                    ok = true;
                    break;
                }
            }
            if (!ok) break;
        }

        vector<pair<int, vector<int>>> res;
        for (int i = 1; i < (1 << inds.size()); ++i) {
            res.eb();
            res.back().first = (__builtin_popcount(i) + 1) % 2;
            for (int j = 0; j < inds.size(); ++j) {
                if ((i >> j) & 1)
                    res.back().second.pb(inds[j]);
            }
        }
        return res;
    };

    show(inds);
    show(mins);

    int balance = 0;
    vector<pair<int, vector<int>>> total;
    for (int k : mins) {
        vector<int> v;
        for (int u : inds)
            if (u != k)
                v.pb(u);

        auto res = make_gcd(v);
        for (auto p : res) {
            total.pb(p);
            if (p.first == 0)
                ++balance;
            else
                --balance;
        }
    }

    balance -= 2;

    auto rr = make_gcd(inds);
    for (int i = 0; i < abs(balance); ++i) {
        for (auto p : rr) {
            if (balance > 0) {
                p.first ^= 1;
            }
            total.pb(p);
        }
    }

    cout << total.size() << '\n';
    for (auto p : total) {
        ++p.second;
        cout << p.first << ' ' << p.second.size() << ' ' << p.second << '\n';
    }

    return 0;
}