#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
long long dp[maxn][4],l,r,n,f[4],u,v;
int main(){
    scanf("%lld %lld %lld",&n,&l,&r);
    u=l;v=r;
    while(((u%3)+3)%3!=0)
        u++;
    while(((v%3)+3)%3!=0)
        v--;
    f[0]=(v-u)/3+1;
   // printf("%d %d\n",u,v);
    u=l;v=r;
    while(((u%3)+3)%3!=1)
        u++;
    while(((v%3)+3)%3!=1)
        v--;
   // printf("%d %d\n",u,v);
    f[1]=(v-u)/3+1;
    u=l;v=r;
    while(((u%3)+3)%3!=2)
        u++;
    while(((v%3)+3)%3!=2)
        v--;
   // printf("%d %d\n",u,v);
    f[2]=(v-u)/3+1;
 //   cout<<"BUG"<<" KUY";
    for(int i=0;i<3;i++){
   // printf("%d ",f[i]);
    dp[1][i]=f[i];
    }
   // printf("\n");
    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][0]*f[0])+(dp[i-1][1]*f[2])+(dp[i-1][2]*f[1]);
        dp[i][0]%=mod;
        dp[i][1]=(dp[i-1][0]*f[1])+(dp[i-1][1]*f[0])+(dp[i-1][2]*f[2]);
        dp[i][1]%=mod;
        dp[i][2]=(dp[i-1][0]*f[2])+(dp[i-1][1]*f[1])+(dp[i-1][2]*f[0]);
        dp[i][2]%=mod;
    }
    printf("%lld\n",dp[n][0]%mod);
}