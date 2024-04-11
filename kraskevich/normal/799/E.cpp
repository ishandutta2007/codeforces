#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll INF = (ll)1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    multiset<int> both;
    vector<multiset<int>> have(2);
    multiset<int> wait;
    multiset<int> opt_set;
    ll res = INF;
    ll cur_both = 0;
    vector<ll> cur(2);
    ll rest = 0;
    vector<vector<bool>> like(n, vector<bool>(2));
    for (int r = 0; r < 2; r++) {
        int a;
        cin >> a;
        for (int i = 0; i < a; i++) {
            int x;
            cin >> x;
            --x;
            like[x][r] = true;
        }
    }
    vector<pair<ll, int>> cp(n);
    for (int i = 0; i < n; i++)
        cp[i] = make_pair(c[i], i);
    sort(cp.begin(), cp.end());
    for (auto p : cp) {
        int i = p.second;
        ll val = p.first;
        if (like[i][0] && like[i][1]) {
            both.insert(val);
            continue;
        }
        if (like[i][0] && (int)have[0].size() < k) {
            cur[0] += val;
            have[0].insert(val);
            continue;
        }
        if (like[i][1] && (int)have[1].size() < k) {
            cur[1] += val;
            have[1].insert(val);
            continue;
        }
        wait.insert(val);
    }
    int both_cnt = 0;
    for (;;) {
        for (int r = 0; r < 2; r++) {
            while ((int)have[r].size() + both_cnt > k) {
                ll x = *have[r].rbegin();
                cur[r] -= x;
                have[r].erase(have[r].find(x));
                wait.insert(x);
            }
        }
        if (both_cnt == k)
            for (auto x : both) 
                wait.insert(x);
        while (opt_set.size() && (int)opt_set.size() > m - 2 * k + both_cnt) {
            ll x = *opt_set.rbegin();
            opt_set.erase(opt_set.find(x));
            rest -= x;
        }
        while (opt_set.size() && wait.size() &&  *opt_set.rbegin() > *wait.begin()) {
            ll x = *opt_set.rbegin();
            ll y = *wait.begin();
            rest -= x;
            rest += y;
            opt_set.erase(opt_set.find(x));
            opt_set.insert(y);
            wait.erase(wait.find(y));
            wait.insert(x);
        }
        while (wait.size() && (int)opt_set.size() < m - 2 * k + both_cnt) {
            ll x = *wait.begin();
            wait.erase(wait.find(x));
            rest += x;
            opt_set.insert(x);
        }
        if (both_cnt + (int)have[0].size() >= k && both_cnt + (int)have[1].size() >= k && 2 * k - both_cnt + (int)opt_set.size() == m)
            res = min(res, rest + cur[0] + cur[1] + cur_both);
        if (both.empty() || both_cnt == k)
            break;
        both_cnt++;
        cur_both += *both.begin();
        both.erase(both.begin());
    }
    if (res == INF)
        res = -1;
    cout << res << endl;
}