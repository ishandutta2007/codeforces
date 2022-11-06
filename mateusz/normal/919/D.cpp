#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m, a, b;
char letter[N];
int vis[N];
int dp[N][30];
vector<int> V[N];

bool DFS(int w) {
    vis[w] = 1;
    
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (vis[u] == 1) {
            return false;
        }
        if (!vis[u]) {
            if (!DFS(u)) {
                return false;
            }
        }
    }
    
    dp[w][letter[w]] = 1;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        for (int j = 0; j < 26; j++) {
            dp[w][j] = max(dp[w][j], dp[u][j] + (letter[w] == j));
        }
    }
    
    vis[w] = 2;
    return true;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    scanf("%s", &letter[1]);
    for (int i = 1; i <= n; i++) {
        letter[i] -= 'a';
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !DFS(i)) {
            printf("-1\n");
            return 0;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    
    printf("%d\n", ans);
  
    return 0;
}