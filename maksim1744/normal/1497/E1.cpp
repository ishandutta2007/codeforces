/*
    author:  Maksim1744
    created: 17.03.2021 17:59:42
*/

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

struct Sieve {
    vector<bool> isp;
    vector<int> primes;
    vector<short> mn;

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
            for (int i = 2; i * i <= n; ++i)
                if (isp[i])
                    for (int j = i * i; j <= n; j += i)
                        mn[j] = i;
        }
    }

    bool is_prime(int k) const {
        return isp[k];
    }

    bool operator[](int k) const {
        return isp[k];
    }

    vector<pair<int, int>> get_prime_divs(int k) const {
        static vector<int> v;
        v.clear();
        while (k != 1 && !isp[k]) {
            v.pb(mn[k]);
            k /= mn[k];
        }
        if (k != 1)
            v.pb(k);
        sort(v.begin(), v.end());
        vector<pair<int, int>> res;
        for (int k : v) {
            if (res.empty() || k != res.back().first)
                res.eb(k, 0);
            res.back().second++;
        }
        return res;
    }

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto [p, c] : v)
            n = n / p * (p - 1);
        return n;
    }
};

vector<int> pr = Sieve(1e3 * 4, true, false).primes;

void test_case(int test) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    cin >> a;
    set<int> cur;
    int ans = 1;
    for (int k : a) {
        for (int p : pr) {
            while (k % p == 0)
                k /= p;
        }
        if (cur.count(k)) {
            ++ans;
            cur.clear();
        }
        show(k);
        cur.insert(k);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < pr.size(); ++i) {
        pr[i] *= pr[i];
    }

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}