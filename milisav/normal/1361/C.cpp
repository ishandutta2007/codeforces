#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 4000000
using namespace std;
int n;
int m;
int a[maxn];
int b[maxn];
int p[maxn];
int ce[maxn];
vector<pair<int,int> > gf[maxn];
bool vis[maxn];
bool ep[maxn];
int ei[maxn];
int ni[maxn];
int si[maxn];
int oi[maxn];
int ec=0;
int tk=1;
int eu[maxn];
int ev[maxn];
vector<pair<int,int> > cv;
stack<int> st;
int ans[maxn];
int ac=0;
void dfs() {
    st.push(1);
    while(!st.empty()) {
        int u=st.top();
        st.pop();
        while(ce[u]<gf[u].size() && ep[gf[u][ce[u]].second]) ce[u]++;
        if(ce[u]==gf[u].size()) {
            ans[ac++]=u;
        }
        else {
            st.push(u);
            st.push(gf[u][ce[u]].first);
            ep[gf[u][ce[u]].second]=true;
        }
    }
}
bool pos(int l) {
    if(l==0) {
        for(int i=1;i<=2*n;i++) p[i]=i;
        return true;
    }
    for(int i=0;i<maxn;i++) {
        gf[i].clear();
        vis[i]=false;
        ce[i]=0;
    }
    ec=0;
    tk=1;
    ac=0;
    for(int i=1;i<=n;i++) {
        ec++;
        gf[2*i-1].push_back({2*i,ec});
        gf[2*i].push_back({2*i-1,ec});
        eu[ec]=2*i-1;
        ev[ec]=2*i;
        ec++;
        gf[2*i-1].push_back({m+(a[i]&((1<<l)-1)),ec});
        gf[m+(a[i]&((1<<l)-1))].push_back({2*i-1,ec});
        eu[ec]=2*i-1;
        ev[ec]=m+(a[i]&((1<<l)-1));
        ec++;
        gf[2*i].push_back({m+(b[i]&((1<<l)-1)),ec});
        gf[m+(b[i]&((1<<l)-1))].push_back({2*i,ec});
        eu[ec]=2*i;
        ev[ec]=m+(b[i]&(1<<(l-1)));
    }
    for(int i=0;i<maxn;i++) {
        int k=gf[i].size();
        if(k&1) return false;
    }
    dfs();
    bool ok=true;
    for(int i=1;i<=ec;i++) {
        if(!ep[i]) ok=false;
        ep[i]=false;
    }
    if(!ok) return false;
    int j=1;
    for(int i=0;i<ac;i++) {
        if(ans[i]<=2*n) {
            p[j]=ans[i];
            j++;
        }
    }
    if((p[1]%2==0 && p[2]!=p[1]-1) || (p[1]%2==1 && p[2]!=p[1]+1)) {
        for(int i=0;i<2*n;i++) p[i]=p[i+1];
        p[2*n]=p[0];
    }
    return true;
}
int main() {
    scanf("%d",&n);
    m=2*n+1;
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int l=20;l>=0;l--) {
        if(pos(l)) {
            printf("%d\n",l);
            for(int i=1;i<=2*n;i++) {
                printf("%d ",p[i]);
            }
            return 0;
        }
    }
	return 0;
}