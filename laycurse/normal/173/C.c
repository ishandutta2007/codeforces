#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int x, y;
int in[510][510];
int sum[510][510];

int get(int x1, int y1, int x2, int y2){
  return sum[x2+1][y2+1] - sum[x1][y2+1] - sum[x2+1][y1] + sum[x1][y1];
}

int main(){
  int i,j,k,l,m,n;
  int res = -INF, tmp;

  scanf("%d%d",&x,&y);
  rep(i,x) rep(j,y) scanf("%d",in[i]+j);
  rep(i,510) sum[0][i] = sum[i][0] = 0;
  rep(i,x) rep(j,y) sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + in[i][j];

  rep(i,x) rep(j,y){
    tmp = 0;
    for(k=1;;k+=2){
      if(i-k < 0 || i+k >= x || j-k < 0 || j+k >= y) break;
      tmp += get(i-k, j-k, i+k, j+k);
      tmp -= get(i-k+1, j-k+1, i+k-1, j+k-1);
      tmp -= in[i-k+1][j-k];
      if(k > 1) tmp += in[i-k+2][j-k+1];
      if(res < tmp) res = tmp;
    }

    tmp = in[i][j];
    for(k=2;;k+=2){
      if(i-k < 0 || i+k >= x || j-k < 0 || j+k >= y) break;
      tmp += get(i-k, j-k, i+k, j+k);
      tmp -= get(i-k+1, j-k+1, i+k-1, j+k-1);
      tmp -= in[i-k+1][j-k];
      tmp += in[i-k+2][j-k+1];
      if(res < tmp) res = tmp;
    }
  }

  printf("%d\n",res);
  
  return 0;
}