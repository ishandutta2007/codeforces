#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


double dp[1001][1001];
double dp_sum[1002][1002];
int n, m;
int a[1200], b[1200];
int fst[1200];

double get(int x1, int y1, int x2, int y2){
  if(x1 > x2 || y1 > y2) return 0;
  return dp_sum[x2+1][y2+1] - dp_sum[x2+1][y1] - dp_sum[x1][y2+1] + dp_sum[x1][y1];
}

int main(){
  int i,j,k,l;
  double sum;
  double res;

  scanf("%d%d",&n,&m);
  rep(i,n){
    scanf("%d",&k);
    fst[k-1] = i;
  }
  rep(i,m) scanf("%d%d",a+i,b+i), a[i]--, b[i]--;

  rep(i,n){
    rep(j,n) dp[i][j] = 0;
    dp[i][fst[i]] = 1;
    rep(j,m){
      sum = dp[i][a[j]] + dp[i][b[j]];
      dp[i][a[j]] = dp[i][b[j]] = sum / 2;
    }
  }

/*  puts("DP"); rep(i,n){rep(j,n) printf("%f ",dp[i][j]); puts("");}*/

  rep(i,n+1) dp_sum[i][0] = dp_sum[0][i] = 0;
  rep(i,n) rep(j,n){
    dp_sum[i+1][j+1] = dp_sum[i][j+1] + dp_sum[i+1][j] - dp_sum[i][j];
    dp_sum[i+1][j+1] += dp[i][j];
  }
  
/*  puts("DP SUM"); rep(i,n+1){rep(j,n+1) printf("%f ",dp_sum[i][j]); puts("");}*/
  
  res = 0;
  rep(i,n) rep(j,n){
    sum = get(i+1, 0, n-1, j-1);
    res += dp[i][j] * sum;
    sum = get(i+1, j, n-1, j);
    res += dp[i][j] * sum / 2;
  }

  printf("%.10f\n",res);

  return 0;
}