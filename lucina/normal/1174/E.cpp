#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
void upd(int &a,int b){
    a+=b;if(a>=mod)a-=mod;
    return;
}
int add(int a, int b) {
  a += b;return a>=mod?a-mod:a;
}
int sub(int a, int b) {
  a -= b;return a<0?a+mod:a;
}
int mul(int a,int b) { return 1ll*a*b%mod; }
int power(int a,int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int dp[2][22][2],n,mp;

int cal(int i,int j){
    int res=(1<<i);
    if(j)res*=3;
    return n/res;
}

int main(){
    scanf("%d",&n);
    mp=0;
    int x=1;
    while((x<<1)<=n){
        x<<=1;
        mp++;
    }
    dp[0][mp][0]=1;
    x=0;
    if((1<<(mp-1))*3<=n)dp[0][mp-1][1]=1;
    for(int i=1;i<n;i++){
        x^=1;
        for(int j=0;j<=mp;j++){
            for(int k=0;k<2;k++){
                dp[x][j][k]=mul(dp[x^1][j][k],cal(j,k)-i);
                if(j<mp)upd(dp[x][j][k],mul(dp[x^1][j+1][k],cal(j,k)-cal(j+1,k)));
                if(k==0)upd(dp[x][j][k],mul(dp[x^1][j][k+1],cal(j,k)-cal(j,k+1)));
            }
        }
    }
    printf("%d\n",dp[x][0][0]);


}