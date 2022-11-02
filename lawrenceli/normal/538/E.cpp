#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int n;
vector<int> adj[MAXN];

int leaf[MAXN], ma[MAXN], mi[MAXN];

void dfs(int cur, int p=-1, int d=0) {
    if (adj[cur].size()-(p!=-1) == 0) {
        leaf[cur] = 1;
        ma[cur] = mi[cur] = 1;
        return;
    }

    for (int x : adj[cur]) if (x != p) {
        dfs(x, cur, d+1);
        leaf[cur] += leaf[x];
    }

    int k = leaf[cur];

    if (d%2 == 0) { //maximize
        int mim = 1e9, sum = 0;
        for (int x : adj[cur]) if (x != p) {
            mim = min(mim, leaf[x]-ma[x]);
            sum += leaf[x]-mi[x];
        }
        ma[cur] = k-mim;
        mi[cur] = k-sum;
    } else { //minimize
        int mim = 1e9, sum = 0;
        for (int x : adj[cur]) if (x != p) {
            sum += ma[x]-1;
            mim = min(mim, mi[x]);
        }
        ma[cur] = sum+1;
        mi[cur] = mim;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << ma[1] << ' ' << mi[1] << '\n';
}