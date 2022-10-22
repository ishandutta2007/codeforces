#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n,m;
long long nm;
vector<int> a[maxn];
int d[maxn];
int ld[maxn];
int lc[maxn][20];
bool ex[2000][2000];
bool us[2000][2000];
vector<pair<int,pair<int,int> > > edg;
vector<pair<int,pair<int,int> > > oedg;
int par[maxn];
int rnk[maxn];
int co(int u) {
    if(par[u]==u) return u;
    par[u]=co(par[u]);
    return par[u];
}
vector<int> seg[4*maxn];
void process(int id,int u) {
    for(int i=0;i<seg[id].size();i++) {
        int v=co(seg[id][i]);
        par[v]=u;
    }
    seg[id].clear();
    seg[id].push_back(u);
}
void uint(int id,int l,int r,int u,int x,int y) {
    if(y<x) return;
    if(x<=l && r<=y) {
        process(id,u);
        return;
    }
    if(r<x || y<l) return;
    int m=(l+r)/2;
    uint(id*2+1,l,m,u,x,y);
    uint(id*2+2,m+1,r,u,x,y);
}
void create_seg(int id,int l,int r) {
    for(int i=l;i<=r;i++) seg[id].push_back(i);
    if(l==r) return;
    int m=(l+r)/2;
    create_seg(id*2+1,l,m);
    create_seg(id*2+2,m+1,r);
}
void compress_mst() {
    for(int i=1;i<=n;i++) {
        par[i]=i;
    }
    create_seg(0,1,n);
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(v);
        a[v].push_back(u);
        edg.push_back({w,{u,v}});
    }
    for(int i=1;i<=n;i++) {
        a[i].push_back(0);
        a[i].push_back(n+1);
        sort(a[i].begin(),a[i].end());
        for(int j=1;j<a[i].size();j++) {
            uint(0,1,n,co(i),a[i][j-1]+1,a[i][j]-1);
        }
    }
    sort(edg.begin(),edg.end());
    long long ans=0;
    for(auto eg:edg) {
        int u=co(eg.second.first);
        int v=co(eg.second.second);
        int w=eg.first;
        if(u!=v) {
            par[v]=u;
            ans=ans+w;
        }
    }
    printf("%lld",ans);
}
bool is_anc(int u,int v) {
    if(d[v]<d[u]) return false;
    int l=0;
    while(d[v]>d[u]) {
        if((d[v]-d[u])&(1<<l)) v=lc[v][l];
        l++;
    }
    return v==u;
}
int main() {
    scanf("%d %d",&n,&m);
    nm=n;
    nm=nm*(nm-1)/2;
    if(nm-m>n) {
        compress_mst();
    }
    else {
        int xo=0;
        for(int i=0;i<m;i++) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            ex[u][v]=ex[v][u]=true;
            edg.push_back({w,{u,v}});
            oedg.push_back({w,{u,v}});
            xo^=w;
        }
        for(int i=1;i<=n;i++) {
            par[i]=i;
            for(int j=1;j<i;j++) {
                if(!ex[i][j]) {
                    edg.push_back({0,{i,j}});
                }
            }
        }
        sort(edg.begin(),edg.end());
        long long ans=0;
        for(auto eg:edg) {
            int u=co(eg.second.first);
            int v=co(eg.second.second);
            int w=eg.first;
            if(u!=v) {
                int u1=eg.second.first;
                int v1=eg.second.second;
                us[u1][v1]=us[v1][u1]=true;
                a[u1].push_back(v1);
                a[v1].push_back(u1);
                par[v]=u;
                ans=ans+w;
            }
        }
        bool fn=false;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<i;j++) {
                if(!ex[i][j] && !us[i][j]) {
                    fn=true;
                }
            }
        }
        if(fn) {
            printf("%lld",ans);
        }
        else {
            long long cans=ans+xo;
            for(int i=0;i<edg.size();i++) {
                int u1=edg[i].second.first;
                int v1=edg[i].second.second;
                if(!ex[u1][v1] && n>2) {
                    ans=0;
                    for(int j=1;j<=n;j++) {
                        par[j]=j;
                        rnk[j]=1;
                    }
                    long long ans=0;
                    for(int j=0;j<edg.size();j++) {
                        if(j==i) continue;
                        pair<int,pair<int,int> > eg=edg[j];
                        int u=co(eg.second.first);
                        int v=co(eg.second.second);
                        int w=eg.first;
                        if(u!=v) {
                            if(rnk[u]>rnk[v]) {
                                par[v]=u;
                            }
                            else {
                                if(rnk[v]>rnk[u]) {
                                    par[u]=v;
                                }
                                else {
                                    par[v]=u;
                                    rnk[u]+=1;
                                }
                            }
                            ans=ans+w;
                        }
                    }
                    cans=min(cans,ans);
                }
            }
            printf("%lld",cans);
        }
    }
    return 0;
}