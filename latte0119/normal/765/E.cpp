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

int N;
vint G[222222];

int dp[222222];
void dfs(int v,int p){
    if(G[v].size()==1){
        dp[v]=1;
        return;
    }

    int mi=INT_MAX,ma=-1;
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v);
        if(dp[u]==-1){
            dp[v]=-1;
        }
        chmin(mi,dp[u]);
        chmax(ma,dp[u]);
    }
    if(dp[v]==-1||mi!=ma)dp[v]=-1;
    else dp[v]=mi+1;
}

int ans;
void dfs2(int v,int p,int s){
    if(G[v].size()==1)return;

    map<int,int>cnt;
    if(s!=-2)cnt[s]++;
    for(auto u:G[v]){
        if(u==p)continue;
        cnt[dp[u]]++;
    }

    if(cnt.find(-1)==cnt.end()&&cnt.size()<=2){
        int t;
        if(cnt.size()==1){
            t=cnt.begin()->fi;
        }
        else{
            t=cnt.begin()->fi;
            t+=cnt.rbegin()->fi;
        }
        while(t%2==0)t/=2;
        chmin(ans,t);
    }

    for(auto u:G[v]){
        if(u==p)continue;
        cnt[dp[u]]--;
        if(cnt[dp[u]]==0)cnt.erase(dp[u]);
        if(cnt.find(-1)==cnt.end()&&cnt.size()==1){
            int t=cnt.begin()->fi;
            dfs2(u,v,t+1);
        }
        cnt[dp[u]]++;
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    if(N==2){
        puts("1");
        return 0;
    }


    int r=-1;
    rep(i,N)if(G[i].size()>1)r=i;
    assert(r>=0);
    dfs(r,-1);
    ans=INT_MAX;
    dfs2(r,-1,-2);

    if(ans==INT_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}