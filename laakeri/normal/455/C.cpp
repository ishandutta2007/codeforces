#include <iostream>
#include <vector>

using namespace std;

int re[400000];

int md[400000];

int mmd[400000];

int pa[400000];
int pax[400000];
int spa[400000];

int s[400000];

int used2[400000];

int pr[400000];

vector<int> g[400000];

int dfs2 (int x){
    if (used2[x]) return -1;
    used2[x]=1;
    for (int nx:g[x]){
        int asd=1+dfs2(nx);
        if (asd>pa[x]){
            spa[x]=pa[x];
            pa[x]=asd;
            pax[x]=nx;
        }
        else if (asd>spa[x]){
            spa[x]=asd;
        }
    }
    return pa[x];
}

int dfs1 (int x, int a, int p){
    if (re[x]) return 0;
    re[x]=a;
    s[a]++;
    md[x]=max(p, pa[x]);
    mmd[a]=min(md[x], mmd[a]);
    pr[a]=max(pr[a], md[x]);
    //cout<<x<<" "<<p<<" "<<pa[x]<<" "<<spa[x]<<" "<<pax[x]<<" "<<md[x]<<endl;
    for (int nx:g[x]){
        if (nx!=pax[x]){
            dfs1(nx, a, max(pa[x]+1, p+1));
        }
        else{
            dfs1(nx, a, max(spa[x]+1, p+1));
        }
    }
}

int u[400000];
int us[400000];

int geta (int x){
    if (u[x]!=x){
        return geta(u[x]);
    }
    return x;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        mmd[i]=99999999;
        u[i]=i;
        us[i]=1;
    }
    for (int i=1;i<=n;i++){
        dfs2(i);
    }
    for (int i=1;i<=n;i++){
        dfs1(i, i, 0);
    }
    for (int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b;
        if (a==1){
            cout<<pr[geta(re[b])]<<'\n';
        }
        if (a==2){
            cin>>c;
            int rb=geta(re[b]);
            int rc=geta(re[c]);
            if (rb!=rc){
                int nmmd;
                if (mmd[rb]<mmd[rc]){
                    nmmd=mmd[rc];
                }
                else if (mmd[rc]<mmd[rb]){
                    nmmd=mmd[rb];
                }
                else{
                    nmmd=mmd[rb]+1;
                }
                int npr=max(max(pr[rb], pr[rc]), mmd[rb]+mmd[rc]+1);
                if (us[rb]<us[rc]){
                    us[rc]+=us[rb];
                    u[rb]=rc;
                    pr[rc]=npr;
                    mmd[rc]=nmmd;
                }
                else{
                    us[rb]+=us[rc];
                    u[rc]=rb;
                    pr[rb]=npr;
                    mmd[rb]=nmmd;
                }
            }
        }
    }
}