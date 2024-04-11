#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int> > edges;

LL ans = 0;
vector<LL> cnt(2, 0);

LL dfs(LL v, LL p, LL x){
    cnt[x]++;
    LL sz = 1;
    for(LL a : edges[v]){
        if(a == p) continue;
        sz += dfs(a, v, 1^x);
    }
    ans += sz * (edges.size() - sz);
    return sz;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    edges.resize(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0, -1, 0);
    cout << (ans + cnt[0] * cnt[1]) / 2 << '\n';
}