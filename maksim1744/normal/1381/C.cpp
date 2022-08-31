/*
    author:  Maksim1744
    created: 21.07.2020 18:08:45
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

void test_case() {
    int n, x, y;
    cin >> n >> x >> y;
    map<int, vector<int>> cnt;
    vector<int> b(n);
    cin >> b;
    if (x == n) {
        cout << "YES\n";
        cout << b << '\n';
        return;
    }
    for (int i = 0; i < b.size(); ++i) {
        cnt[b[i]].pb(i);
    }
    int other = 1;
    while (cnt.count(other)) ++other;
    set<pair<int, int>> scnt;
    for (auto [a, b] : cnt) {
        scnt.emplace(-b.size(), a);
    }
    vector<int> a(n, -1);
    for (int i = 0; i < x; ++i) {
        auto [c, val] = *scnt.begin();
        scnt.erase(scnt.begin());
        c++;
        auto it = cnt.find(val);
        a[it->second.back()] = b[it->second.back()];
        it->second.pop_back();
        if (c != 0)
            scnt.emplace(c, val);
    }
    int k = -scnt.begin()->first;
    y -= x;
    int cany = (n - x) * 2 - k * 2;
    if (cany < y) {
        // show(y, cany, k);
        // show(a);
        // show(scnt);
        cout << "NO\n";
        return;
    }
    vector<pair<int, int>> iinds;
    for (auto [a, t] : cnt) {
        for (auto k : t) {
            iinds.eb(b[k], k);
        }
    }
    sort(iinds.begin(), iinds.end());
    vector<int> inds;
    for (auto [i, o] : iinds) {
        inds.pb(o);
    }
    // show(inds);
    assert(inds.size() == n - x);
    // sort(inds.begin(), inds.end());
    show(a);
    show(b);
    show(inds);
    show(scnt);
    int shift = inds.size() / 2;
    for (int i = 0; i < inds.size(); ++i) {
        a[inds[(i + shift) % inds.size()]] = b[inds[i]];
    }
    int bad = 0;
    for (auto k : inds) {
        if (a[k] == b[k]) {
            a[k] = other;
            ++bad;
        }
    }
    // assert(n - bad >= y);
    int done = inds.size() - bad;
    assert(done >= y);
    for (auto k : inds) {
        if (done == y) break;
        if (a[k] != other) {
            a[k] = other;
            --done;
        }
    }
    assert(done == y);
    cout << "YES\n";
    cout << a << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}