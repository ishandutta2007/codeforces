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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll x = 0;
    const ll Max = (1ll << 32) - 1;
    vector<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "add") {
            if (st.empty()) {
                x++;
                if (x > Max)
                    return cout << "OVERFLOW!!!\n", 0;
            } else {
                if (st.back().second == -1)
                    return cout << "OVERFLOW!!!\n", 0;
                x += st.back().second;
                if (x > Max)
                    return cout << "OVERFLOW!!!\n", 0;
            }
        } else if (op == "end")
            st.pop_back();
        else if (op == "for") {
            ll val;
            cin >> val;
            if (st.empty())
                st.eb(val, val);
            else if (st.back().second == -1 || st.back().second * val > Max)
                st.eb(val, -1);
            else
                st.eb(val, st.back().second * val);
        }
    }
    cout << x << '\n';
}