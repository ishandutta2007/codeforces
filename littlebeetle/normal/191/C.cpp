#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long

const int Maxn=200001;
const int oo=2147483647;

int n,m,x[Maxn],y[Maxn],a,b;
int son[Maxn],size[Maxn],deep[Maxn],fa[Maxn],top[Maxn],len[Maxn];
int NEXT[Maxn],to[Maxn],head[Maxn],cnt;
void insert(int u,int v) {
    ++cnt;
    NEXT[cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;  
}
void dfs_1(int u,int f) {
    fa[u]=f;
    deep[u]=deep[f]+1;
    size[u]=1;
    for(int i=head[u]; i; i=NEXT[i]) {
        int v=to[i];
        if(v==fa[u]) continue;
        dfs_1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
}
void dfs_2(int u,int topf) {
    top[u]=topf;
    if(!son[u]) return;
    dfs_2(son[u],topf);
    for(int i=head[u]; i; i=NEXT[i]) {
        int v=to[i];
        if(v==fa[u]||v==son[u]) continue;
        dfs_2(v,v);
    }
}
int lca(int x,int y) {
    while(top[x]!=top[y]) {
        if(deep[top[x]]<deep[top[y]]) y=fa[top[y]];
        else x=fa[top[x]];
    }
    if(deep[x]>deep[y]) swap(x,y);
    return x;
}
void dfs_3(int u,int f) {
    for(int i=head[u]; i; i=NEXT[i]) {
        int v=to[i];
        if(v==f) continue; 
        dfs_3(v,u);
        len[u]+=len[v];
    }
    return;
}
int main() {
    cin>>n;
    for(int i=1; i<n; i++) {
        cin>>x[i]>>y[i];
        insert(x[i],y[i]);
        insert(y[i],x[i]);
    }
    dfs_1(1,0);
    dfs_2(1,1);
    cin>>m;
    for(int i=1; i<=m; i++) {
        cin>>a>>b;
        len[a]++;
        len[b]++;
        len[lca(a,b)]-=2;   
    }
    dfs_3(1,0);
    for(int i=1; i<n; i++) {
        if(deep[x[i]]<deep[y[i]]) swap(x[i],y[i]);
        cout<<len[x[i]]<<' ';
    }
    return 0;
}