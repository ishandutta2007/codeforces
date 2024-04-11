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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m, m--;
        cnt[m]++;
    }
    vector<int> c(k);
    for (int &el : c)
        cin >> el;
    vector<vector<int>> ans = {{}};
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            int L = -1, R = ans.size();
            while (R - L > 1) {
                int mid = (L + R) / 2;
                if (ans[mid].size() < c[i])
                    R = mid;
                else
                    L = mid;
            }
            if (R == ans.size())
                ans.push_back({i});
            else {
                ans[R].push_back(i);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.size() << ' ';
        for (auto j : i)
            cout << j + 1 << ' ';
        cout << '\n';
    }
}