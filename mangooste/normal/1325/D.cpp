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
    long long X, S;
    cin >> X >> S;
    if (X > S || X % 2 != S % 2)
        return cout << "-1\n", 0;
    if (S == 0)
        return cout << "0\n", 0;
    if (S == X)
        return cout << "1\n" << S << '\n', 0;
    if ((((S - X) / 2) ^ ((X ^ (S - X) / 2))) == X && (S - X) / 2 + (X ^ (S - X) / 2) == S) {
        cout << "2\n";
        cout << (S - X) / 2 << ' ' << (X ^ (S - X) / 2) << '\n';
        return 0;
    }
    cout << "3\n";
    cout << (S - X) / 2 << ' '  << (S - X) / 2 << ' ' << X << '\n';
}