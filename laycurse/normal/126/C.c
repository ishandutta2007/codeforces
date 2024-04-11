#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char mp[2100][2100], tmp[2100][2100];
int go[2100];

int main(){
  int i,j,k,l,m,n,loop;
  int res;
  
  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%s",mp[i]);
    res = 0;

    rep(i,n) rep(j,n) mp[i][j] -= '0';

    rep(loop,2){
/*      printf("loop %d\n",loop);
      rep(i,n){ rep(j,n)putchar(mp[i][j]+'0'); puts(""); }*/

      rep(i,n) go[i] = 0;
      for(i=n-1;i>=0;i--){
        k = 0;
        for(j=0; j<=i; j++){
          m = mp[i][j];
          m += k;
          m += go[j];
          
          if(j!=i){
            if(m%2){
              res++;
              k++;
              go[j]++;
            }
            mp[i][j] = 0;
          } else {
            mp[i][j] = m%2;
          }
        }
      }
      if(loop==0){
        rep(i,n) rep(j,n) tmp[i][j] = mp[i][j];
        rep(i,n) rep(j,n) mp[i][j] = tmp[j][i];
      }
    }

    rep(i,n) if(mp[i][i]) res++;

    printf("%d\n",res);
  }

  return 0;
}