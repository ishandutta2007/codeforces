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

int n;
string s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> s;
    while (true) {
        vector<vector<int>> cur(26);
        for (int i = 0; i < s.size(); i++)
            for (int d = -1; d <= 1; d += 2) {
                int j = i + d;
                if (j < 0 || j >= n)
                    continue;
                if (s[i] == s[j] + 1) {
                    cur[s[i] - 'a'].push_back(i);
                    break;
                }
            }
        bool was = false;
        for (int i = 25; i >= 0; i--) {
            if (!cur[i].size())
                continue;
            string t = "";
            for (int j = 0; j < cur[i][0]; j++)
                t.push_back(s[j]);
            for (int j = 1; j < cur[i].size(); j++) {
                for (int z = cur[i][j - 1] + 1; z < cur[i][j]; z++)
                    t.push_back(s[z]);
            }
            for (int j = cur[i].back() + 1; j < s.size(); j++)
                t.push_back(s[j]);
            s = t;
            was = true;
            break;
        }
        if (!was)
            break;
    }
    cout << n - s.size() << '\n';
}