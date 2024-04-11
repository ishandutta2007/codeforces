/*
    author:  Maksim1744
    created: 30.09.2020 17:51:56
*/

#include <bits/stdc++.h>

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
const int N = 15;
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
const int N = 1e6 + 20;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    cin >> p;
    vector<pair<int, int>> light(m);
    cin >> light;
    {
        sort(light.begin(), light.end());
        vector<pair<int, int>> tmp;
        for (auto [x, y] : light) {
            while (!tmp.empty() && tmp.back().second <= y) tmp.pop_back();
            tmp.eb(x, y);
        }
        swap(light, tmp);
    }

    multiset<int> ms;

    // vector<ll> dif(N + 1, 0);

    show(light);

    // sort(p.begin(), p.end());
    vector<vector<pair<pair<int, int>, int>>> mxs(p.size());
    int ind = -1;
    for (auto [a, b] : p) {
        ++ind;
        auto add = [&](int l, int r, int val) {
            l = max(l, 0);
            r = min(r, N - 1);
            if (l > r) return;
            mxs[ind].eb(mp(l, r), val);
            // dif[l] += val;
            // dif[r + 1] -= val;
        };
        int l = 0;
        for (int i = 0; i < light.size(); ++i) {
            int r = light[i].first;
            int val = max(0, light[i].second + 1 - b);
            add(l - a, r - a, val);
            l = light[i].first + 1;
        }
        add(l - a, N + 20, 0);
        show(mxs[ind]);
    }

    show(mxs);

    int ans = 1e9;
    int L = 0;
    set<pair<int, int>> s;
    vector<int> ptr(mxs.size(), 1);
    for (int i = 0; i < p.size(); ++i) {
        if (!mxs[i].empty()) {
            if (mxs[i].size() > 1)
                s.emplace(mxs[i][1].first.first, i);
            ms.insert(mxs[i][0].second);
        }
    }

    ans = *prev(ms.end());
    ms.insert(0);
    show(ans);

    while (!s.empty()) {
        shows;
        show(L, s, ms);
        show(ptr);
        auto [l, i] = *s.begin();
        L = mxs[i][ptr[i]].first.first;
        show(L);
        show(l, i);
        s.erase(s.begin());
        ms.erase(ms.find(mxs[i][ptr[i] - 1].second));
        // if (ptr[i] < mxs[i].size()) {
        show(i, ptr[i], mxs[i]);
        ms.insert(mxs[i][ptr[i]].second);
        ans = min(ans, L + *prev(ms.end()));
        show(ans);
        ++ptr[i];
        if (ptr[i] < mxs[i].size()) {
            s.emplace(mxs[i][ptr[i]].first.first, i);
        }
        // }
    }
    cout << ans << '\n';

    // // ll ans = 0;
    // // ll cur = 0;
    // // show(dif);
    // // vector<ll> total(N, 0);;
    // // total[0] = dif[0];
    // // for (int i = 1; i < total.size(); ++i)
    // //     total[i] = total[i - 1] + dif[i];
    // // show(total);
    // // for (int i = 0; i < dif.size(); ++i) {
    // //     ans = min(ans, total[i] + i);
    // // }
    // // cout << ans << '\n';

    return 0;
}