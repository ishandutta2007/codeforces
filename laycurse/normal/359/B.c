#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int k, n;
  static int res[1100000];

  int i, j;

  scanf("%d%d",&n,&k);

  if(k==0){
    rep(i,2*n) res[i] = i+1;
  } else {
    res[0] = 1+k;
    res[1] = 1;
    j = 0;
    REP(i,2,2*n){
      j++;
      if(j==1) j++;
      if(j==1+k) j++;
      res[i] = j;
    }
  }


  rep(i,2*n){
    if(i) putchar(' ');
    printf("%d",res[i]);
  }
  puts("");

  return 0;
}