/*
    author:  Maksim1744
    created: 04.09.2022 19:02:24
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

string to_string(__int128 x) {
    if (x == 0) return "0";
    __uint128_t k = x;
    if (k == (((__uint128_t)1) << 127)) return "-170141183460469231731687303715884105728";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream &operator << (ostream &o, __int128 x) {
    return o << to_string(x);
}

istream& operator >> (istream& i, __int128& x) {
    string s;
    i >> s;
    x = 0;
    for (char c : s)
        x = x * 10 + (c - '0');
    return i;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n;
    cin >> n;

    int have = 1;
    vector<vector<int>> vals = {{}, {0}};
    vector<ll> by2s_fast(1e5);
    by2s_fast[0]++;
    vector<ll> pref(1e5);
    while (have < n) {
        vals.eb();
        int k = vals.size() - 1;
        if (k - 3 >= 0) {
            if (k % 2 == 0) {
                pref[1]++;
                pref[k - 1]--;
            } else {
                pref[0]++;
                pref[k - 1]--;
            }
            have += (k - 1 - ((k % 2) ^ 1)) / 2;
        }
        if (have + 3 >= n) {
            for (int i = (k % 2) ^ 1; i <= k - 3; i += 2)  {
                vals.back().pb(i);
                // by2s_fast[i]++;
            }
        }
        if (k >= 2) {
            vals.back().pb(k - 2);
            by2s_fast[k - 2]++;
            ++have;
        }
        // have += vals.back().size();
    }
    for (int i = 2; i < pref.size(); ++i)
        pref[i] += pref[i - 2];
    for (int i = 0; i < pref.size(); ++i) {
        by2s_fast[i] += pref[i];
    }

    reverse(vals.back().begin(), vals.back().end());
    while (have > n) {
        by2s_fast[vals.back().back()]--;
        vals.back().pop_back();
        --have;
    }
    reverse(vals.back().begin(), vals.back().end());

    vector<vector<ll>> by2(vals.size() + 2);

    // vector<pair<ll, ll>> v;
    // for (int i = 0; i < vals.size(); ++i) {
    //     for (int k : vals[i]) {
    //         by2[k].pb(i - k);
    //         // v.eb((1ll << k) * (i - k), i);
    //     }
    // }

    vector<ll> by2s(by2.size());
    by2s_fast.resize(by2s.size());
    by2s = by2s_fast;
    auto by2s0 = by2s;
    // for (int i = 0; i < by2.size(); ++i) {
    //     by2s[i] = by2[i].size();
    // }
    // show(by2s);
    show(by2s_fast);

    for (int i = 1; i < by2s.size(); ++i) {
        by2s[i] += by2s[i - 1];
    }

    #ifdef HOME
    int D = log(vals.size()) / log(2) + 1;
    #else
    const int D = 17;
    #endif
    show(D);
    show(by2);

    // vector<ll> b;
    // for (int i = 0; i < by2.size(); ++i) {
    //     for (int j : by2[i]) {
    //         b.pb(j << i);
    //     }
    // }
    // sort(b.begin(), b.end());
    // cout << b << endl;

    auto que = [&](int pos) {

        auto belowpair = [&](int p2, int x) {
            ll res = 0;
            // {
            //     // return (ll)lowb(b, x << p2);
            //     for (int i = 0; i < by2.size(); ++i) {
            //         for (int j : by2[i]) {
            //             if ((1ll << i) * j < (1ll << p2) * x)
            //                 ++res;
            //         }
            //     }
            //     return res;
            // }
            if (p2 - D >= 0) res += by2s[p2 - D];
            for (int i = max(0, p2 - D + 1); i <= p2 + D && i < by2s.size(); ++i) {
                ll val = x;
                if (i <= p2) val <<= p2 - i;
                else val = (val + (1ll << (i - p2)) - 1) / (1ll << (i - p2));



                // int ind = lowb(by2[i], val);

                int ind = 0;
                if (by2s0[i] >= 1) {
                    int cc = by2s0[i];
                    if (i == 0 && val > 1 && cc >= 1) {
                        ++ind;
                        --cc;
                    }
                    if (cc >= 1 && val > 2) {
                        ++ind;
                        --cc;
                    }
                    if (val > 3) {
                        --val;
                        ind += min((ll)cc, (val + 1) / 2 - 1);
                    }
                }

                res += ind;
            }
            return res;
        };

        auto belowp2 = [&](int p2) {
            return belowpair(p2, 0);
            // ll res = 0;
            // if (p2 - D >= 0) res += by2s[p2 - D];
            // for (int i = max(0, p2 - D + 1); i < p2 && i < by2s.size(); ++i) {
            //     int ind = lowb(by2[i], 1ll << (p2 - i));
            //     res += ind;
            // }
            // return res;
        };

        int L = -1, R = by2s.size();
        while (R - L > 1) {
            int C = (L + R) / 2;
            if (belowp2(C) <= pos)
                L = C;
            else
                R = C;
        }
        ll p2 = max(0, L - D);
        L = -1; R = (1ll << D);
        while (R - L > 1) {
            int C = (L + R) / 2;
            if (belowpair(p2, C) <= pos)
                L = C;
            else
                R = C;
        }
        ll x = L;
        while (x % 2 == 0) {
            x /= 2;
            ++p2;
        }
        // if (x == 1) {
        //     if (p2 == 0) {
        //         return 1;
        //     }
        //     x *= 2;
        //     --p2;
        // }
        return p2 + x;
        // return (1ll << p2) * x;
    };

    // ll s = 0;
    ll tot = 0;
    for (ll s = 1; s < 1e5; ++s) {
        auto bel = [&](ll x) {
            if (x < 0) return -1ll;
            return x / 4;
        };
        ll cnt = bel(min((ll)(n - 1) * 4, (s + 1) * (s + 1) - 2)) - bel(s * s - 2);
        cnt = max(cnt, 0ll);
        if (s < 10)
            show(s, cnt);
        tot += cnt * s;
        // I
    }
    // for (ll i = 0; i < n; ++i) {
    //     while (s * s <= i * 4 + 1)
    //         ++s;

    //     tot += s - 1;
    // }
    cout << tot << '\n';

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << que(k - 1) << '\n';
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << que(i) << ' ';
    // }
    // cout << endl;

    // sort(v.begin(), v.end());
    // for (auto [x, y] : v)
    //     cout << y << ' ';
    // cout << endl;

    // show(vals);

    return 0;
}