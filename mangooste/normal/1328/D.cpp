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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        int j = (i - 1 + n) % n;
        if (a[i] == a[j]) {
            pos = i;
            vector<int> tmp;
            for (int k = i; k < n; k++)
                tmp.push_back(a[k]);
            for (int k = 0; k < i; k++)
                tmp.push_back(a[k]);
            a = tmp;
            break;
        }
    }
    if (pos == -1) {
        if (n % 2 == 0) {
            cout << "2\n";
            for (int i = 0; i < n; i++)
                cout << i % 2 + 1 << ' ';
            cout << '\n';
        } else {
            cout << "3\n";
            for (int i = 0; i < n - 1; i++)
                cout << i % 2 + 1 << ' ';
            cout << "3\n";
        }
        return;
    }
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            ans[i] = ans[i - 1];
            continue;
        }
        if (ans[i - 1] == 1)
            ans[i] = 2;
        else
            ans[i] = ans[i - 1] - 1;
    }
    cout << *max_element(all(ans)) << '\n';
    for (int i = n - pos; i < n; i++)
        cout << ans[i] << ' ';
    for (int i = 0; i < n - pos; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}