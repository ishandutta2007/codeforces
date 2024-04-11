#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e6 + 5;

int n, k;
vector<int> g[N];
pii dp[N];

void dfs(int v, int par = -1) {
    int child = 0;
    vector<pii> hlp;
    for (int to : g[v]) {
        if (to == par) continue;
        child++;
        dfs(to, v);
        dp[v].first += dp[to].first;
        if (dp[to].second < k) {
            hlp.emplace_back(
                    dp[to].first,
                    dp[to].second + 1
            );
        }
    }
    if (child == 0) {
        dp[v] = {1, 0};
        return;
    }
    sort(hlp.begin(), hlp.end(), [](pii p1, pii p2){
        return p1.second > p2.second;
    });
    while ((int)hlp.size() >= 2) {
        pii p1 = hlp[(int)hlp.size() - 1];
        pii p2 = hlp[(int)hlp.size() - 2];
        if (p1.second + p2.second <= k) {
            hlp.pop_back();
            dp[v].first--;
        } else {
            break;
        }
    }
    dp[v].second = hlp.empty() ? inf : hlp.back().second;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = 1;

    while ((int)g[root].size() == 1) root++;

    dfs(root);

//    for (int v = 1; v <= n; v++) {
//        cout << dp[v].first << " " << dp[v].second << "\n";
//    }

    cout << dp[root].first << "\n";

    return 0;
}