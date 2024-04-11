#include<bits/stdc++.h>
using namespace std;
const int maxn=2005,mod=1e9+7;
int sum,ans;
pair<int,bool> dp[maxn][maxn];
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod;return;
}
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
int n;
int main(){
    scanf("%d",&n);
    n*=2;
    dp[0][0]=make_pair(0,true);
    for(int len=1;len<=n;len++){
        for(int bal=0;bal<=n;bal++){
            int sum=0;
            bool free=false;
            if(bal>0){
                plusle(sum,dp[len-1][bal-1].first);
                free|=(dp[len-1][bal-1].second);
            }
            if(bal+1<=len-1){
                plusle(sum,dp[len-1][bal+1].first);
                free|=(dp[len-1][bal+1].second);
            }
            dp[len][bal]=free?make_pair(add(sum,1),false):make_pair(sum,true);
        }
    }

    printf("%d\n",dp[n][0].first);
}