#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int x,y,num;
  int r,g;
  int ok_r, ok_g, ok_v;
  char mp[120][120];
  int grundy[10];

  while(scanf("%d%d%d",&x,&y,&k)==3){
    rep(i,x) scanf("%s",mp[i]);
    ok_g = ok_r = 0;
    rep(i,10) grundy[i] = 0;

    rep(i,x){
      r=g=-1; num = 0;
      rep(j,y){
        if(mp[i][j]=='G') g=j, num++;
        if(mp[i][j]=='R') r=j, num++;
      }
      if(r==-1 || g==-1){
        if(num < y){
          if(g>=0) ok_g = 1;
          if(r>=0) ok_r = 1;
        }
        continue;
      }

      if(r > g) m = r-g-1; else m = g-r-1;
      rep(j,10) if(m&1<<j) grundy[j]++;
    }

    if(ok_g && ok_r){
      puts("Draw"); continue;
    }
    if(ok_g){
      puts("First"); continue;
    }
    if(ok_r){
      puts("Second"); continue;
    }

    rep(i,10) if(grundy[i]%(k+1)) break;
    if(i==10) puts("Second"); else puts("First");
  }

  return 0;
}