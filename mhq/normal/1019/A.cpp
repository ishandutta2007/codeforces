#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 3005;
int n, m;
ll ans = (ll)1e15;
vector < int > g[maxN];
int need[maxN];
vector < int > all;
int main() {
    ios_base::sync_with_stdio(false);
 //   freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p, a;
        cin >> p >> a;
        g[p].push_back(a);
    }
    for (int i = 1; i <= m; i++) {
        sort(g[i].begin(), g[i].end());
    }
    for (int sum = 0; sum <= (n - g[1].size()); sum++) {
        int val = sum + g[1].size();
        all.clear();
        ll cur = 0;
        int sum2 = 0;
        bool ok = true;
        for (int i = 2; i <= m; i++) {
            need[i] = max(0, (int)g[i].size() - val + 1);
            if (g[i].size() < need[i]) {
                ok = false;
                break;
            }
            sum2 += need[i];
            for (int j = 0; j < need[i]; j++) {
                cur += g[i][j];
            }
            for (int j = need[i]; j < g[i].size(); j++) all.push_back(g[i][j]);
        }
        if (!ok) continue;
        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        if (sum2 + all.size() < sum) continue;
        while (sum2 < sum) {
            sum2++;
            cur += all.back();
            all.pop_back();
        }
        ans = min(ans, cur);
    }
    cout << ans;
}