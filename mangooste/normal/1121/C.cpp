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

int n, k, m = 0;
vector<int> a;
set<pair<int, int>> cur;
vector<char> cool;

int get() {
    int big = (m * 100000 / n);
    return (big / 1000) % 100 + ((big / 100) % 10 >= 5);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (int &el : a)
        cin >> el;
    cool.resize(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);
    int T = accumulate(all(a), 0);
    int t = 0;
    while (t <= T && !(q.empty() && cur.empty())) {
        if (cur.size() != k && !q.empty()) {
            while (!q.empty() && cur.size() != k) {
                cur.insert({a[q.front()], q.front()});
                q.pop();
            }
            continue;
        }
        t++;
        for (auto i : cur) {
            int cur_test = a[i.second] - i.first + 1;
            if (cur_test == get())
                cool[i.second] = 1;
        }
        while (!cur.empty() && cur.begin()->first == 1) {
            cur.erase(cur.begin());
            m++;
        }
        set<pair<int, int>> nw;
        for (auto i : cur)
            nw.insert({i.first - 1, i.second});
        cur.swap(nw);
        debug(t, cur);
    }
    int ans = 0;
    for (auto i : cool)
        ans += i;
    cout << ans << '\n';
}