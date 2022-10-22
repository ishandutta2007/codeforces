#include<bits/stdc++.h>
#define maxn 200500
using namespace std;
int t;
int n,m;
vector<pair<int,int> > a[maxn];
vector<pair<int,int> > b[maxn];
int sz[maxn];
char s[maxn];
bool vis[maxn];
bool vs[maxn];
int low[maxn];
int disc[maxn];
int par[maxn];
int tcm=0;
void tarjan(int u,int pred) {
    low[u]=disc[u]=tcm;
    vs[u]=true;
    tcm++;
    for(auto eg:a[u]) {
        int v=eg.first;
        if(v!=pred) {
            if(!vs[v]) {
                par[v]=u;
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
            }
            else {
                low[u]=min(low[u],disc[v]);
            }
        }
    }
}
void dfs1(int i,int col) {
    vis[i]=true;
    for(auto eg:b[i]) {
        int j=eg.first;
        if(s[eg.second]=='2') {
            s[eg.second]='0'+col;
            col=col^1;
        }
        if(b[j].size()==2 && !vis[j]) {
            dfs1(j,col);
        }
    }
}
void dfs2(int i) {
    vis[i]=true;
    for(auto eg:b[i]) {
        int j=eg.first;
        if(b[j].size()>2) {
            if(s[eg.second]=='2') {
                if(!vis[j]) s[eg.second]='1';
                else s[eg.second]='0';
            }
            if(!vis[j]) dfs2(j);
        }
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back({v,i});
            a[v].push_back({u,i});
            s[i]='2';
        }
        s[m]=0;
        tarjan(1,-1);
        for(int i=1;i<=n;i++) {
            for(auto eg:a[i]) {
                int j=eg.first;
                if(par[j]!=i && par[i]!=j) {
                    b[i].push_back(eg);
                }
                else {
                    if(par[j]==i && low[j]<=disc[i]) b[i].push_back(eg);
                    else {
                        if(par[i]==j && low[i]<=disc[j]) b[i].push_back(eg);
                        else {
                            s[eg.second]='0';
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(b[i].size()==2 && !vis[i]) dfs1(i,1);
        }
        for(int i=1;i<=n;i++) {
            if(b[i].size()>2 && !vis[i]) dfs2(i);
        }
        for(int i=1;i<=n;i++) {
            a[i].clear();
            b[i].clear();
            vs[i]=false;
            vis[i]=false;
        }
        printf("%s\n",s);
    }
    return 0;
}