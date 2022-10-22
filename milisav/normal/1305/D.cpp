#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
int n;
vector<int> a[maxn];
vector<int> vrtc;
bool ce[maxn];
vector<pair<int,int> > eg;
void dfs(int u,int p,int w) {
    if(u==w) return;
    ce[u]=false;
    for(auto v:a[u]) {
        if(v!=p) dfs(v,u,w);
    }
}
void refactor_tree(int u,int v,int w) {
    dfs(u,-1,w);
    dfs(v,-1,w);
    vrtc.clear();
    for(int i=1;i<=n;i++) a[i].clear();
    for(auto e:eg) {
        if(ce[e.first] && ce[e.second]) {
            a[e.first].push_back(e.second);
            a[e.second].push_back(e.first);
        }
    }
    for(int i=1;i<=n;i++) {
        if(ce[i]) vrtc.push_back(i);
    }
}
int main() {
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<=n;i++) {
        ce[i]=true;
        vrtc.push_back(i);
    }
    for(int i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
        eg.push_back({u,v});
    }
    while(vrtc.size()>1) {
        u=-1;
        v=-1;
        for(auto t:vrtc) {
            if(a[t].size()==1) {
                if(u==-1) u=t;
                else {
                    v=t;
                    break;
                }
            }
        }
        int w;
        printf("? %d %d\n",u,v);
        fflush(stdout);
        scanf("%d",&w);
        refactor_tree(u,v,w);
    }
    printf("! %d\n",vrtc[0]);
    fflush(stdout);
    return 0;
}