#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,K,P;
vint G[111111];

int cnt[111111];
int sum[111111];
int luz[111111];
void dfs(int v,int p,int d){
    cnt[d]++;
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v,d+1);
    }
}

signed main(){
    scanf("%lld%lld%lld",&N,&K,&P);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    dfs(0,-1,0);
    cnt[0]=0;
    for(int i=1;i<N;i++)sum[i]=sum[i-1]+cnt[i];

    for(int i=1;i<N;i++){
        luz[i]=luz[i-1]+sum[i-1];
    }

    int ans=0;
    for(int i=1;i<N;i++){
        if(sum[i]<=K&&luz[i]<=P){
            chmax(ans,sum[i]);
            continue;
        }

        int ub=i+1;
        int lb=1;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            int l=luz[i];
            l-=luz[mid-1];
            l-=sum[mid-1]*(i-mid+1);

            int s=sum[i];
            s-=sum[mid-1];
            if(s<=K&&l<=P)ub=mid;
            else lb=mid;
        }

        int l=luz[i]-luz[ub-1]-sum[ub-1]*(i-ub+1);
        int s=sum[i]-sum[ub-1];

        int tmp=INT_MAX;
        chmin(tmp,K-s);
        if(i!=lb)chmin(tmp,(P-l)/(i-lb));

        chmax(ans,s+tmp);
    }

    cout<<ans<<endl;
    return 0;
}