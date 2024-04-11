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
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    sort(all(a));
    vector<pair<int, int>> b;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        b.emplace_back(a[i], j - i);
        i = j;
    }
    int m = b.size();
    int i = 0, j = m - 1;
    long long ans = b[m - 1].first - b[0].first;
    debug(b);
    while (i != j && k) {
        debug(i, j, k);
        if (b[i].second <= b[j].second) {
            long long max_can = k / b[i].second;
            if (max_can >= b[i + 1].first - b[i].first) {
                k -= 1LL * (b[i + 1].first - b[i].first) * b[i].second;
                b[i + 1].second += b[i].second;
                ans = b[j].first - b[i + 1].first;
                i++;
            } else {
                ans -= max_can;
                k = 0;
            }
        } else {
            long long max_can = k / b[j].second;
            if (max_can >= b[j].first - b[j - 1].first) {
                k -= 1LL * (b[j].first - b[j - 1].first) * b[j].second;
                b[j - 1].second += b[j].second;
                ans = b[j - 1].first - b[i].first;
                j--;
            } else {
                ans -= max_can;
                k = 0;
            }
        }
    }
    cout << ans << '\n';
}