#include<bits/stdc++.h>
using namespace std;
const int manx=3e5+10;
const int mod=1000000007;//
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
void minun(int &a,int b){
    a-=b; if(a<0)a+=mod; return;
}
int add(int a,int b) {
  a+=b;
  return a>=mod?a-mod:a;
}
int sub(int a,int b) {
  a-=b;
  return a<0?a+mod:a;
}
int mul(int a,int b) {
  return (int)((long long)a*b%mod);
}
int power(int a,int b) {
  int res=1;
  while (b>0) {
    if (b&1) {
      res=mul(res,a);
    }
    a=mul(a,a);
    b>>=1;
  }
  return res;
}
bool isprime(int x){
    for(int j=(int)sqrt(x);j>=2;j--){
        if(x%j==0)return false;
    }
    return true;
}
int n,x,ct[75],f[75];
map<int,int> p;
int dp[2][(1<<19)];

int main(){
    scanf("%d",&n);
    int id=0;
    for(int i=2;i<=70;i++){
        if(isprime(i)){
            p[i]=id++;
        }
    }
    while(n--){
        scanf("%d",&x);
        ct[x]++;
    }
    for(x=1;x<=70;x++){
        int msk=0;
        int y=x;
        for(int i=2;i<=y;i++){
            if(y%i==0){
            int s=0;
                while(y%i==0){
                    s^=1;
                    y/=i;
                }
            if(s)
                msk|=(1<<p[i]);
            }
        }
        f[x]=msk;
    }
    x=0;
    dp[0][0]=1;
    int p2[100005];
    p2[0]=1;
    for(int j=1;j<=100000;j++)
    p2[j]=add(p2[j-1],p2[j-1]);
    for(int i=1;i<=70;i++){
        if(ct[i]==0){
        for(int msk=0;msk<(1<<19);msk++){
            dp[x^1][msk]=dp[x][msk];
        }
        }
        else{
        for(int msk=0;msk<(1<<19);msk++){
            dp[x^1][msk]=add(mul(dp[x][msk],p2[ct[i]-1]),mul(dp[x][msk^f[i]],p2[ct[i]-1]));
        }
        }
        x^=1;
    }
    printf("%d\n",sub(dp[x][0],1));

}