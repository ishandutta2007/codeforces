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

struct E {
    int chk, type, L;
    E(int chk = 0, int type = 0, int L = 0) :
        chk(chk), type(type), L(L)
    {}
};

vector<vector<E>> evs;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    evs.resize(n);
    for (int i = 0; i < m; i++) {
        int t, L, R;
        cin >> t >> L >> R, L--, R--;
        evs[L].pb(E(t, 1, L));
        evs[R].pb(E(t, 2, L));
    }
    for (auto &el : evs) {
        sort(all(el), [](E &a, E &b) {
            return a.chk > b.chk || (a.chk == b.chk && a.type < b.type);
        });
    }
    bool can = true;
    int el = 100000000;
    int frm = -1, bal = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for (auto el : evs[i]) {
            if (el.chk == 0) {
                if (el.type == 2)
                    can &= (frm > el.L || frm == -1);
            } else if (el.type == 1) {
                if (bal == 0)
                    frm = i;
                bal++;
            } else
                bal--;
        }
        if (bal == 0) {
            ans[i] = el;
            el -= n + 1;
            frm = -1;
        } else
            ans[i] = el++;
    }
    if (!can)
        return cout << "No\n", 0;
    cout << "Yes\n";
    for (auto el : ans)
        cout << el << ' ';
    cout << '\n';
}