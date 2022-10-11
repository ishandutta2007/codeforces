#include <algorithm>
#include <cassert>
#include <cmath>
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

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        deque<int> dq;
        for (int i = 0; i < a; i++) {
            dq.pb(1);
        }
        for (int i = a; i < m; i++) {
            dq.pb(0);
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = dq[j];
            }
            for (int k = 0; k < a; k++) {
                int fr = dq.front();
                dq.pop_front();
                dq.pb(fr);
            }
        }
        bool chk = true;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                cur += ans[i][j];
            }
            chk &= (cur == a);
        }
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                cur += ans[i][j];
            }
            chk &= (cur == b);
        }
        if (chk) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j];
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
}