/*
    author:  Maksim1744
    created: 30.05.2021 17:59:25
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

#ifdef HOUSE
mt19937_64 rng(1928378);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    vector<string> v(n);
    cin >> v;
    string best(m, '0');
    int bestc = 0;
    for (int it = 0; it < 100; ++it) {
        string& s = v[rnd(n)];
        vector<int> bits;
        for (int i = 0; i < m; ++i) {
            if (s[i] == '1')
                bits.pb(i);
        }
        vector<int> cnt(1 << bits.size());
        for (auto &s : v) {
            int res = 0;
            for (int i = 0; i < bits.size(); ++i) {
                if (s[bits[i]] == '1')
                    res |= (1 << i);
            }
            cnt[res]++;
        }
        for (int b = 0; b < bits.size(); ++b)
            for (int i = 0; i < cnt.size(); ++i)
                if ((i >> b) & 1)
                    cnt[i ^ (1 << b)] += cnt[i];
        int need = (n + 1) / 2;
        int besti = -1;
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] < need) continue;
            if (besti == -1 || __builtin_popcount(besti) < __builtin_popcount(i))
                besti = i;
        }
        if (besti != -1 && __builtin_popcount(besti) > bestc) {
            string t(m, '0');
            for (int i = 0; i < bits.size(); ++i)
                if ((besti >> i) & 1)
                    t[bits[i]] = '1';
            bestc = __builtin_popcount(besti);
            best = t;
        }
    }
    cout << best << '\n';

    return 0;
}