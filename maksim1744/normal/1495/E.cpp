/*
    author:  Maksim1744
    created: 10.03.2021 16:47:29
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

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> t(n);
    {
        int m;
        cin >> m;
        vector<int> p(m), k(m), b(m), w(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i] >> k[i] >> b[i] >> w[i];
        }
        for (int i = 0; i < m; ++i) {
            ll seed = b[i];
            ll base = w[i];
            auto rn = [&]() {
                ll ret = seed;
                seed = (seed * base + 233) % mod;
                return ret;
            };
            for (int j = (i == 0 ? 0ll : p[i - 1]) + 1; j <= p[i]; ++j) {
                t[j - 1] = (rn() % 2) + 1;
                a[j - 1] = (rn() % k[i]) + 1;
            }
        }
    }
    if (t[0] == 2) {
        for (int i = 0; i < n; ++i) {
            t[i] = 3 - t[i];
        }
    }

    show(a);
    show(t);

    auto calc = [&]() {
        vector<int> res(n, 0);
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == 1) {
                s1 += a[i];
            } else {
                s2 += a[i];
            }
        }
        show(s1, s2);
        if (s1 == s2) {
            res = a;
            return res;
        }
        vector<ll> sms(n, 0);
        bool sw = false;
        int fr = 0;
        // show(a);
        // show(t);
        if (s1 < s2) {
            sw = true;
            for (int i = 0; i < n; ++i) {
                if (t[i] == 2) {
                    fr = i;
                    break;
                }
            }
            a[0]--;
            vector<char> tt;
            vector<int> aa;
            for (int i = 0; i < n; ++i) {
                tt.pb(t[(i + fr) % n]);
                aa.pb(a[(i + fr) % n]);
            }
            // show(fr);
            swap(t, tt);
            swap(a, aa);
            for (int i = 0; i < n; ++i) {
                t[i] = 3 - t[i];
            }
        }

        show(a);
        show(t);

        if (true) {
            vector<pair<int, ll>> v;
            for (int i = 0; i < n; ++i) {
                if (v.empty() || t[v.back().first] != t[i])
                    v.eb(i, 0);
                v.back().second += a[i];
            }
            // show(v);
            sms[0]++;
            v[0].second--;
            auto ad = [&](pair<int, ll> p) {
                if (v.empty() || t[v.back().first] != t[p.first]) {
                    v.pb(p);
                    return;
                }
                v.back().second += p.second;
            };
            if (v[0].second == 0) {
                v.erase(v.begin());
            } else {
                auto x = v[0];
                // v.pb(v[0]);
                v.erase(v.begin());
                ad(x);
            }
            show(v);
            while (v.size() > 1) {
                show(v);
                if (t[v[0].first] == 1) {
                    auto x = v[0];
                    v.erase(v.begin());
                    ad(x);
                }
                pair<int, ll> tmp = {-1, -1};
                if (t[v.back().first] == 2) {
                    tmp = v.back();
                    v.pop_back();
                }
                if (v.size() < 2) {
                    show(v, tmp);
                    if (tmp.first != -1)
                        show(t[tmp.first]);
                    show(t[v[0].first]);
                    assert(false);
                }
                if (v[v.size() - 2].second == v[v.size() - 1].second) {
                    ll x = v[v.size() - 2].second;
                    sms[v[v.size() - 1].first] += x;
                    sms[v[v.size() - 2].first] += x;
                    v.pop_back();
                    v.pop_back();
                } else if (v[v.size() - 2].second < v[v.size() - 1].second) {
                    ll x = v[v.size() - 2].second;
                    sms[v[v.size() - 1].first] += x;
                    sms[v[v.size() - 2].first] += x;
                    auto u = v.back();
                    v.pop_back();
                    v.pop_back();
                    u.second -= x;
                    ad(u);
                } else {
                    ll x = v[v.size() - 1].second;
                    sms[v[v.size() - 1].first] += x;
                    sms[v[v.size() - 2].first] += x;
                    v.pop_back();
                    v.back().second -= x;
                }
                if (tmp.first != -1)
                    ad(tmp);
            }

        }

        show(sms);

        if (sw) {
            vector<ll> smss;
            vector<char> tt;
            vector<int> aa;
            for (int i = 0; i < n; ++i) {
                tt.pb(t[(i - fr + n) % n]);
                aa.pb(a[(i - fr + n) % n]);
                smss.pb(sms[(i - fr + n) % n]);
            }
            swap(t, tt);
            swap(a, aa);
            swap(sms, smss);
            for (int i = 0; i < n; ++i) {
                t[i] = 3 - t[i];
            }
            sms[0]++;
            a[0]++;
        }

        show(sms);

        vector<ll> have(3, 0);
        for (int i = 0; i < n * 2 + 5; ++i) {
            sms[i % n] += have[t[i % n]];
            ll v = min(sms[i % n], (ll)a[i % n] - res[i % n]);
            res[i % n] += v;
            have[t[i % n]] = sms[i % n] - v;
            sms[i % n] = 0;
        }

        return res;
    };

    auto r = calc();
    show(r);
    ll res = 1;
    for (ll i = 1; i <= n; ++i) {
        ll ans = r[i - 1];
        ans ^= (i * i);
        ans += 1;
        ans %= mod;
        res = res * ans % mod;
    }
    cout << res << '\n';

    return 0;
}