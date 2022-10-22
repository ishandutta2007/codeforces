#include<bits/stdc++.h>
using namespace std;
int n,k,r;
vector<int> a[500000];
vector<int> b[500000];
int lc[500000][22];
int d[500000];
int s[500000];
int cp[500000];
int rcmp[500000];
vector<int> ncomp[500000];
int ds[500000];
bool vis[500000];
void dfs(int u,int p=1) {
    lc[u][0]=p;
    for(int k=1;k<22;k++) {
        lc[u][k]=lc[lc[u][k-1]][k-1];
    }
    for(auto v:a[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            dfs(v,u);
        }
    }
}
void tv(int u,int c) {
    rcmp[u]=c;
    vis[u]=true;
    for(auto v:b[u]) {
        if(!vis[v]) {
            tv(v,c);
        }
    }
    vis[u]=false;
}
int lca(int u,int v) {
    if(d[u]>d[v]) swap(u,v);
    int k=0;
    while(d[v]>d[u]) {
        if(((d[v]-d[u])&(1<<k))==(1<<k)) {
            v=lc[v][k];
        }
        k++;
    }
    //cout<<u<<" "<<v<<endl;
    k=21;
    while(u!=v) {
        while(k>0 && lc[u][k]==lc[v][k]) k--;
        if(k==-1) return lc[u][0];
        u=lc[u][k];
        v=lc[v][k];
    }
    return u;
}
int dist(int u,int v) {
    return d[u]+d[v]-2*d[lca(u,v)];
}
int lift(int u,int db) {
    int k=0;
    while((1<<k)<=db) {
        if(db&(1<<k)) {
            u=lc[u][k];
        }
        k++;
    }
    return u;
}
queue<pair<int,int> > q;
void stops() {
    for(int i=1;i<=r;i++) {
        vis[s[i]]=true;
        ds[s[i]]=0;
        cp[s[i]]=i;
        q.push({s[i],i});
    }
    int u,c;
    while(!q.empty()) {
        u=q.front().first;
        c=q.front().second;
        q.pop();
        for(auto v:a[u]) {
            if(!vis[v]) {
                vis[v]=true;
                ds[v]=ds[u]+1;
                cp[v]=c;
                q.push({v,c});
            }
        }
    }
    for(int i=1;i<=n;i++) vis[i]=false;
}
void comps() {
    for(int i=1;i<=r;i++) vis[i]=false;
    for(int u=1;u<=n;u++) {
        for(auto v:a[u]) {
            //cout<<u<<" "<<v<<" "<<cp[u]<<" "<<cp[v]<<" "<<ds[u]+1+ds[v]<<endl;
            if(cp[u]!=cp[v] && ds[u]+1+ds[v]<=2*k) {
                //cout<<"ok"<<endl;
                b[cp[u]].push_back(cp[v]);
            }
        }
    }
    int cc=1;
    for(int i=1;i<=r;i++) {
        if(rcmp[i]==0) {
            tv(i,cc);
            cc++;
        }
    }
}
int main() {
    scanf("%d %d %d",&n,&k,&r);
    int x,y;
    for(int i=1;i<=n-1;i++) {
        scanf("%d %d",&x,&y);
        a[x].push_back(n+i);
        a[n+i].push_back(x);
        a[n+i].push_back(y);
        a[y].push_back(n+i);
    }
    n+=(n-1);
    dfs(1,1);
    for(int i=1;i<=r;i++) {
        scanf("%d",&s[i]);
    }
    stops();
    comps();
    int v;
    scanf("%d",&v);
    while(v--) {
        scanf("%d %d",&x,&y);
        int z=lca(x,y);
        //cout<<z<<endl;
        //return 0;
        int dis=dist(x,y);
        if(dis<=2*k) {
            printf("YES\n");
        }
        else {
            int kx=d[x]-d[z];
            int ky=d[y]-d[z];
            int px,py;
            if(kx>=k) px=lift(x,k);
            else px=lift(y,dis-k);
            if(ky>=k) py=lift(y,k);
            else py=lift(x,dis-k);
            /*cout<<kx<<" "<<ky<<" "<<x<<" "<<y<<endl;
            cout<<px<<" "<<py<<" "<<ds[px]<<" "<<ds[py]<<" "<<cp[px]<<" "<<cp[py]<<" "<<rcmp[cp[px]]<<" "<<rcmp[cp[py]]<<endl;*/
            if(rcmp[cp[px]]==rcmp[cp[py]] && ds[px]<=k && ds[py]<=k) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}