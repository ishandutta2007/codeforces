#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
vector<int> a[2000000];
bool vis[2000000];
int low[2000000];
int disc[2000000];
bool instack[2000000];
int comp[2000000];
vector<int> b[2000000];
stack<int> s;
int tim=0;
int cc=0;
void scc(int u) {
    vis[u]=true;
    instack[u]=true;
    s.push(u);
    disc[u]=low[u]=tim++;
    for(int i=0;i<a[u].size();i++) {
        int v=a[u][i];
        if(!vis[v]) {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
        else {
            if(instack[v]) low[u]=min(low[u],disc[v]);
        }
    }
    if(low[u]==disc[u]) {
        while(!s.empty() && s.top()!=u) {
            instack[s.top()]=false;
            comp[s.top()]=cc;
            s.pop();
        }
        instack[s.top()]=false;
        comp[s.top()]=cc;
        s.pop();
        cc++;
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        int u,v;
        for(int i=1;i<=n;i++) {
            a[i].clear();
            vis[i]=false;
            low[i]=disc[i]=-1;
            instack[i]=false;
            comp[i]=-1;
            b[i].clear();
            cc=0;
        }
        for(int i=1;i<=m;i++) {
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
        }
        for(int i=1;i<=n;i++) {
            if(!vis[i]) scc(i);
        }
        int bc=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<a[i].size();j++) {
                if(comp[i]!=comp[a[i][j]]) {
                    b[comp[i]].push_back(comp[a[i][j]]);
                }
            }
        }
        for(int i=0;i<cc;i++) {
            if(b[i].size()==0) bc=i;
        }
        if(cc==1) printf("No\n");
        else {
            printf("Yes\n");
            int j=0;
            for(int i=1;i<=n;i++) {
                if(comp[i]==bc) j++;
            }
            printf("%d %d\n",j,n-j);
            for(int i=1;i<=n;i++) {
                if(comp[i]==bc) printf("%d ",i);
            }
            printf("\n");
            for(int i=1;i<=n;i++) {
                if(comp[i]!=bc) printf("%d ",i);
            }
            printf("\n");
        }
    }
    return 0;
}