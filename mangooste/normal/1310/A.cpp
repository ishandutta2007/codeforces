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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &i : a)
        cin >> i.first;
    for (auto &i : a)
        cin >> i.second;
    sort(all(a));
    multiset<int> need;
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (need.empty() || a[i - 1].first == a[i].first) {
            need.insert(a[i].second);
            sum += a[i].second;
            continue;
        }
        int del = a[i].first - a[i - 1].first;
        if (need.size() < del) {
            int cur = need.size() - 1;
            for (auto j : need) {
                ans += 1LL * cur * j;
                cur--;
            }
            need.clear();
            need.insert(a[i].second);
            sum = a[i].second;
            continue;
        }
        for (int i = 0; i < del; i++) {
            sum -= *(--need.end());
            ans += 1LL * i * (*(--need.end()));
            need.erase(--need.end());
        }
        ans += sum * del;
        need.insert(a[i].second);
        sum += a[i].second;
    }
    if (!need.empty()) {
        int cur = need.size() - 1;
        for (auto j : need) {
            ans += 1LL * cur * j;
            cur--;
        }
    }
    cout << ans << '\n';
}