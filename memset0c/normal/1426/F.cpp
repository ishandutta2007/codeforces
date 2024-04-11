#include<bits/stdc++.h>
const int N=2e5+10,mod=1e9+7;
int n;
long long f[N][5];
char s[N];
long long calc(int a,int b,int c){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=3;j++)f[i][j]=f[i-1][j];
    if(s[i]==a){
      f[i][1]++;
    }
    if(s[i]==b){
      f[i][2]+=f[i-1][1];
    }
    if(s[i]==c){
      f[i][3]+=f[i-1][2];
    }
    for(int j=1;j<=3;j++)f[i][j]%=mod;
  }
  return f[n][3];
}
int main(){
  scanf("%d%s",&n,s+1);
  long long mul=1;
  long long inv=(mod+1)/3;
  for(int i=1;i<=n;i++)if(s[i]=='?')mul=mul*3%mod;
  long long ans=0;
  ans=(ans+calc('a','b','c')*mul);
  ans=(ans+calc('?','b','c')*mul%mod*inv)%mod;
  ans=(ans+calc('a','?','c')*mul%mod*inv)%mod;
  ans=(ans+calc('a','b','?')*mul%mod*inv)%mod;
  ans=(ans+calc('?','?','c')*mul%mod*inv%mod*inv)%mod;
  ans=(ans+calc('a','?','?')*mul%mod*inv%mod*inv)%mod;
  ans=(ans+calc('?','b','?')*mul%mod*inv%mod*inv)%mod;
  ans=(ans+calc('?','?','?')*mul%mod*inv%mod*inv%mod*inv)%mod;
  printf("%lld\n",ans);
}