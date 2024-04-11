#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
int xr = 0;
void ask(vector<int>& p) {
    cout << "? ";
    for (int v : p) cout << v << " ";
    cout << endl;
    int resp;
    cin >> resp;
    xr ^= resp;
}
int dp[505];
int prv[505];
int to_take[505];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        int nv = n - v;
        q.pop();
        for (int take1 = 0; take1 <= k; take1++) {
            if (take1 <= v && k - take1 <= nv) {
                int new_val = (v - take1) + k - take1;
                if (dp[new_val] == -1) {
                    dp[new_val] = dp[v] + 1;
                    prv[new_val] = v;
                    to_take[new_val] = take1;
                    q.push(new_val);
                }
            }
        }
    }
    if (dp[n] == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    int cur = n;
    while (cur != 0) {
        path.emplace_back(cur);
        cur = prv[cur];
    }
    path.emplace_back(0);
    reverse(path.begin(), path.end());
    vector<int> sgn(n + 1, 0);
    for (int x = 0; x + 1 < path.size(); x++) {
        int from = path[x];
        int to = path[x + 1];
        int take1 = to_take[path[x + 1]];
        int take0 = k - take1;
        vector<int> p;
        for (int u = 1; u <= n; u++) {
            if (take1 > 0 && sgn[u] == 1) {
                p.emplace_back(u);
                take1--;
                sgn[u] ^= 1;
            }
            else if (take0 > 0 && sgn[u] == 0) {
                p.emplace_back(u);
                take0--;
                sgn[u] ^= 1;
            }
        }
        assert(p.size() == k);
        ask(p);
    }
    cout << "! " << xr << endl;
    /*if (n % 2 == 1 && k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int cnt_bad = n % k;
    if (cnt_bad % 2 == 0) {
        if (cnt_bad != 0) {
            vector<int> p1, p2;
            for (int i = 1; i <= cnt_bad / 2; i++) {
                p1.emplace_back(i);
                p2.emplace_back(i + cnt_bad / 2);
            }
            for (int i = cnt_bad + 1; i <= k + cnt_bad / 2; i++) {
                p1.emplace_back(i);
                p2.emplace_back(i);
            }
            assert(p1.size() == k && p2.size() == k);
            ask(p1);
            ask(p2);
        }
    }
    else {
        vector<int> p1, p2, p3;
        for (int i = 1; i <= k; i++) {
            p1.emplace_back(i);
        }
        vector<int> lft;
        vector<int> bad;
        for (int x = 1; x <= k + cnt_bad; x++) {
            if (x <= cnt_bad || x > k) lft.emplace_back(x);
            else bad.emplace_back(x);
        }
        assert(bad.size() % 2 == 0);
        for (int i = 0; i < (int)bad.size() / 2; i++) {
            p2.emplace_back(bad[i]);
            p3.emplace_back(bad[i + (bad.size()) / 2]);
        }
        for (int i = 0; i < k - (int)bad.size() / 2; i++) {
            p2.emplace_back(lft[i]);
            p3.emplace_back(lft[i]);
        }
        assert(p1.size() == k && p2.size() == k && p3.size() == k);
        ask(p1);
        ask(p2);
        ask(p3);
    }
    for (int x = cnt_bad + 1; x <= n; x += k) {
        vector<int> u;
        for (int f = x; f <= x + k - 1; f++) u.emplace_back(f);
        ask(u);
    }*/
    return 0;
}