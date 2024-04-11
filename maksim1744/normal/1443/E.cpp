/*
    author:  Maksim1744
    created: 28.01.2021 15:49:56
*/

#include "bits/stdc++.h"

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

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
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<ll> fact(20, 1);
    for (int i = 2; i < fact.size(); ++i)
        fact[i] = fact[i - 1] * i;

    auto get_perm = [&](int n, ll x) {
        vector<int> res(n);
        ordered_set<int> s;
        --x;
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }

        for (int i = 0; i < n; ++i) {
            show(i, x, res);
            if (i == n - 1) {
                assert(x == 0);
                assert(s.size() == 1);
                res[i] = *s.begin();
                break;
            }
            ll full = x / fact[n - 1 - i];
            res[i] = *s.find_by_order(full);
            s.erase(res[i]);
            x -= full * fact[n - 1 - i];
        }
        return res;
    };

    int n, q;
    cin >> n >> q;
    ll x = 1;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            ll l, r;
            cin >> l >> r;
            --l; --r;
            ll ans = r - l + 1;
            while (r >= l && r >= n - 15) {
                ans += p[r];
                --r;
            }
            if (l <= r) {
                ans += r * (r + 1) / 2 - l * (l - 1) / 2;
            }
            cout << ans << '\n';
        } else {
            int s;
            cin >> s;
            x += s;
            auto p2 = get_perm(min(15, n), x);
            for (int i = 0; i < p2.size(); ++i) {
                p[n - p2.size() + i] = p2[i] + p.size() - p2.size();
            }
            show(x, p);
        }
    }

    return 0;
}