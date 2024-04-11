#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[200000];
int ans[200000];
int fst[200000];
vector<pair<int,pair<int,int> > > dq[100005][40];
int bg[100005][40];
bool agree(int t,int nmod,int nrem,int omod,int orem) {
    if(nmod==omod) return nrem==orem;
    else {
        if(nmod<omod) return nrem==(orem%nmod);
        else return (nrem%omod)==orem;
    }
}
void fix(int j,int l,int u,int i) {
    for(int t=2;t*t<=l;t++) {
        int c=1;
        while(l%t==0) {
            c*=t;
            l/=t;
        }
        if(c!=1) {
            int r=j%c;
            while(bg[u][t]<dq[u][t].size() && !agree(t,dq[u][t][bg[u][t]].first,dq[u][t][bg[u][t]].second.first,c,r)) {
                fst[u]=max(fst[u],dq[u][t][bg[u][t]].second.second+1);
                bg[u][t]++;
            }
            while(bg[u][t]<dq[u][t].size()&& c>dq[u][t].back().first) dq[u][t].pop_back();
            dq[u][t].push_back({c,{r,i}});
        }
    }
    if(l!=1) {
        int c=l,t=l,r=j%l;
        while(bg[u][t]<dq[u][t].size() && !agree(t,dq[u][t][bg[u][t]].first,dq[u][t][bg[u][t]].second.first,c,r)) {
            fst[u]=max(fst[u],dq[u][t][bg[u][t]].second.second+1);
            bg[u][t]++;
        }
        while(bg[u][t]<dq[u][t].size()&& c>dq[u][t].back().first) dq[u][t].pop_back();
        dq[u][t].push_back({c,{r,i}});;
    }
    if(fst[u]==-1) fst[u]=i;
    //cout<<i<<" "<<j<<" "<<u<<" "<<fst[u]<<endl;
    ans[u]=max(ans[u],i-fst[u]+1);
}
void clr(int i) {
    if(i==0) return;
    for(int j=0;j<a[i-1].size();j++) {
        bool fnd=false;
        for(int t=0;t<a[i].size();t++) {
            if(a[i][t]==a[i-1][j]) {
                fnd=true;
                break;
            }
        }
        if(!fnd) {
            fst[a[i-1][j]]=-1;
            for(int t=0;t<40;t++) {
                dq[a[i-1][j]][t].clear();
                bg[a[i-1][j]][t]=0;
            }
        }
    }
}
void solve(int i) {
    clr(i);
    for(int j=0;j<a[i].size();j++) {
        fix(j,a[i].size(),a[i][j],i);
    }
}
int main() {
    scanf("%d %d",&n,&m);
    int k;
    for(int i=0;i<n;i++) {
        scanf("%d",&k);
        int t;
        for(int j=0;j<k;j++) {
            scanf("%d",&t);
            a[i].push_back(t);
        }
    }
    for(int i=1;i<=m;i++) fst[i]=-1;
    for(int i=0;i<n;i++) solve(i);
    for(int i=1;i<=m;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}