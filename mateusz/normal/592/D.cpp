#include <bits/stdc++.h>

using namespace std;

const int N = 222222, INF = 0;

int n, m, a, b, x;
vector<int> V[N];
bool vis[N];
int bad[N];
int dp[N], dp2[N];
int res[N];

void DFS1(int w) {
    vis[w] = true;
    int dpSum = 0;
    int bestDiff = 0;
    int badNeighbours = 0;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (vis[u] == false) {
            DFS1(u);
            bad[w] += bad[u];
            if (bad[u] > 0) {
                badNeighbours++;
                dp[w] += dp[u] + 2;
                dpSum += dp[u];
                bestDiff = min(bestDiff, -dp[u] + dp2[u]);
            }
        }
    }
    dp2[w] = dpSum + bestDiff + max(0, badNeighbours * 2 - 1);
}

void DFS2(int w, int dpSum, int bestDiff, int badNeighbours) {
    vis[w] = true;
    vector<int> bestDiffPref;
    bestDiffPref.push_back(bestDiff);
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (vis[u] == false && bad[u] > 0) {
            badNeighbours++;
            dpSum += dp[u];
            bestDiff = min(bestDiff, -dp[u] + dp2[u]);
        }
        bestDiffPref.push_back(bestDiff);
    }
    res[w] = dpSum + bestDiff + max(0, badNeighbours * 2 - 1);
    int bestSuf = INF;
    for (int i = V[w].size() - 1; i >= 0; i--) {
        int u = V[w][i];
        if (vis[u] == false) {
            int newDp = dpSum + 2 * (badNeighbours) - dp[u] - 2 * (bad[u] > 0);
            int newDp2 = newDp + min(bestSuf, bestDiffPref[i]) - (badNeighbours - (bad[u] > 0) > 0 ? 1 : 0);
            DFS2(u, newDp, -newDp + newDp2, (m - bad[u]) > 0);
            bestSuf = min(bestSuf, -dp[u] + dp2[u]);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        bad[x] = 1;
    }

    DFS1(1);
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    res[1] = dp2[1];
    DFS2(1, 0, INF, 0);

    int mini = 1e9;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (res[i] < mini) {
            mini = res[i];
            ans = i;
        }
    }

    printf("%d\n%d\n", ans, mini);

    return 0;
}