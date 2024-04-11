#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define LIM 60
#define M 51123987

int ab(int x){if(x<0) return -x; return x;}

int dp[8][LIM][LIM][LIM];
char in[LIM]; int len;

int main(){
  int i,j,k,l,m,n,r,res,sum,lim;
  int a,b,c;

  rep(m,8) rep(i,LIM) rep(j,LIM) rep(k,LIM) dp[m][i][j][k]=0;
  dp[7][0][0][0]=1;
  
  scanf("%d%s",&len,in);
  lim = (len+8)/3;

  rep(i,len) in[i]-='a';

  rep(l,len) if(!l || in[l]!=in[l-1]){
    if(in[l]==0){
      rep(m,8) if(m&1<<in[l]){
        rep(b,lim) rep(c,lim){
          sum = 0;
          REP(a,1,lim){
            sum = (sum+dp[m][a-1][b][c])%M;
            dp[7-(1<<in[l])][a][b][c] = (dp[7-(1<<in[l])][a][b][c]+sum)%M;
            dp[m-(1<<in[l])][a-1][b][c] = (dp[m-(1<<in[l])][a-1][b][c]+dp[m][a-1][b][c])%M;
            dp[m][a-1][b][c] = 0;
          }
        }
      }
    }
    if(in[l]==1){
      rep(m,8) if(m&1<<in[l]){
        rep(a,lim) rep(c,lim){
          sum = 0;
          REP(b,1,lim){
            sum = (sum+dp[m][a][b-1][c])%M;
            dp[7-(1<<in[l])][a][b][c] = (dp[7-(1<<in[l])][a][b][c]+sum)%M;
            dp[m-(1<<in[l])][a][b-1][c] = (dp[m-(1<<in[l])][a][b-1][c]+dp[m][a][b-1][c])%M;
            dp[m][a][b-1][c] = 0;
          }
        }
      }
    }
    if(in[l]==2){
      rep(m,8) if(m&1<<in[l]){
        rep(a,lim) rep(b,lim){
          sum = 0;
          REP(c,1,lim){
            sum = (sum+dp[m][a][b][c-1])%M;
            dp[7-(1<<in[l])][a][b][c] = (dp[7-(1<<in[l])][a][b][c]+sum)%M;
            dp[m-(1<<in[l])][a][b][c-1] = (dp[m-(1<<in[l])][a][b][c-1]+dp[m][a][b][c-1])%M;
            dp[m][a][b][c-1] = 0;
          }
        }
      }
    }
  }
  
  res=0;
  rep(m,8) rep(i,lim) rep(j,lim) rep(k,lim){
    if(i+j+k != len) continue;
    if(ab(i-j)>1 || ab(j-k)>1 || ab(k-i)>1) continue;
    res = (res+dp[m][i][j][k])%M;
  }
  printf("%d\n",res);

  return 0;
}