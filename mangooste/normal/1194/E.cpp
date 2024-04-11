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

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #define DEBUG

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const int M = 5001 * 2;

struct seg {
    int L, R, val;
    seg(int L = 0, int R = 0, int val = 0) :
        L(L), R(R), val(val)
    {}
};

vector<int> fen;

void upd(int pos, int del) {
    for (; pos < M; pos |= pos + 1)
        fen[pos] += del;
}

int get(int pos) {
    int cur = 0;
    for (; pos >= 0; pos &= pos + 1, pos--)
        cur += fen[pos];
    return cur;
}

int get(int L, int R) {
    return get(R) - get(L - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<seg> X, Y;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += M / 2, y1 += M / 2, x2 += M / 2, y2 += M / 2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        if (x1 == x2)
            Y.pb(seg(y1, y2, x1));
        else
            X.pb(seg(x1, x2, y1));
    }
    sort(all(X), [](seg &a, seg &b) {
        return a.val < b.val;
    });
    sort(all(Y), [](seg &a, seg &b) {
        return a.L < b.L;
    });
    int pos_y = 0;
    ll ans = 0;
    vector<seg> maybe;
    fen.resize(M);
    for (int i = 0; i < X.size(); i++) {
        while (pos_y < Y.size() && Y[pos_y].L <= X[i].val)
            maybe.pb(Y[pos_y++]);
        sort(all(maybe), [](seg &a, seg &b) {
            return a.R < b.R;
        });
        fill(all(fen), 0);
        for (auto el : maybe)
            upd(el.val, 1);
        int pos = 0;
        for (int j = i + 1; j < X.size(); j++) {
            while (pos < maybe.size() && maybe[pos].R < X[j].val) {
                upd(maybe[pos].val, -1);
                pos++;
            }
            int L = max(X[i].L, X[j].L), R = min(X[i].R, X[j].R);
            if (R > L) {
                int cur = get(L, R);
                ans += 1ll * cur * (cur - 1) / 2;
            }
        }
    }
    cout << ans << '\n';
}