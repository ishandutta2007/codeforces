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

int n, m, k;
vector<int> p, sc;
vector<char> cool;
vector<int> one;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    p.resize(n);
    for (int &el : p)
        cin >> el;
    one.resize(m);
    sc.resize(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num, num--;
        sc[i] = num;
        one[num] = max(one[num], p[i]);
    }
    cool.resize(n);
    for (int i = 0; i < k; i++) {
        int el;
        cin >> el, el--;
        cool[el] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (cool[i] && p[i] != one[sc[i]]);
    cout << ans << '\n';
}