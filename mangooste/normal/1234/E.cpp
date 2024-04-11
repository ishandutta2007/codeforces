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
    #define DEBUG

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

int n, m;
vector<int> x;
vector<ll> fenw;

void upd(int pos, int del) {
    for (; pos < n; pos |= pos + 1)
        fenw[pos] += del;
}
void upd(int L, int R, int del) {
    upd(L, del);
    upd(R + 1, -del);
}

ll get(int pos) {
    ll ans = 0;
    for (; pos >= 0; pos &= pos + 1, pos--)
        ans += fenw[pos];
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    x.resize(m);
    for (int &el : x)
        cin >> el, el--;
    fenw.resize(n);
    for (int i = 0; i < m - 1; i++) {
        int a = x[i], b = x[i + 1];
        if (a == b)
            continue;
        if (a > b)
            swap(a, b);
        if (a != 0)
            upd(0, a - 1, b - a);
        upd(a, a, b);
        if (a + 1 <= b - 1)
            upd(a + 1, b - 1, b - a - 1);
        upd(b, b, a + 1);
        if (b != n - 1)
            upd(b + 1, n - 1, b - a);
    }
    for (int i = 0; i < n; i++)
        cout << get(i) << ' ';
    cout << '\n';
}