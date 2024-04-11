#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int in[55][55];
int sum[55][55], tmp[55][55];

int main(){
  int i,j,k,l,m,n,loop;
  int x,y,a,b;
  int res, go;

  while(scanf("%d%d",&x,&y)==2){
    rep(i,x) rep(j,y) scanf("%d",in[i]+j);
    scanf("%d%d",&a,&b);
    res = a*b;

    rep(i,x){
      tmp[i][0]=0; rep(j,y) tmp[i][j+1]=tmp[i][j]+in[i][j];
    }
    rep(j,y+1){
      sum[0][j] = 0;
      rep(i,x) sum[i+1][j] = sum[i][j] + tmp[i][j];
    }
    
    rep(loop,2){
      k=a, a=b, b=k;
      REP(i,a,x+1) REP(j,b,y+1){
        go = sum[i][j] - sum[i-a][j] - sum[i][j-b] + sum[i-a][j-b];
        if(res > go) res = go;
      }
    }
    printf("%d\n",res);
  }

  return 0;
}