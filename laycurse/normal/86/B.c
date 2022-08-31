#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y;
char mp[1200][1200];

int is_emp(int a,int b){
  if(a<0 || b<0 || a>=x || b>=y) return 0;
  if(mp[a][b]=='.') return 1;
  return 0;
}

int main(){
  int i,j,k,l,m,n,fg;
  int dx[4]={0,0,1,-1};
  int dy[4]={1,-1,0,0};
  char c;
  int dame;

  while(scanf("%d%d",&x,&y)==2){
    rep(i,x) scanf("%s",mp[i]);
    dame=0;

    rep(i,x) rep(j,y) if(is_emp(i,j)){
      m = 0;
      rep(k,4) m += is_emp(i+dx[k], j+dy[k]);
      if(m==0) dame=1;
    }

    if(dame){puts("-1"); continue;}

    rep(i,x){
      fg = 0;
      rep(j,y) if(is_emp(i,j) && is_emp(i,j+1)){
        c = '0' + (i%3)*2;
        if(fg) c++;
        fg ^= 1;

        mp[i][j] = mp[i][j+1] = c;
      }
    }

    rep(j,y){
      fg = 0;
      rep(i,x) if(is_emp(i,j) && is_emp(i+1,j)){
        c = '6';
        if(fg) c++;
        fg ^= 1;

        mp[i][j] = mp[i+1][j] = c;
      }
    }

    for(;;){
      fg = 0;
      rep(i,x) rep(j,y) if(is_emp(i,j)){
        if(0<=i-1 && i-1<x && '0'<=mp[i-1][j] && mp[i-1][j]<='9'){ mp[i][j] = mp[i-1][j]; continue; }
        if(0<=i+1 && i+1<x && '0'<=mp[i+1][j] && mp[i+1][j]<='9'){ mp[i][j] = mp[i+1][j]; continue; }
        if(0<=j-1 && j-1<y && '0'<=mp[i][j-1] && mp[i][j-1]<='9'){ mp[i][j] = mp[i][j-1]; continue; }
        if(0<=j+1 && j+1<y && '0'<=mp[i][j+1] && mp[i][j+1]<='9'){ mp[i][j] = mp[i][j+1]; continue; }
      }
      if(!fg) break;
    }

    rep(i,x) puts(mp[i]);
  }

  return 0;
}