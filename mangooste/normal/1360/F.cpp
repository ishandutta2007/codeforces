#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> dict(n);
        for (auto &el : dict) {
            cin >> el;
        }
        Fun<bool(string)> maybe = [&](string s) {
            for (auto t : dict) {
                int cnt = 0;
                for (int i = 0; i < m; i++) {
                    if (s[i] != t[i]) {
                        cnt++;
                    }
                }
                if (cnt > 1) {
                    return false;
                }
            }
            return true;
        };
        bool fnd = false;
        for (int i = 0; i < m && !fnd; i++) {
            string start = dict[0].substr(0, i);
            string finish = (i == m - 1 ? "" : dict[0].substr(i + 1, m - i - 1));
            for (char ch = 'a'; ch <= 'z' && !fnd; ch++) {
                string cur = start;
                cur.pb(ch);
                cur += finish;
                if (maybe(cur)) {
                    cout << cur << '\n';
                    fnd = true;
                }
            }
        }
        if (!fnd) {
            cout << "-1\n";
        }
    }
}