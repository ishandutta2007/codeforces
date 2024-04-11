#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int sz, n;
char now[1555][1555], next[1555][1555], pat[555][555];

void gogo(void){
  int i,j,ii,jj;

  rep(i,sz) rep(j,sz){
    if(now[i][j]=='.'){
      rep(ii,n) rep(jj,n) next[i*n+ii][j*n+jj] = pat[ii][jj];
    } else {
      rep(ii,n) rep(jj,n) next[i*n+ii][j*n+jj] = '*';
    }
  }

  sz *= n;
  rep(i,sz) rep(j,sz) now[i][j]=next[i][j];
}

int main(){
  int i,j,l,m,k;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  scanf("%d%d",&n,&k);
  sz=1; now[0][0]='.';
  rep(i,n) scanf("%s",pat[i]);
  while(k--) gogo();

  rep(i,sz){
    rep(j,sz) putchar(now[i][j]);
    puts("");
  }

  return 0;
}