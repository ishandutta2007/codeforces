#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000100;

int n, q;
vector<int> adj[maxn];
int par[maxn], val[maxn];
bool black[maxn];
int best = maxn;

void dfs(int v, int p = -1, int va = maxn) {
    par[v] = p;
    va = min(va, v);
    val[v] = va;
    for (int i : adj[v])
        if (i != p)
            dfs(i, v, va);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int last = 0;
    for (int i = 0; i < q; i++) {
        int t, x;
        scanf("%d %d", &t, &x);
        x = (x + last) % n + 1;
        if (i == 0) dfs(x);
        if (t == 1) {
            while (x != -1 && !black[x]) {
                black[x] = 1;
                best = min(best, x);
                x = par[x];
            }
        } else {
            last = min(val[x], best);
            printf("%d\n", last);
        }
    }
}