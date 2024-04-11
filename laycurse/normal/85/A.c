#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  char res[4][1000];

  while(scanf("%d",&n)==1){
    if(n%2){
      res[0][n-1] = res[1][n-1] = 'y';
      res[2][  0] = res[3][  0] = 'z';
      for(i=0;i+1<n;i+=2){
        res[0][i] = res[0][i+1] = 'a'+(i%4);
        res[1][i] = res[1][i+1] = 'c'+(i%4);
      }
      for(i=1;i+1<n;i+=2){
        res[2][i] = res[2][i+1] = 'k'+(i%4);
        res[3][i] = res[3][i+1] = 'l'+(i%4);
      }
    } else {
      for(i=0;i+1<n;i+=2){
        res[0][i] = res[0][i+1] = 'a'+(i%4);
        res[3][i] = res[3][i+1] = 'b'+(i%4);
      }
      res[1][  0] = res[2][  0] = 'y';
      res[1][n-1] = res[2][n-1] = 'z';
      for(i=1;i+1<n;i+=2){
        res[1][i] = res[1][i+1] = 'k'+(i%4);
        res[2][i] = res[2][i+1] = 'l'+(i%4);
      }
    }

    rep(i,4) res[i][n] = '\0';
    rep(i,4) puts(res[i]);
  }

  return 0;
}