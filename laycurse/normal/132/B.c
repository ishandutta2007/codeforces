#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y;
char in[60][60];
int block[60][60], xa[6060], xb[6060], ya[6060], yb[6060], block_size;

int fst[6000][4][2];

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int main(){
  int i,j,k,l,m,n;
  int a, b, tm;
  int now, d1, d2;
  int nx, ny;

  scanf("%d%d",&x,&n);
  rep(i,x) scanf("%s",in[i]);
  y = strlen(in[0]);

  rep(i,x) rep(j,y) block[i][j] = -1;
  
  block_size = 0;
  rep(i,x) rep(j,y) if(block[i][j]==-1 && in[i][j]!='0'){
    REP(k,i,x) if(in[k][j] != in[i][j]) break;
    REP(l,j,y) if(in[i][l] != in[i][j]) break;

    xa[block_size] = i; xb[block_size] = k-1;
    ya[block_size] = j; yb[block_size] = l-1;
    REP(a,i,k) REP(b,j,l) block[a][b] = block_size;
    block_size++;
  }

  rep(i,block_size) rep(j,4) rep(k,2) fst[i][j][k] = -1;

  tm = 0;
  now = 0; d1 = 0; d2 = 0;
  while(tm < n){
    if(fst[now][d1][d2] >= 0){
      int step = tm - fst[now][d1][d2];
      k = (n-tm-10) / step;
      if(k > 0) n -= step * k;
    } else {
      fst[now][d1][d2] = tm;
    }

    tm++;
    if(d1==0 && d2==0) nx = xa[now], ny = yb[now]+1;
    if(d1==0 && d2==1) nx = xb[now], ny = yb[now]+1;
    if(d1==1 && d2==0) nx = xb[now]+1, ny = yb[now];
    if(d1==1 && d2==1) nx = xb[now]+1, ny = ya[now];
    if(d1==2 && d2==0) nx = xb[now], ny = ya[now]-1;
    if(d1==2 && d2==1) nx = xa[now], ny = ya[now]-1;
    if(d1==3 && d2==0) nx = xa[now]-1, ny = ya[now];
    if(d1==3 && d2==1) nx = xa[now]-1, ny = yb[now];

    if(nx < 0 || nx >= x || ny < 0 || ny >= y || block[nx][ny]==-1){
      if(d2==1) d1 = (d1+1)%4;
      d2 = (d2+1)%2;
    } else {
      now = block[nx][ny];
    }
  }

  nx = xa[now];
  ny = ya[now];
/*  printf("%d %d %d %d\n",(int)(in[nx][ny]-'0'), now, d1, d2);*/
  printf("%d\n",(int)(in[nx][ny]-'0'));

  return 0;
}