#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    // #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

struct one {
    int x, v, num;

    one(int x = 0, int v = 0, int num = -1) :
        x(x), v(v), num(num)
    {}
};

ostream& operator << (ostream &out, one a) {
    out << '(' << a.x << ' ' << a.v << ' ' << a.num << ')';
    return out;
}

int n;
vector<one> a;
vector<pair<ll, int>> fenw;

pair<ll, int> get(int pos) {
    pair<ll, int> ans = {0, 0};
    for (; pos >= 0; pos &= pos + 1, pos--)
        ans.first += fenw[pos].first, ans.second += fenw[pos].second;
    return ans;
}

pair<ll, int> get(int L, int R) {
    pair<ll, int> a = get(R), b = get(L - 1);
    return {a.first - b.first, a.second - b.second};
}

void upd(int pos, ll del) {
    for (; pos < n; pos |= pos + 1)
        fenw[pos].first += del, fenw[pos].second++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x;
    for (int i = 0; i < n; i++)
        cin >> a[i].v;
    sort(all(a), [](one &a, one &b) {
        return a.v < b.v || a.v == b.v && a.x < b.x;
    });
    debug(a);
    for (int i = 0; i < n; i++)
        a[i].num = i;
    sort(all(a), [](one &a, one &b) {
        return a.x < b.x || a.x == b.x && a.v > b.v;
    });
    debug(a);
    fenw.resize(n);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        pair<ll, int> cur = get(a[i].num, n - 1);
        ans += cur.first - 1LL * cur.second * a[i].x;
        debug(i, cur, ans);
        upd(a[i].num, a[i].x);
    }
    cout << ans << '\n';
}