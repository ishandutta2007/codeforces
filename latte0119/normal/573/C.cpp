#include<bits/stdc++.h>
using namespace std;


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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}


const int SIZE=100000;
int N;
vint G[SIZE];

int deg[SIZE];
bool used[SIZE];

void dfs(int v,int p){
    if(G[v].size()>=3){
        deg[v]--;
        return;
    }
    used[v]=true;
    for(int to:G[v]){
        if(to==p)continue;
        dfs(to,v);
    }
}

signed main(){
    scanf("%d",&N);
    rep(i,N-1){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    rep(i,N)deg[i]=G[i].size();
    rep(i,N)if(G[i].size()==1)dfs(i,-1);

    rep(i,N)if(!used[i]){
        if(G[i].size()>=3){
            for(int to:G[i]){
                if(G[to].size()==3&&deg[to]==1){
                    used[to]=true;//
                    deg[i]--;
                }
            }
        }
    }

    bool ok=true;
    rep(i,N)if(!used[i])ok&=deg[i]<=2;
    if(ok)puts("Yes");
    else puts("No");

    return 0;
}