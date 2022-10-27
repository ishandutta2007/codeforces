#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
long long n,inv[maxn],dp[15000][100];
int k,r;

long long qpow(long long u,long long v){
long long s=1;
while(v>0){
    if(v&1){
        s=s*u;
        s%=mod;
    }
    u=u*u;
    u%=mod;
    v=v>>1;
}
return s;
}
long long ss(long long p,long long q){
    memset(dp,0,sizeof(dp));
    dp[0][q]=1;
    for(int i=1;i<=k;i++){
        for(int j=q;j>=0;j--){
            dp[i][j]=dp[i][j+1]+((dp[i-1][j]*inv[j+1])%mod);
            dp[i][j]%=mod;
        }
    }
    long long s=0;
    for(int i=0;i<=q;i++){
        s+=(dp[k][i]*qpow(p,i));
        s%=mod;
    }
    return s%mod;
}

int main(){
    scanf("%lld %d",&n,&k);
    int x=sqrt(n);
    for(int i=1;i<=1000;i++)
        inv[i]=qpow(i,mod-2);
   long long ans=1;
    for(int i=2;i<=x;i++){
        if(n%i==0){
           r=0;
           while(n%i==0){
            r++;n/=i;
           }
           ans*=ss(i,r);
           ans%=mod;
        }
    }
    if(n>1)
        ans*=ss(n,1);
    ans%=mod;
    printf("%lld\n",ans);

}
/*
dp[i][j]=sum dp[i-1][k]/(k+1) from k=j to a
dp[i][j+1]=sum dp[i-1][k]/(k+1) from k=j+1 to a
dp[i][j]=dp[i][j+1]+dp[i-1][j]/(j+1)

*/