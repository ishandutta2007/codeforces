#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int mp[222][222];
  int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, cnv[333];
  char in[222];
  int sx,sy,nx,ny;

  cnv['U']=0; cnv['R']=1; cnv['D']=2; cnv['L']=3;

  scanf("%s",in);
  for(i=0;;i++) if(in[i]<' ') break; n=i;

  rep(i,222) rep(j,222) mp[i][j]=0;
  sx=sy=111;

  mp[sx][sy]=1;
  rep(i,n){
    k=cnv[in[i]];
    sx+=dx[k]; sy+=dy[k];
    if(mp[sx][sy]) break; mp[sx][sy]=1;

    m=0;
    rep(k,4) {
      nx=sx+dx[k]; ny=sy+dy[k];
      m+=mp[nx][ny];
    }
    if(m>=2) break;
  }

  if(i==n) puts("OK"); else puts("BUG");

  return 0;
}