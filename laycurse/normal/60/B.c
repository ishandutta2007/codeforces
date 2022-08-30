#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y,z;
char mp[12][12][12];

void nul(int a,int b,int c,char from, char to){
  if(a<0||b<0||c<0||a>=x||b>=y||c>=z||mp[a][b][c]!=from) return;

  mp[a][b][c]=to;
  nul(a-1,b,c,from,to);
  nul(a+1,b,c,from,to);
  nul(a,b-1,c,from,to);
  nul(a,b+1,c,from,to);
  nul(a,b,c-1,from,to);
  nul(a,b,c+1,from,to);
}

int main(){
  int i,j,k,l,m,n;

  while(scanf("%d%d%d",&x,&y,&z)==3){
    rep(i,x) rep(j,y) scanf("%s",mp[i][j]);
    scanf("%d%d",&i,&j); i--; j--;

    nul(0,i,j,'.','@');
    n=0;
    rep(i,x) rep(j,y) rep(k,z) if(mp[i][j][k]=='@') n++;
    printf("%d\n",n);
  }

  return 0;
}