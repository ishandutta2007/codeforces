#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

map<int, vector<int> > g[100001];

map<int, int> used[100001];
set<int> cc[100001];
map<pair<int, int>, int> qs;

void dfs(int x, int co, int c){
    if (used[x][co]==1) return;
    used[x][co]=1;
    cc[x].insert(c);
    for (int nx:g[x][co]){
        dfs(nx, co, c);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][c].push_back(b);
        g[b][c].push_back(a);
    }
    int i2=1;
    for (int i=1;i<=n;i++){
        for (auto e:g[i]){
            dfs(i, e.F, i2++);
        }
    }
    int q;
    cin>>q;
    for (int qq=0;qq<q;qq++){
        int u,v;
        cin>>u>>v;
        if (u>v) swap(u, v);
        if (qs[{u, v}]) cout<<qs[{u, v}]-1<<'\n';
        else{
            int vv=0;
            if (cc[u].size()<cc[v].size()){
                for (int c:cc[u]){
                    if (cc[v].count(c)) vv++;
                }
            }
            else{
                for (int c:cc[v]){
                    if (cc[u].count(c)) vv++;
                }
            }
            qs[{u, v}]=vv+1;
            cout<<vv<<'\n';
        }
    }
}