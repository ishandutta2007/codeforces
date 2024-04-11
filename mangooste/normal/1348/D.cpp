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
    ostream& operator << (ostream& out, pair<A, B>& p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T>
    ostream& operator << (ostream& out, vector<T>& v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream& out, set<T>& st) {
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

#define int long long
#define all(a) a.begin(), a.end()

void print(vector<int> ans) {
    cout << ans.size() << '\n';
    for (auto el : ans)
        cout << el << ' ';
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n0\n";
        return;
    }
    if (n == 3) {
        cout << "1\n1\n";
        return;
    }
    if (n == 4) {
        cout << "2\n0 1\n";
        return;
    }
    vector<int> ans = { 1 };
    int already = 3;
    for (int day = 2;; day++) {
        int maybe = (1LL << day);
        int need = n - already;
        if (need >= maybe * 2) {
            ans.push_back(1LL << day - 1);
            already += maybe;
            continue;
        }
        int num = maybe / 2;
        if (2 * num >= need) {
            ans.push_back(need - num);
            print(ans);
            break;
        }
        if (need % 2 == 0) {
            ans.push_back(need / 2 - num);
            ans.push_back(0);
        } else {
            ans.push_back(need / 2 - num);
            ans.push_back(1);
        }
        print(ans);
        break;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}