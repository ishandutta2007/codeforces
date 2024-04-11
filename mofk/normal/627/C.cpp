#include <bits/stdc++.h>
#define int long long

using namespace std;

int d, n, m;
pair <int, int> gas[200005];
int nxt[200005];

signed main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> d >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> gas[i].first >> gas[i].second;
    sort(gas + 1, gas + m + 1);
    gas[m+1] = make_pair(d, 0);
    for (int i = m; i >= 0; --i) {
        nxt[i] = i;
        while (gas[nxt[i] + 1].second > gas[i].second) nxt[i] = nxt[nxt[i] + 1];
    }
    long long ans = 0;
    int spare = n, cur = 0;
    while (cur <= m) {
        if (gas[cur+1].first - gas[cur].first > n) return cout << -1 << endl, 0;
        int Next = nxt[cur] + 1;
        if (gas[Next].first - gas[cur].first <= n) {
            int fil = gas[Next].first - gas[cur].first;
            if (spare < fil) {
                ans += (fil - spare) * gas[cur].second;
                spare = fil;
            }
        }
        else {
            ans += (n - spare) * gas[cur].second;
            spare = n;
        }
        spare -= (gas[cur+1].first - gas[cur].first);
        ++cur;
    }
    cout << ans << endl;
}