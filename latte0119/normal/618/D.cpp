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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=200000;

int n,x,y;
vint g[SIZE];

int dp[SIZE][2];

void dfs(int v,int p){
    int sum=0;
    int delta1=INT_MAX,delta2=INT_MAX;
    rep(i,g[v].size()){
        int u=g[v][i];
        if(u==p)continue;
        dfs(u,v);
        sum+=dp[u][1];
        int d=dp[u][1]-dp[u][0];
        if(d<delta1){
            delta2=delta1;
            delta1=d;
        }
        else if(d<delta2){
            delta2=d;
        }
    }
    dp[v][0]=max(sum,sum+1-delta1);
    dp[v][1]=max(dp[v][0],sum+2-delta1-delta2);
}

signed main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin>>n>>x>>y;
    rep(i,n-1){
        int v,u;
        cin>>v>>u;
        v--;u--;
        g[v].pb(u);
        g[u].pb(v);
    }

    if(x>=y){
        bool f=false;
        rep(i,n)f|=(g[i].size()==n-1);
        if(f)cout<<(n-2)*y+x<<endl;
        else cout<<(n-1)*y<<endl;
        return 0;
    }

    dfs(0,-1);
    cout<<dp[0][1]*x+(n-dp[0][1]-1)*y<<endl;
    return 0;
}