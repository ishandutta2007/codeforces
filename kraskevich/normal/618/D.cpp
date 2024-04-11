#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200 * 1000 + 10;

vector<int> g[N];
int dp0[N]; // has an open end
int dp1[N]; // both taken
bool was[N];

void dfs(int v) {
    was[v] = true;
    int kids = 0;
    int any_sum = 0;
    vector<int> difs;
    for (int to : g[v]) {
        if (was[to])
            continue;
        dfs(to);
        any_sum += dp1[to];
        kids++;
        difs.push_back(dp0[to] - dp1[to]);
    }
    if (kids == 0) 
        return;
    sort(difs.begin(), difs.end());
    reverse(difs.begin(), difs.end());
    dp0[v] = max(any_sum, any_sum + difs[0] + 1);
    dp1[v] = dp0[v];
    if (difs.size() >= 2)
        dp1[v] = max(dp1[v], any_sum + difs[0] + difs[1] + 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    ll res = dp1[0] * x + (n - 1 - dp1[0]) * y;
    int max_deg = 0;
    for (int i = 0; i < n; i++)
        max_deg = max(max_deg, int(g[i].size()));
    if (max_deg == n - 1)
        res = min(res, (n - 2) * y + x);
    else 
        res = min(res, (n - 1) * y);
    cout << res << endl;
}