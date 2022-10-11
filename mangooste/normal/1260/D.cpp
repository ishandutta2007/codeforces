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

int m, n, k, t;
vector<int> a;
vector<array<int, 3>> b;

bool chk(int val) {
    int mn = a[m - val];
    int L = -1, R = k;
    while (R - L > 1) {
        int md = (L + R) / 2;
        if (b[md][2] > mn)
            R = md;
        else
            L = md;
    }
    vector<int> fenw(n + 2, 0);
    int sm = n + 1;
    for (int i = R; i < k; i++)
        fenw[b[i][0]]++, fenw[b[i][1] + 1]--;
    for (int i = 1; i < n + 2; i++) {
        fenw[i] += fenw[i - 1];
        sm += 2 * (fenw[i] != 0);
    }
    return sm <= t;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> m >> n >> k >> t;
    a.resize(m);
    for (int &el : a)
        cin >> el;
    sort(all(a));
    b.resize(k);
    for (auto &el : b)
        cin >> el[0] >> el[1] >> el[2];
    sort(all(b), [](array<int, 3> &a, array<int, 3> &b) {
        return a[2] < b[2];
    });
    int L = 0, R = m + 1;
    while (R - L > 1) {
        int md = (L + R) / 2;
        if (chk(md))
            L = md;
        else
            R = md;
    }
    cout << L << '\n';
}