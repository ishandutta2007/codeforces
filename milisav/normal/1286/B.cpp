#include<bits/stdc++.h>
using namespace std;
int n;
int p[5000];
int c[5000];
int ans[5000];
int ch[5000];
vector<int> a[5000];
vector<pair<int,int> > cr;
void dfs_compute(int u) {
    cr.push_back({ans[u],u});
    for(auto v:a[u]) {
        dfs_compute(v);
    }
}
void dfs(int u,int offset) {
    ch[u]=0;
    int boff=offset;
    for(auto v:a[u]) {
        dfs(v,offset);
        ch[u]+=(ch[v]+1);
        offset+=(ch[v]+1);
    }
    if(c[u]>ch[u]) {
        printf("NO");
        exit(0);
    }
    if(ch[u]==0) {
        ans[u]=1+offset;
        return;
    }
    cr.clear();
    for(auto v:a[u]) {
        dfs_compute(v);
    }
    sort(cr.begin(),cr.end());
    if(c[u]==0) ans[u]=1+boff;
    else ans[u]=cr[c[u]-1].first+1;
    for(int i=c[u];i<cr.size();i++) {
        ans[cr[i].second]++;
    }
}
int main() {
    scanf("%d",&n);
    int rt;
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&p[i],&c[i]);
        a[p[i]].push_back(i);
        if(p[i]==0) rt=i;
    }
    dfs(rt,0);
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}