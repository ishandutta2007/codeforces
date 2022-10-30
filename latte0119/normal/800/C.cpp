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

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }else{
        x=1;y=0;
    }
    return d;
}

int mod_inverse(int a,int m){
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}

int N,M;
bool isban[222222];

vint d;
vint lis[222222];


signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N){
        int a;
        scanf("%lld",&a);
        isban[a]=true;
    }

    for(int i=1;i<=M;i++){
        if(M%i==0)d.pb(i);
    }

    for(int i=0;i<M;i++){
        if(isban[i])continue;
        int tmp=gcd(i,M);
        lis[tmp].pb(i);
    }

    vint dp(d.size(),INT_MIN);
    vint pre(d.size());
    dp[0]=0;
    for(int i=0;i<d.size();i++){
        dp[i]+=lis[d[i]].size();
        for(int j=i+1;j<d.size();j++){
            if(d[j]%d[i])continue;
            if(dp[j]<dp[i]){
                dp[j]=dp[i];
                pre[j]=i;
            }
        }
    }

    int ma=0;
    rep(i,d.size())if(dp[i]>dp[ma])ma=i;

    vint ans;
    while(true){
        for(auto u:lis[d[ma]])ans.pb(u);
        if(ma==0)break;
        ma=pre[ma];
    }
    reverse(all(ans));

    int now=1;
    int nowgcd=1;

    vint ansans;
    for(int i=0;i<ans.size();i++){
        int x=now/nowgcd;
        int y=ans[i]/nowgcd;
        int z=y*mod_inverse(x,M/nowgcd)%(M/nowgcd);
        ansans.pb(z);
        now=ans[i];
        nowgcd=gcd(now,M);
    }

    printf("%lld\n",(int)ansans.size());
    rep(i,ansans.size())printf("%lld ",ansans[i]);
    puts("");
    return 0;
}