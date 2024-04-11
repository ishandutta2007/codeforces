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
using ll = long long;
using pii = pair<int, int>;

namespace Debug {
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

    #define DEBUG

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

int n, m, k;
vector<vector<int>> table;
vector<vector<int>> num;
int cur;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    vector<char> can;
    for (int i = 0; i < 10; i++)
        can.pb('0' + i);
    for (int i = 0; i < 26; i++) {
        can.pb('a' + i);
        can.pb('A' + i);
    }
    while (t--) {
        cin >> n >> m >> k;
        table.clear();
        table.resize(n, vector<int>(m));
        num.clear();
        num.resize(n, vector<int>(m, -1));
        int cnt = 0;
        for (auto &i : table) 
            for (auto &el : i) {
                char cur;
                cin >> cur;
                if (cur == '.')
                    el = 0;
                else
                    el = 1, cnt++;
            }
        vector<int> need(k);
        for (auto &el : need)
            el = cnt / k;
        for (int i = 0; i < cnt % k; i++)
            need[i]++;
        cur = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            if (i % 2)
                j = m - 1;
            while (j >= 0 && j < m) {
                if (table[i][j])
                    if (need.back() == 0) {
                        need.pop_back();
                        cur++;
                    }
                need.back() -= table[i][j];
                num[i][j] = cur;
                if (i % 2 == 0)
                    j++;
                else
                    j--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << can[num[i][j]];
            cout << '\n';
        }
    }
}