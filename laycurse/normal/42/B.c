#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int chk1(int dx,int dy){
  if(dx<0) dx=-dx; if(dy<0) dy=-dy;
  if(dx<=1 && dy<=1) return 1;
  return 0;
}

int chk2(int dx,int dy){
  if(dx==0 && dy==0) return 0;
  if(dx==0 || dy==0) return 1;
  return 0;
}

int main(){
  int i,j,k,l,m,n;
  int di,dj,ok;
  char in[4][4];

  while(scanf("%s%s%s%s",in[0],in[1],in[2],in[3])==4){
    ok=0;
    REP(di,-1,2) REP(dj,-1,2) {
      in[3][0] += di; in[3][1]+=dj;
      while('a'<=in[3][0]&&in[3][0]<='h' && '1'<=in[3][1]&&in[3][1]<='8'){
        if(chk1(in[2][0]-in[3][0],in[2][1]-in[3][1])) break;
        rep(i,2){
          if(chk2(in[i][0]-in[3][0],in[i][1]-in[3][1])){
            rep(k,3){
              if(in[i][1]==in[3][1] && in[i][1]==in[k][1] && ((in[i][0]<in[k][0]&&in[k][0]<in[3][0])||(in[i][0]>in[k][0]&&in[k][0]>in[3][0]))) break;
              if(in[i][0]==in[3][0] && in[i][0]==in[k][0] && ((in[i][1]<in[k][1]&&in[k][1]<in[3][1])||(in[i][1]>in[k][1]&&in[k][1]>in[3][1]))) break;
            }
            if(k==3) break;
          }
        }
        if(i<2) break;
        ok=1; break;
      }
      in[3][0] -= di; in[3][1] -= dj;
    }
    if(ok) puts("OTHER"); else puts("CHECKMATE");

    break;
  }

  return 0;
}