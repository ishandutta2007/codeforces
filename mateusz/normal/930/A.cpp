#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, x;
vector<int> V[N];
int depth[N];

void DFS(int w, int d) {
    depth[d]++;
    for (int u : V[w]) {
        DFS(u, d + 1);
    }
}

int main() {
    
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        V[x].push_back(i);
    }
    
    DFS(1, 0);
    
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += depth[i] % 2;
    }
    
    printf("%d\n", ans);
    
    return 0;
}