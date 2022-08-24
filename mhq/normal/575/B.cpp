#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int base=1e9+7;
const int maxn=2e5;
int up[maxn][19];
int hg[maxn];
int fd[maxn],fu[maxn],a[maxn*6];
int n,m,x,y,z;
int ans=0;
vector<pair<int,int> > ed[maxn];
void dfs(int x, int y, int h) {
    up[x][0]=y;
    hg[x]=h;
    for (int i=0;i<ed[x].size();i++) {
        int to=ed[x][i].first;
        if (to==y) continue;
        dfs(to,x,h+1);
    }
}
int pw[maxn*11];
int lca(int x, int y) {
    if (hg[x]<hg[y]) swap(x,y);
    for (int i=18;i>=0;i--)
        if (hg[up[x][i]]>=hg[y]) x=up[x][i];
    for (int i=18;i>=0;i--)
        if (up[x][i]!=up[y][i]) {
            x=up[x][i];
            y=up[y][i];
        }
    if (x==y) return x;
    return up[x][0];
}
void dfs2(int x, int y, int z) {
    for (int i=0;i<ed[x].size();i++) {
        int to=ed[x][i].first;
        if (to==y) continue;
        dfs2(to,x,ed[x][i].second);
        fd[x]+=fd[to];
        fu[x]+=fu[to];
        if (ed[x][i].second==1) {
            ans=(ans+pw[fd[to]]-1)%base;
            if (ans<0) ans+=base;
            if (ans>=base) ans-=base;
        }
        if (ed[x][i].second==0) {
            ans=(ans+pw[fu[to]]-1)%base;
            if (ans<0) ans+=base;
            if (ans>=base) ans-=base;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    for (int i=1;i<=n-1;i++) {
        scanf("%d%d%d",&x,&y,&z);
        if (z==0) {
            ed[x].push_back(make_pair(y,2));
            ed[y].push_back(make_pair(x,2));
        }
        else {
            ed[x].push_back(make_pair(y,1));
            ed[y].push_back(make_pair(x,0));
        }
    }
    pw[0]=1;
    for (int i=1;i<=2000000;i++) {
        pw[i]=(pw[i-1]+pw[i-1]);
        if (pw[i]>=base) pw[i]-=base;
    }
    dfs(1,0,1);
    for (int j=1;j<=18;j++)
    for (int i=1;i<=n;i++) up[i][j]=up[up[i][j-1]][j-1];
    scanf("%d",&m);
    a[0]=1;
    for (int i=1;i<=m;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<m;i++) {
        int x=a[i];
        int y=a[i+1];
        int lc=lca(x,y);
        fd[lc]--;
        fd[x]++;
        fu[lc]--;
        fu[y]++;
    }
    dfs2(1,0,-1);
    printf("%d",ans);
    return 0;
}