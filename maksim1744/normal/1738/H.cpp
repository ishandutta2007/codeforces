/*
    author:  Maksim1744
    created: 30.09.2022 19:11:43
*/

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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

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

    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        long long h1 = (*this)(p.first);
        long long h2 = (*this)(p.second);
        return (*this)(h1 ^ (h2 << 32) ^ (h2 >> 32));
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int q;
    cin >> q;
    vector<pair<int, char>> v(q);

    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        if (s == "pop") {
            v[i].first = -1;
        } else {
            char c;
            cin >> c;
            v[i] = mp(1, c);
        }
    }

    string s;
    for (int i = 0; i < q; ++i) {
        if (v[i].first == 1)
            s.pb(v[i].second);
    }
    int n = s.size();
    vector<int> add_len(n), del_len(n);

    int l = 0, r = -1;
    for (int i = 0; i < q; ++i) {
        if (v[i].first == 1) {
            ++r;
            add_len[r] = r - l + 1;
        } else {
            del_len[l] = r - l + 1;
            ++l;
        }
    }

    string t(s.size() * 2 - 1, '-');
    for (int i = 0; i < s.size(); ++i) {
        t[i * 2] = s[i];
    }

    auto man = manacher_odd(t);
    vector<int> add_pal(n);
    vector<int> del_pal(n);

    {
        vector<pair<int, int>> ad, dl;
        for (int i = 0; i < t.size(); ++i) {
            ad.eb(i, i);
            dl.eb(i + man[i], i);
        }

        sort(dl.begin(), dl.end());

        set<int> cur;

        int iad = 0, idl = 0;


        for (int i = 0; i < t.size(); ++i) {
            while (iad < ad.size() && ad[iad].first <= i) {
                cur.insert(ad[iad].second);
                ++iad;
            }
            while (idl < dl.size() && dl[idl].first <= i) {
                cur.erase(dl[idl].second);
                ++idl;
            }

            if (i % 2 == 0) {
                auto it = cur.lower_bound(i - add_len[i / 2] + 1);
                if (it != cur.end()) {
                    int x = *it;
                    add_pal[i / 2] = i - x + 1;
                }
            }
        }
    }
    {
        reverse(man.begin(), man.end());
        reverse(t.begin(), t.end());
        reverse(del_len.begin(), del_len.end());

        vector<pair<int, int>> ad, dl;
        for (int i = 0; i < t.size(); ++i) {
            ad.eb(i, i);
            dl.eb(i + man[i], i);
        }

        sort(dl.begin(), dl.end());

        set<int> cur;

        int iad = 0, idl = 0;

        for (int i = 0; i < t.size(); ++i) {
            while (iad < ad.size() && ad[iad].first <= i) {
                cur.insert(ad[iad].second);
                ++iad;
            }
            while (idl < dl.size() && dl[idl].first <= i) {
                cur.erase(dl[idl].second);
                ++idl;
            }

            if (i % 2 == 0) {
                auto it = cur.lower_bound(i - del_len[i / 2] + 1);
                if (it != cur.end()) {
                    int x = *it;
                    del_pal[i / 2] = i - x + 1;
                }
            }
        }

        reverse(del_len.begin(), del_len.end());
        reverse(del_pal.begin(), del_pal.end());
    }

    show(s);
    show(add_len);
    show(add_pal);
    show(del_len);
    show(del_pal);

    const int mod1 = 1e9 + 7;
    const int p1 = rnd(1e3, mod1 - 1e3);
    const int mod2 = 998244353;
    const int p2 = rnd(1e3, mod2 - 1e3);

    vector<int> degp1(n + 20, 1);
    for (int i = 1; i < degp1.size(); ++i)
        degp1[i] = degp1[i - 1] * 1ll * p1 % mod1;
    vector<int> degp2(n + 20, 1);
    for (int i = 1; i < degp2.size(); ++i)
        degp2[i] = degp2[i - 1] * 1ll * p2 % mod2;

    vector<int> h1(n), h2(n);
    h1[0] = h2[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; ++i) {
        h1[i] = (h1[i - 1] * 1ll * p1 + s[i] - 'a' + 1) % mod1;
        h2[i] = (h2[i - 1] * 1ll * p2 + s[i] - 'a' + 1) % mod2;
    }

    auto geth = [&](int l, int r) -> pair<int, int> {
        int H1 = h1[r];
        int H2 = h2[r];
        if (l != 0) {
            H1 = (H1 - h1[l - 1] * 1ll * degp1[r - l + 1] % mod1 + mod1) % mod1;
            H2 = (H2 - h2[l - 1] * 1ll * degp2[r - l + 1] % mod2 + mod2) % mod2;
        }
        return {H1, H2};
    };
    // auto geth = [&](int l, int r) {
    //     return s.substr(l, r - l + 1);
    // };


    l = 0; r = -1;
    gp_hash_table<pair<int, int>, int, hash_my> cnt;
    for (auto [op, _] : v) {
        show(l, r);
        show(op);
        show(cnt);
        if (op == 1) {
            ++r;
            cnt[geth(r - add_pal[r] + 1, r)]++;
        } else {
            auto val = geth(l, l + del_pal[l] - 1);
            ++l;
            show(val);
            auto it = cnt.find(val);
            assert(it != cnt.end());
            it->second--;
            if (it->second == 0) {
                cnt.erase(it->first);
            }
        }
        cout << cnt.size() << '\n';
    }

    return 0;
}