#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 310;
const int MAXT = 500010;
const int MOD = 1e9+7;

int n, q, t;
int a[MAXN], adj[MAXN], val[MAXN], indeg[MAXN];
int sze;
bool vis[MAXN];
int dp[MAXT];

void dfs(int n) {
    vis[n]=true;
    if (adj[n]==-1) val[sze]=a[n];
    else {
        if (vis[adj[n]]) {
            cout << 0 << endl;
            exit(0);
        }
        dfs(adj[n]);
        val[sze]=val[sze-1]+a[n];
    }
    if (t<0) {
        cout << 0 << endl;
        exit(0);
    }
    t-=val[sze++];
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d%d%d", &n, &q, &t);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) adj[i]=-1;
    for (int i=0; i<q; i++) {
        int b, c;
        scanf("%d%d", &b, &c);
        b--; c--;
        adj[c]=b;
        indeg[b]++;
    }
    for (int i=0; i<n; i++) {
        if (indeg[i]==0) {
            dfs(i);
            t+=val[sze-1];
            if (t<0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (sze!=n) {
        cout << 0 << endl;
        return 0;
    }
    dp[0]=1;
    for (int i=0; i<sze; i++) {
        for (int j=0; j<t; j++) {
            int k=j+val[i];
            if (k<=t) dp[k]=(dp[k]+dp[j])%MOD;
        }
    }
    cout << dp[t] << endl;
}