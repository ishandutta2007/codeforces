#include <bits/stdc++.h>

using namespace std;

const int N = 1000006, INF = 1e9;

int n, m;
int a, b;
vector<int> V2[N];

int stwy[N];
int dp[N];
int type[N];

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &type[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &b, &a);
        V2[b].push_back(a);
        stwy[a]++;
    }
    
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (stwy[i] == 0) {
            Q.push(i);
        }
    }
    
    while (!Q.empty()) {
        int w = Q.front();
        if (type[w] == 1) {
            dp[w] = max(dp[w], 1);
        }
        Q.pop();
        for (int i = 0; i < V2[w].size(); i++) {
            int u = V2[w][i];
            if (!(type[u] == 1 && type[w] == 0)) {
                dp[u] = max(dp[u], dp[w]);
            } else {
                dp[u] = max(dp[u], dp[w] + 1);
            }
            stwy[u]--;
            if (stwy[u] == 0) {
                Q.push(u);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}