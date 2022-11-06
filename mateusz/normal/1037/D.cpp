#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, a, b;
vector<int> V[N];
int seq[N], where[N];
vector<int> mySeq;
bool vis[N];

void BFS(int v) {
    queue<int> Q;
    Q.push(v);
    vis[v] = true;
    
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        mySeq.push_back(w);
        for (int u : V[w]) {
            if (!vis[u]) {
                vis[u] = true;
                Q.push(u);
            }
        }
    }
}

bool cmp(int a, int b) {
    return where[a] < where[b];
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &seq[i]);
        where[seq[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        sort(V[i].begin(), V[i].end(), cmp);
    }
    
    BFS(1);
    
    for (int i = 1; i <= n; i++) {
        if (seq[i] != mySeq[i - 1]) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    
    return 0;
}