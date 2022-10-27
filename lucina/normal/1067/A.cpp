#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
void minun(int &a,int b){
    a-=b; if(a<0)a+=mod; return;
}
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}
int dp[202][2],s[202][2],n,pre,x,a;
///dp[i][j][k] means the number of ways to restore such that i-th element==j and k=1 means a[i]>=a[i-1]| else k==1 else k=0


int main(){
    scanf("%d",&n);
    scanf("%d",&pre);
    /// think again dp[i][j][k]
    /// the number of ways to restore such that "a[i]>=a[i-1]"
    if(pre==-1){
        for(int j=1;j<=200;j++)
            dp[j][0]=1;
    }
    else{
        dp[pre][0]=1;
    }
    for(int i=1;i<=200;i++)
        for(int k=0;k<2;k++)
        s[i][k]=s[i-1][k]+dp[i][k];
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=200;j++){
                /// 0 need 1 satisfied
            if(j==x||x==-1){
                /// if 0 mean we add something > previous element
                /// in other words a[i]>a[i-1]
                ///a[n]<=a[n-1]
                ///plusle(dp[j][0],add(s[j-1][0],s[j-1][1]));
                /// if 1 mean we add something <= previous element
                /// so it must be already satisfied or
                /// not satisfied so you must add
                ///plusle(dp[j][1],add(s[200][1]))
                /// ok let's ignore above part maybe I'm broken in dp
                /// ah think again
                /// we define 0 as we need something that >= previous element
                /// we define 1 as the previous element already <= previous previous of it
                plusle(dp[j][0],add(s[j-1][0],s[j-1][1]));///hope it's correct
                ///oops may not be enough
                /// ok look at definition above
                /// so we must add something <= previous element
                plusle(dp[j][1],sub(s[200][1],s[j-1][1]));
                /// we must add only dp^1[j][0]? why?
                /// the answer is that k>last so we must add something >=k
                ///but the fact that 1 means <=k so the only thing we have to add is k
                ///stupid dp but took me many hours hope to get AC in first attempt
                plusle(dp[j][1],sub(s[j][0],s[j-1][0]));
            }
        }
        s[0][0]=0;s[0][1]=0;
        for(int j=1;j<=200;j++){
            for(int k=0;k<2;k++)
            s[j][k]=add(s[j-1][k],dp[j][k]);
        }
    }
    printf("%d\n",s[200][1]);
}