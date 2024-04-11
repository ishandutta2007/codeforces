#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, c, d;
int parent[N];
vector<int> g[N];
pair<int, char> a[N];
ll weight[N];
ll dp[N][2];

void dfs(int v) {
    dp[v][0] = d;
    dp[v][1] = weight[v];
    for (int to : g[v]) {
        dfs(to);
        dp[v][0] += dp[to][0];
        dp[v][1] += min(dp[to][0], dp[to][1]);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> d;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    cin >> a[n].first;

    {
        int last_p = n;
        int last_w = n;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i].second == 'P') {
                parent[i] = last_w;
                weight[i] = 1ll * (a[last_w].first - a[i].first) * c;
                last_p = i;
            } else {
                parent[i] = last_p;
                weight[i] = 1ll * (a[last_p].first - a[i].first) * c;
                last_w = i;
            }
        }
    }

    for (int v = 0; v < n; v++) {
        g[parent[v]].push_back(v);
    }

    dfs(n);

    cout << dp[n][1] << "\n";

    return 0;
}