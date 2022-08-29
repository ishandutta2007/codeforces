#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int N = 8, tm = 100;
  char mp[8][9], cp[8][8];

  int i, j, di, dj, ni, nj;

  rep(i,N) scanf("%s",mp[i]);

  while(tm--){
    rep(i,N) rep(j,N) cp[i][j] = mp[i][j];

    rep(i,N) rep(j,N) if(cp[i][j]=='M'){
      REP(di,-1,2) REP(dj,-1,2){
        ni = i + di; nj = j + dj;
        if(ni < 0 || nj < 0 || ni >= N || nj >= N || mp[ni][nj]=='S') continue;
        mp[ni][nj] = 'M';
      }
    }
    
    rep(i,N)   rep(j,N) if(cp[i][j]=='S') mp[i][j] = '.';
    rep(i,N-1) rep(j,N) if(cp[i][j]=='S') mp[i+1][j] = 'S';
  }

  if(mp[0][0]=='M') puts("WIN"); else puts("LOSE");

  return 0;
}