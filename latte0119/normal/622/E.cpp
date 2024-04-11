#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=500000;

int N;
vint G[SIZE];

vint vs;
int dep[SIZE],par[SIZE];
void dfs(int v){
    vint st;
    st.pb(v);
    vs.pb(v);
    dep[v]=0;
    par[v]=0;
    rep(i,st.size()){
        int u=st[i];
        rep(j,G[u].size()){
            int to=G[u][j];
            if(to==par[u])continue;
            par[to]=u;
            dep[to]=dep[u]+1;
            st.pb(to);
            vs.pb(to);
        }
    }
}

int solve(int s){
    vs.clear();
    dfs(s);
    vint ds;
    rep(i,vs.size()){
        int v=vs[i];
        if(G[v].size()==1)ds.pb(dep[v]);
    }
    sort(all(ds));
    rep(i,ds.size()-1){
        if(ds[i]>=ds[i+1]){
            ds[i+1]=ds[i]+1;
        }
    }
    return ds.back()+1;
}

signed main(){
    scanf("%d",&N);
    rep(i,N-1){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    int ma=0;
    rep(i,G[0].size())chmax(ma,solve(G[0][i]));
    printf("%d\n",ma);
    return 0;
}