#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
vector<int> a[maxn];
int d[maxn];
int b[maxn];
void dfs(int u,int p=-1) {
    if(d[u]%2==0) {
        b[u]=-a[u].size();
    }
    else {
        b[u]=a[u].size();
    }
    for(auto v:a[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            dfs(v,u);
        }
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n-1;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1);
        for(int i=1;i<=n;i++) printf("%d ",b[i]);
        printf("\n");
        for(int i=1;i<=n;i++) {
            a[i].clear();
            d[i]=0;
            b[i]=0;
        }
    }
    return 0;
}