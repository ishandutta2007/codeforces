#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuck
#define y0 fuxk
#define y1 fxck
#define x1 fxxk
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=0x3f3f3f3f,MOD=1e9+7;
const ld eps=1e-9;
ll n;int k;
int dp[64][10005];
int rev[100],ans;
int pw(int x,int y){
    int s=1;
    for(;y;y>>=1,x=1ll*x*x%MOD)
        if(y&1)s=1ll*s*x%MOD;
    return s;
}
int sol(int x,int y){
    for(int i=y;i>=0;--i)
        for(int j=k;j>=0;--j)
            dp[i][j]=0;
    dp[y][k]=1;
    for(int i=y;i>=0;--i)
        for(int j=k;j>=1;--j)
            for(int p=i;p>=0;--p)
                dp[p][j-1]=(dp[p][j-1]+1ll*dp[i][j]*rev[i+1])%MOD;
    int ret=0;
    for(int i=0;i<=y;++i)ret=(ret+1ll*pw(x,i)*dp[i][0])%MOD;
    //printf("%d %d %d\n",x,y,ret);
    return ret;
}
int main(){
    rep(i,99)rev[i]=pw(i,MOD-2);
    scanf("%lld%d",&n,&k);
    ans=1;
    for(int i=2;1ll*i*i<=n;++i)if(n%i==0){
        int cnt=0;
        while(n%i==0)n/=i,++cnt;
        ans=1ll*ans*sol(i,cnt)%MOD;
    }
    if(n>1)ans=1ll*ans*sol(n%MOD,1)%MOD;
    printf("%d\n",ans);
}