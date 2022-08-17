#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];
vector<int> vin[max_n];
int n;
int color[max_n];

bool cycle = false;
void dfs(int cur) {
    if (cycle) {
        return;
    }
    color[cur] = 1;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (color[to] == 0) {
            dfs(to);
            continue;
        }
        if (color[to] == 1) {
            cycle = true;
        }
    }
    color[cur] = 2;
}

bool has_cycle() {
    cycle = false;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    return cycle;
}

vector<int> tout;
bool vis[max_n];
void dfs2(int cur) {
    vis[cur] = 1;
    for (int to : v[cur]) {
        if (!vis[to]) {
            dfs2(to);
        }
    }
    tout.PB(cur);
}
int dp[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        dp[i] = color[i] = vis[i] = 0;
        v[i].clear();
        vin[i].clear();
    }
    tout.clear();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        clr();
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                --x;
                v[x].PB(i);
                vin[i].PB(x);
            }
        }
        if (has_cycle()) {
            puts("-1");
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs2(i);
            }
        }
        reverse(tout.begin(), tout.end());
        int ans = 1;
        for (int x : tout) {
            dp[x] = 1;
            for (int to : vin[x]) {
                if (to < x) {
                    dp[x] = max(dp[x], dp[to]);
                } else {
                    dp[x] = max(dp[x], dp[to] + 1);
                }
            }
            ans = max(ans, dp[x]);
        }
        cout << ans << "\n";
    }

    return 0;
}