/*
    author:  Maksim1744
    created: 24.10.2021 15:28:36
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
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
            show(num);
            prime = sieve.mn[num];
            count = 0;
            while (num != 1 && sieve.mn[num] == prime) {
                show(num, sieve.mn[num]);
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
            mn.resize(n + 1);
            for (int i = 2; i <= n; ++i) {
                if (isp[i]) {
                    mn[i] = i;
                    if ((ll)i * i <= n)
                        for (int j = i * i; j <= n; j += i)
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
    PrimeIteratorContainer get_prime_divs(int k) const {
        return PrimeIteratorContainer(k, *this);
    }

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto [p, c] : v)
            n = n / p * (p - 1);
        return n;
    }
};

const int N = 1e6 + 20;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    Sieve sieve(N, true, true);
    string s;
    cin >> s;

    vector<vector<pair<int, int>>> pos(N);
    vector<vector<int>> tor(N);

    for (int i = 0; i < n; ++i) {
        auto res = sieve.get_prime_divs(a[i]);
        int sign = (s[i] == '*' ? 1 : -1);
        for (auto [p, c] : res) {
            c *= sign;
            pos[p].eb(i, c);
        }
    }

    vector<int> st;
    vector<int> good;
    for (int i = 0; i < pos.size(); ++i) {
        if (pos[i].empty()) continue;
        good.pb(i);
        pos[i].insert(pos[i].begin(), mp(-1, 0));
        for (int j = 1; j < pos[i].size(); ++j)
            pos[i][j].second += pos[i][j - 1].second;
        tor[i].assign(pos[i].size(), pos[i].size());
        st.clear();
        for (int j = pos[i].size() - 1; j >= 0; --j) {
            while (!st.empty() && pos[i][st.back()].second >= pos[i][j].second)
                st.pop_back();
            if (!st.empty())
                tor[i][j] = st.back();
            st.pb(j);
        }
        pos[i].eb(n, -1);
    }

    set<pair<int, int>> cur;

    for (int k : good) {
        cur.emplace(pos[k][tor[k][0]].first, k);
    }
    cur.emplace(n, 1e9);

    ll ans = 0;

    vector<int> ind(N, 0);

    for (int l = 0; l < n; ++l) {
        show(l, cur);
        ans += cur.begin()->first - l;

        auto res = sieve.get_prime_divs(a[l]);
        for (auto [k, c] : res) {
            cur.erase({pos[k][tor[k][ind[k]]].first, k});
            ++ind[k];
            if (ind[k] < tor[k].size())
                cur.insert({pos[k][tor[k][ind[k]]].first, k});
        }
    }
    cout << ans << '\n';

    return 0;
}