#include <bits/stdc++.h>
using namespace std;

const int maxn = 500100;

int n, m, qv[maxn], qh[maxn], num[maxn];
char tc[maxn];
vector<int> adj[maxn];
vector<int> v[maxn], pre[maxn];
int ent[maxn], exi[maxn], cnt;
int qlo[maxn], qup[maxn];

void dfs(int cur, int d=1) {
    v[d].push_back(cur);
    ent[cur] = cnt++;
    for (int i : adj[cur]) {
        dfs(i, d+1);
    }
    exi[cur] = cnt;
}

bool cmp(int a, int b) {
    return ent[a] < b;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=2; i<=n; i++) {
        int p;
        scanf("%d", &p);
        adj[p].push_back(i);
    }
    
    scanf("\n");
    for (int i=1; i<=n; i++) scanf("%c", &tc[i]);

    dfs(1);

    for (int i=0; i<m; i++) {
        scanf("%d %d", &qv[i], &qh[i]);
    }

    for (int i=0; i<m; i++) {
        qlo[i] = lower_bound(v[qh[i]].begin(), v[qh[i]].end(), ent[qv[i]], cmp) - v[qh[i]].begin();
        qup[i] = lower_bound(v[qh[i]].begin(), v[qh[i]].end(), exi[qv[i]], cmp) - v[qh[i]].begin();
    }



    for (char c='a'; c <= 'z'; c++) {
        for (int i=1; i<=n; i++) {
            pre[i].resize(v[i].size() + 1, 0);
            for (int j=0; j<v[i].size(); j++)
                if (tc[v[i][j]] == c) pre[i][j+1] = pre[i][j] + 1;
                else pre[i][j+1] = pre[i][j];
        }

        for (int i=0; i<m; i++)
            if ((pre[qh[i]][qup[i]] - pre[qh[i]][qlo[i]]) & 1) num[i]++;
    }

    for (int i=0; i<m; i++) {
        if (num[i] <= 1) printf("Yes\n");
        else printf("No\n");
    }
}