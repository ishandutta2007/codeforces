/*
    author:  Maksim1744
    created: 19.12.2019 17:55:12
*/

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#include "C:/C++ libs/print.cpp"
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

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    cin >> v;
    for (int i = 0; i < n; ++i) {
        --v[i].first;
        --v[i].second;
    }
    vector<int> who(n * 2, 0);
    for (int i = 0; i < n; ++i) {
        who[v[i].second] = 1;
    }
    vector<int> ends(n * 2, 0);
    vector<int> begs(n * 2, 0);
    for (int i = 0; i < ends.size(); ++i) {
        ends[i] = (who[i] == 1);
        if (i != 0)
            ends[i] += ends[i - 1];
    }
    for (int i = (int)begs.size() - 1; i >= 0; --i) {
        begs[i] = (who[i] == 0);
        if (i + 1 < begs.size())
            begs[i] += begs[i + 1];
    }
    ordered_set<int> st;
    vector<int> with(n * 2);
    for (int i = 0; i < n; ++i) {
        with[v[i].first] = v[i].second;
        with[v[i].second] = v[i].first;
    }

    vector<int> p(n), rk(n, 1);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    function<int(int)> par = [&](int v) {
        if (v == p[v])
            return v;
        p[v] = par(p[v]);
        return p[v];
    };
    auto un = [&](int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v)
            return;
        if (rk[u] > rk[v])
            swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
    };

    vector<int> num(n * 2, 0);
    for (int i = 0; i < n; ++i) {
        num[v[i].first] = i;
        num[v[i].second] = i;
    }

    ll cnt = 0;
    for (int i = 0; i < n * 2; ++i) {
        if (who[i] == 0) {
            // ll c = 0;
            // if (i != 0)
            //     c += ends[i - 1];
            // if (i + 1 != n * 2)
            //     c += begs[i + 1];
            // c = n - 1 - c;
            // cnt += st.order;
            // show(i, c);
            cnt += st.order_of_key(with[i]) - st.order_of_key(i);
            auto it = st.lower_bound(i);
            while (it != st.end() && *it < with[i]) {
                un(num[i], num[*it]);
                ++it;
            }
            if (cnt > n - 1) {
                cout << "NO\n";
                return 0;
            }
        }
        if (with[i] > i)
            st.insert(with[i]);
    }
    // show(who);
    // show(begs, ends);
    // show(cnt);
    if (cnt != (n - 1) || rk[par(0)] != n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}