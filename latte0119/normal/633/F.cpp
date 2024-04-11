#include<bits/stdc++.h>
using namespace std;

#define int long long
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

const int SIZE=111111;
int N;
int A[SIZE];
vint G[SIZE];

int far[3][SIZE],tho[SIZE],tho_far[3][SIZE];
int ans;

inline void in(int a[3][SIZE],int v,int f){
    if(a[2][v]>=f)return;
    a[2][v]=f;
    for(int i=2;i>0;i--){
        if(a[i][v]>a[i-1][v])swap(a[i][v],a[i-1][v]);
    }
}

void dfs(int v,int p){
    for(auto to:G[v]){
        if(to==p)continue;
        dfs(to,v);
        in(far,v,far[0][to]+A[to]);
        in(tho_far,v,tho[to]);
        chmax(tho[v],tho[to]);
    }
    chmax(tho[v],far[0][v]+far[1][v]+A[v]);
    chmax(ans,tho_far[0][v]+tho_far[1][v]);
}

void dfs2(int v,int p,int f3){
    in(far,v,f3);
    for(auto to:G[v]){
        if(to==p)continue;
        bool ok=false;
        int cnt=0;
        int tmp=tho[to]+A[v];
        rep(i,3){
            if(!ok&&far[0][to]+A[to]==far[i][v]){
                ok=true;
            }
            else if(cnt<2){
                tmp+=far[i][v];
                cnt++;
            }
        }
        chmax(ans,tmp);
        dfs2(to,v,(far[0][to]+A[to]!=far[0][v]?far[0][v]:far[1][v])+A[v]);
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    dfs(0,-1);
    dfs2(0,-1,0);
    cout<<ans<<endl;
    return 0;
}