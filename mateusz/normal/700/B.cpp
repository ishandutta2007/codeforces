#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, k, x, a, b;
int cnt[N];
long long ans;
bool vis[N];
vector<int> V[N];

void DFS(int w) {
    vis[w] = true;

    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS(u);
            ans += min(cnt[u], (2 * k - cnt[u]));
            cnt[w] += cnt[u];
        }
    }
}

int main() {

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= 2 * k; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    DFS(1);

    printf("%lld\n", ans);

    return 0;
}