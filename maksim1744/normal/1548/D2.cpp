/*
    author:  Maksim1744
    created: 01.08.2021 18:58:19
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
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

const int N = 6e3 + 20;
array<array<int, N>, N> pregcd;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        pregcd[i].fill(-1);
    }

    ll ans = 0;

    auto solve_even = [&](const vector<pair<ll, ll>> &v) {
        vector<ll> cnt(4);
        // int n = v.size();
        for (auto [x, y] : v) {
            x /= 2;
            y /= 2;
            x = abs(x);
            y = abs(y);

            int rx = x % 2;
            int ry = y % 2;
            cnt[rx * 2 + ry]++;
        }

        ll ans1 = 0;
        for (int i = 0; i < 4; ++i) {
            ans1 += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        }

        ll ans2 = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i != j) {
                    ans2 += cnt[i] * (cnt[i] - 1) / 2 * cnt[j];
                }
            }
        }

        ans += ans1 + ans2;
    };

    auto bord = [&](pair<pair<ll, ll>, int> aa, pair<pair<ll, ll>, int> bb) {
        if (aa.second > bb.second) swap(aa, bb);
        if (pregcd[aa.second][bb.second] == -1) {
            auto &a = aa.first;
            auto &b = bb.first;
            pregcd[aa.second][bb.second] = gcd(abs(a.first - b.first), abs(a.second - b.second));
        }
        return pregcd[aa.second][bb.second];
    };

    auto mid_ar = [&](pair<ll, ll> a, pair<ll, ll> b) {
        return (ll)(b.first - a.first) * (b.second + a.second);
    };
    auto double_ar = [&](pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
        return abs(mid_ar(a, b) + mid_ar(b, c) + mid_ar(c, a));
    };

    map<pair<ll, ll>, vector<pair<pair<ll, ll>, int>>> cnt;
    map<pair<ll, ll>, vector<pair<ll, ll>>> cnt2;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        cnt[{x % 4, y % 4}].eb(mp(x, y), i);
        cnt2[{x % 2, y % 2}].eb(x, y);
    }

    for (auto& [p, v] : cnt2)
        solve_even(v);

    show(cnt);
    show(cnt2);

    show(ans);

    auto is_same2 = [&](pair<ll, ll> a, pair<ll, ll> b) {
        return a.first % 2 == b.first % 2 && a.second % 2 == b.second % 2;
    };

    for (auto& [p1, v1] : cnt) {
        for (auto& [p2, v2] : cnt) {
            if (p2 == p1) break;
            if (!is_same2(p1, p2)) continue;
            for (auto& [p3, v3] : cnt) {
                if (is_same2(p1, p3)) continue;

                ll S2 = double_ar(p1, p2, p3);
                show(S2);
                if (S2 % 2 == 1) continue;
                ll S = S2 / 2;

                show(S);

                int need = (S % 2 == 0 ? 0 : 2);

                for (auto pt3 : v3) {
                    array<ll, 4> c1, c2;
                    c1.fill(0); c2.fill(0);
                    for (auto pt1 : v1)
                        c1[bord(pt1, pt3) % 4]++;
                    for (auto pt2 : v2)
                        c2[bord(pt2, pt3) % 4]++;

                    for (int i = 1; i <= 3; i += 2)
                        for (int j = 1; j <= 3; j += 2)
                            if ((i + j + 2) % 4 == need)
                                ans += c1[i] * c2[j];
                }
            }
        }
    }

    show(ans);

    for (auto& [p1, v1] : cnt) {
        for (auto& [p3, v3] : cnt) {
            if (is_same2(p1, p3)) continue;

            ll S2 = double_ar(p1, p1, p3);
            if (S2 % 2 == 1) continue;
            ll S = S2 / 2;

            int need = (S % 2 == 0 ? 0 : 2);

            for (auto pt3 : v3) {
                array<ll, 4> c1;
                c1.fill(0);

                for (auto pt1 : v1) 
                    c1[bord(pt1, pt3) % 4]++;

                ll cur = 0;

                for (int i = 1; i <= 3; i += 2) {
                    for (int j = 1; j <= 3; j += 2) {
                        if ((i + j) % 4 == need) {
                            if (i != j) cur += c1[i] * c1[j];
                            else cur += c1[i] * (c1[i] - 1) / 2;
                        }
                    }
                }
                assert(cur % 2 == 0);
                show(p1, p3, c1, cur);
                ans += cur / 2;
            }

        }
    }

    show(ans);

    cout << ans << '\n';

    return 0;
}