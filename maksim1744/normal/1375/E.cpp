/*
    author:  Maksim1744
    created: 04.07.2020 18:54:18
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
    vector<int> a(n);
    cin >> a;
    vector<pair<int, int>> ans;
    auto b = a;
    sort(b.begin(), b.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; ++i) {
        a[i] = lowb(b, a[i]);
    }
    vector<set<int>> poss(b.size());
    for (int i = 0; i < a.size(); ++i) {
        poss[a[i]].insert(i);
    }
    // show(a);
    // show(poss);
    set<int> goodi;
    auto check = [&](int i) {
        if (i < 0 || i + 1 >= poss.size()) return;
        if ((*--poss[i].end()) > *poss[i + 1].begin())
            goodi.insert(i);
        else
            goodi.erase(i);
    };
    for (int i = 0; i < poss.size(); ++i) {
        check(i);
    }
    // show(goodi);
    while (!goodi.empty()) {
        int ind = *goodi.begin();

        int x = *--poss[ind].end();
        int y = *poss[ind + 1].begin();
        poss[ind].erase(x);
        poss[ind + 1].erase(y);
        poss[ind].insert(y);
        poss[ind + 1].insert(x);
        ans.eb(x, y);
        swap(a[x], a[y]);

        auto it = poss[ind].find(y);
        ++it;
        while (it != poss[ind].end()) {
            ans.eb(y, *it);
            ++it;
        }

        it = poss[ind + 1].find(x);
        while (it != poss[ind + 1].begin()) {
            --it;
            ans.eb(x, *it);
        }

        check(ind);
        check(ind - 1);
        check(ind + 1);
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        if (x > y) swap(x, y);
        cout << x + 1 << ' ' << y + 1 << '\n';
    }

    return 0;
}