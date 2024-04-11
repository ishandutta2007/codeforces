#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

vector <int> E[100010], P[100010];
int n, m, q, C[100010];

struct node{
    node(){top=0;}
    int p[10], top;
    void Ins(int x){
        if(top == 10)return;
        p[top++] = x;
    }
};

node up[100010][20];
int upd[100010][20], dep[100010];

node merge(node &a,node &b){
    node res; res.top = 0;
    int i=0, j=0;
    for(;i<a.top;i++){
        while(j != b.top && b.p[j] <= a.p[i])res.Ins(b.p[j++]);
        res.Ins(a.p[i]);
    }
    while(j != b.top)res.Ins(b.p[j++]);
    return res;
}

void dfs(int x,int fa){
    for(auto i : E[x]){
        if(i != fa){
            dep[i] = dep[x] + 1;
            upd[i][0] = x;
            for(int j=1;j<20;j++){
                upd[i][j] = upd[ upd[i][j-1] ][j-1];
            }
            for(int j=1;j<20;j++){
                up[i][j] = merge(up[i][j-1], up[ upd[i][j-1] ][j-1]);
            }
            dfs(i, x);
        }
    }
}

void Do(int u,int v,int a){
    if(dep[u] > dep[v])swap(u, v);
    node res; res.top = 0;
    for(int i=0;i<20;i++){
        if(1<<i & (dep[v] - dep[u])){
            res = merge(res, up[v][i]);
            v = upd[v][i];
        }
    }
    for(int i=19;i>=0;i--){
        if(upd[u][i] != upd[v][i]){
            res = merge(res, up[u][i]);
            res = merge(res, up[v][i]);
            u = upd[u][i];
            v = upd[v][i];
        }
    }
    if(u == v){
        res = merge(res, up[v][0]);
        int len = min(res.top, a);
        printf("%d ",len);
        for(int i=0;i<len;i++)printf("%d ", res.p[i]);
    }
    else{
        res = merge(res, up[v][1]);
        res = merge(res, up[u][0]);
        
        int len = min(res.top, a);
        printf("%d ",len);
        for(int i=0;i<len;i++)printf("%d ", res.p[i]);
    }
    puts("");
}

void solve(int tc) {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<n;i++){
        int x, y; scanf("%d%d",&x,&y);
        E[x].pb(y); E[y].pb(x);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",C+i);
        up[C[i]][0].Ins(i);
    }
    dfs(1, -1);
    for(int i=1;i<=q;i++){
        int u, v, a; scanf("%d%d%d",&u,&v,&a);
        Do(u, v, a);
    }
}

int main(){
    int Tc = 1;// scanf("%d",&Tc);
    for(int i=1;i<=Tc;i++){
        solve(i);
    }
    return 0;
}