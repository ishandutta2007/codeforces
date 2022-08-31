/*
    author:  Maksim1744
    created: 26.04.2019 10:26:14
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, pair<int, int>>> f(n);
    vector<pair<pair<int, int>, int>> p(m);
    for (int i = 0; i < n; ++i) {
        cin >> f[i].first.first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i].second.first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i].first.second;
        f[i].second.second = f[i].first.second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i].first.first;
        p[i].second = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i].first.second;
    }
    p.eb(mp(-1, 0), m);
    p.eb(mp(1e9+5, 0), m + 1);
    m += 2;
    sort(p.begin(), p.end());
    sort(f.begin(), f.end());
    vector<vector<int>> add(m), del(m);
    vector<int> px(m);
    for (int i = 0; i < m; ++i) {
        px[i] = p[i].first.first;
    }
    for (int i = 0; i < n; ++i) {
        add[lowb(px, f[i].first.first)].pb(i);
        del[lowb(px, f[i].second.first + 1)].pb(i);
    }
    // show("here");
    auto rotate = [](pair<int, int>& p) {
        p = {p.first - p.second, p.first + p.second};
    };
    // show(add, del);
    // show(p, f);
    for (int i = 0; i < m; ++i) {
        rotate(p[i].first);
    }
    for (int i = 0; i < n; ++i) {
        rotate(f[i].first);
        rotate(f[i].second);
    }
    // show(p, f);
    vector<int> vx, vy;
    for (int i = 0; i < m; ++i) {
        vx.pb(p[i].first.first);
        vy.pb(p[i].first.second);
    }
    for (int i = 0; i < n; ++i) {
        vx.pb(f[i].first.first);
        vx.pb(f[i].second.first);
        vy.pb(f[i].first.second);
        vy.pb(f[i].second.second);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    auto compress = [&](pair<int, int>& p) {
        p.first = lowb(vx, p.first);
        p.second = lowb(vy, p.second);
    };
    for (int i = 0; i < m; ++i) {
        compress(p[i].first);
    }
    for (int i = 0; i < n; ++i) {
        compress(f[i].first);
        compress(f[i].second);
    }
    vector<int> ans(m, 0);

    int k = 500;
    #ifdef TAG_LENGTH
    k = 2;
    #endif

    // show(f, add, del);
    vector<pair<pair<int, int>, int>> ff(n);
    for (int i = 0; i < n; ++i) {
        ff[i] = {f[i].first, i};
    }
    sort(ff.begin(), ff.end());
    vector<int> ffto(n);
    for (int i = 0; i < n; ++i) {
        ffto[ff[i].second] = i;
        // f[i] = ff[i].first;
    }
    for (int i = 0; i < m; ++i) {
        for (auto& k : add[i]) {
            k = ffto[k];
        }
        for (auto& k : del[i]) {
            k = ffto[k];
        }
    }

    show(p, ff, add, del);

    int inf = 1e7;
    vector<int> al(f.size(), inf);
    vector<vector<int>> blocks((f.size() + k - 1) / k, vector<int>(k, inf));

    for (int i = 0; i < m; ++i) {
        for (auto j : add[i]) {
            al[j] = ff[j].first.second;
            assert(blocks[j / k].back() == inf);
            blocks[j / k].pop_back();
            blocks[j / k].insert(blocks[j / k].begin() + lowb(blocks[j / k], ff[j].first.second), ff[j].first.second);
        }
        for (auto j : del[i]) {
            al[j] = inf;
            int ind = lowb(blocks[j / k], ff[j].first.second);
            assert(blocks[j / k][ind] == ff[j].first.second);
            blocks[j / k].erase(blocks[j / k].begin() + ind);
            blocks[j / k].pb(inf);
        }
        int ind = uppb(ff, mp(p[i].first, inf));
        showt(i, blocks, al, ind, ff, p[i]);
        int sm = 0;
        for (int j = 0; j < ind / k; ++j) {
            int i1 = uppb(blocks[j], p[i].first.second);
            // show(blocks[i], p[i].first.second, i1);
            sm += i1;
        }
        show(sm);
        for (int j = ind / k * k; j < ind; ++j) {
            sm += (al[j] <= p[i].first.second);
        }
        show(sm);
        ans[p[i].second] = sm;
    }

    for (int i = 0; i < m - 2; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}