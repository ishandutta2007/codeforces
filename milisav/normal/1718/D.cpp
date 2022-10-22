#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int t;
int n,q;
int p[maxn];
int ip[maxn];
int a[maxn];
int s[maxn];
int pmax[maxn];
int nmax[maxn];
vector<pair<int,int> > ev;
vector<int> ch[maxn];
bool ans[maxn];
bool vis[maxn];
bool open[maxn];
int par[maxn];
int mx[maxn];
priority_queue<pair<int,int> > op;
int bins(int t) {
    for(int i=0;i<n;i++) {
        vis[i]=open[i]=false;
    }
    open[ip[n]]=true;
    while(!op.empty()) op.pop();
    if(a[ip[n]]==0) op.push({mx[ip[n]],ip[n]});
    int cnt=0;
    int ad=1;
    int id=0;
    for(int i=0;i<ev.size();i++) {
        if(t>=ev[i].first && ad==1) {
            if(op.empty()) return 1;
            int u=op.top().second;
            op.pop();
            for(auto v:ch[u]) {
                open[v]=true;
                if(a[v]==0) op.push({mx[v],v});
            }
            ad=0;
        }
        if(ev[i].second==-1) {
            if(op.empty()) return 1;
            int u=op.top().second;
            op.pop();
            for(auto v:ch[u]) {
                open[v]=true;
                if(a[v]==0) op.push({mx[v],v});
            }
        }
        else {
            int u=ev[i].second;
            if(!open[u]) return 1-2*ad;
            for(auto v:ch[u]) {
                open[v]=true;
                if(a[v]==0) op.push({mx[v],v});
            }
        }
    }
    if(ad==1) {
        if(op.empty()) return 1;
        int u=op.top().second;
        op.pop();
        for(auto v:ch[u]) {
            open[v]=true;
            if(a[v]==0) op.push({mx[v],v});
        }
        ad=0;
    }
    return 0;
}
int cnt;
void dfs(int u) {
    mx[u]=a[u];
    cnt++;
    for(auto v:ch[u]) {
        dfs(v);
        mx[u]=max(mx[u],mx[v]);
        assert(p[u]>p[v]);
    }
}
int main() {
    scanf("%d",&t);
    int acnt=1;
    while(t--) {
        scanf("%d %d",&n,&q);
        cnt=0;
        ev.clear();
        for(int i=0;i<n;i++) {
            ch[i].clear();
            scanf("%d",&p[i]);
            ip[p[i]]=i;
            vis[i]=false;
        }
        for(int i=0;i<n;i++) {
            pmax[i]=i-1;
            while(pmax[i]!=-1 && p[pmax[i]]<p[i]) pmax[i]=pmax[pmax[i]];

        }
        for(int i=n-1;i>=0;i--) {
            nmax[i]=i+1;
            while(nmax[i]!=n && p[nmax[i]]<p[i]) nmax[i]=nmax[nmax[i]];
        }
        for(int i=0;i<n;i++) {
            if(pmax[i]==-1) {
                if(nmax[i]!=n) {
                    ch[nmax[i]].push_back(i);
                    par[i]=nmax[i];
                }
            }
            else {
                if(nmax[i]==n) {
                    ch[pmax[i]].push_back(i);
                    par[i]=pmax[i];
                }
                else {
                    if(p[pmax[i]]<p[nmax[i]]) {
                        ch[pmax[i]].push_back(i);
                        par[i]=pmax[i];
                    }
                    else {
                        ch[nmax[i]].push_back(i);
                        par[i]=nmax[i];
                    }
                }
            }
        }
        par[ip[n]]=-1;
        int k=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            if(a[i]==0) k++;
            else {
                ev.push_back({a[i],i});
            }
        }
        for(int i=1;i<=k-1;i++) {
            scanf("%d",&s[i]);
            ev.push_back({s[i],-1});
        }
        sort(ev.begin(),ev.end());
        reverse(ev.begin(),ev.end());
        dfs(ip[n]);
        assert(cnt==n);
        int l=0,r=1e6;
        int x,y;
        while(l<r) {
            int m=(l+r)/2;
            if(bins(m)<0) l=m+1;
            else r=m;
        }
        x=l;
        while(x<=1e6 && bins(x)<0) x++;
        l=0,r=1e6;
        while(l<r) {
            int m=(l+r+1)/2;
            if(bins(m)>0) r=m-1;
            else l=m;
        }
        y=l;
        while(y>=0 && bins(y)>0) y--;
        for(int i=0;i+1<ev.size();i++) {
            //assert(bins(ev[i].first)>=bins(ev[i].second));
        }
        //assert(x>y || (bins(x)<=bins(y)));
        /*if(x<=y && bins(x)>bins(y)) {
            assert(bins(y)==-1);
        }*///cout<<x<<" "<<y<<" "<<ok<<endl;
        for(int i=0;i<q;i++) {
            int d;
            scanf("%d",&d);
            if(x<=d && d<=y) printf("YES\n");
            else printf("NO\n");
            acnt++;
        }
    }
    return 0;
}