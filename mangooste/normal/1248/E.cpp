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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    long long p;
    cin >> n >> p;
    vector<pair<long long, int>> t(n);
    for (auto &i : t)
        cin >> i.first;
    for (int i = 0; i < n; i++)
        t[i].second = i;
    long long cur_time;
    vector<long long> ans(n);
    set<pair<long long, int>> st;
    for (auto i : t)
        st.insert(i);
    queue<int> q;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (q.empty() && s.empty())
            cur_time = st.begin()->first;
        cur_time += p;
        while (!st.empty() && st.begin()->first <= cur_time) {
            if (q.empty() || st.begin()->second < q.back())
                q.push(st.begin()->second);
            else
                s.insert(st.begin()->second);
            st.erase(st.begin());
        }
        ans[q.front()] = cur_time;
        q.pop();
        if (q.empty() && !s.empty()) {
            q.push(*s.begin());
            s.erase(s.begin());
        }
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}