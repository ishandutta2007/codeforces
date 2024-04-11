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

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &el : a)
        cin >> el;
    vector<ll> pr(n);
    pr[0] = a[0];
    for (int i = 1; i < n; i++)
        pr[i] = pr[i - 1] + a[i];
    vector<ll> mn(n + 1);
    const ll INF = 1e16;
    for (int cnt = 0; cnt <= n; cnt++) {
        ll L = -1, R = INF;
        auto chk = [&](ll val) {
            priority_queue<ll> pq;
            ll already = 0;
            int cur_cnt = 0;
            for (int i = 0; i < n; i++) {
                pq.push(-a[i]);
                while (pr[i] - already + val < 0) {
                    already += -pq.top();
                    pq.pop();
                    cur_cnt++;
                }
            }
            return cur_cnt <= cnt;
        };
        while (R - L > 1) {
            ll md = (L + R) / 2;
            if (chk(md))
                R = md;
            else
                L = md;
        }
        mn[cnt] = R;
    }
    for (int tt = 0; tt < m; tt++) {
        ll b;
        cin >> b;
        int L = -1, R = n + 1;
        while (R - L > 1) {
            int md = (L + R) / 2;
            if (mn[md] <= b)
                R = md;
            else
                L = md;
        }
        cout << R << '\n';
    }
}