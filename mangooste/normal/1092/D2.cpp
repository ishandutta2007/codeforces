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

int n;
vector<int> a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &el : a)
        cin >> el;
    vector<pair<int, int>> st;
    st.emplace_back(a[0], 1);
    for (int i = 1; i < n; i++) {
        if (a[i] != st.back().first) {
            while (st.size() > 1 && st.back().second % 2 == 0 && st.back().first < a[i]) {
                st[st.size() - 1].second += st[st.size() - 1].second;
                st.pop_back();
            }
            if (st.size() == 1 && st.back().second % 2 == 0 && st.back().first < a[i])
                st.back().first = a[i];
            if (st.back().first < a[i])
                return cout << "NO\n", 0;
            if (st.back().first == a[i])
                st.back().second++;
            else
                st.emplace_back(a[i], 1);
        } else
            st.back().second++;
        debug(st);
        while (st.size() > 1 && st[st.size() - 1].first < st[st.size() - 2].first && st.back().second % 2 == 0) {
            st[st.size() - 2].second += st[st.size() - 1].second;
            st.pop_back();
        }
        debug(st);
    }
    cout << (st.size() == 1 ? "YES\n" : "NO\n");
}