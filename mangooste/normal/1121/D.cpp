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

const int N = 500005;
int m, k, n, s;
int a[N], b[N], cnt[N];
map<int, queue<int>> cur;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> m >> k >> n >> s;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < s; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    set<int> poses;
    sort(b, b + s);
    int need = unique(b, b + s) - b;
    for (int i = m - 1; i >= 0; i--) {
        int el = a[i];
        if (cnt[el] != 0) {
            if (cur[el].size() == cnt[el]) {
                poses.erase(cur[el].front());
                cur[el].pop();
                cur[el].push(i);
                poses.insert(cur[el].front());
            } else {
                cur[el].push(i);
                if (cur[el].size() == cnt[el])
                    poses.insert(cur[el].front());
            }
        }
        if (poses.size() != need)
            continue;
        int mx_pos = *(--poses.end());
        int L = (i / k) * k, R = L + k;
        if (mx_pos < R)
            return cout << "0\n", 0;
        int cnt_left = L / k;
        int mn_need = mx_pos - R + 1 + max(0, cnt_left - n + 1) * k;
        if (m - mn_need >= n * k && i + k - 1 < m) {
            cout << mn_need << '\n';
            for (int j = 0; j < max(0, cnt_left - n + 1) * k; j++)
                cout << j + 1 << ' ';
            for (int j = L, sm = 0; sm < mn_need - max(0, cnt_left - n + 1) * k; j++) {
                if (j < i) {
                    cout << j + 1 << ' ';
                    sm++;
                    continue;
                }
                if (cur[a[j]].size())
                    cur[a[j]].pop();
                else {
                    cout << j + 1 << ' ';
                    sm++;
                }
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}