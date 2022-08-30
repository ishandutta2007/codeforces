#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int A[1200], B[1200];

  while(scanf("%d%d",&n,&k)==2){
    rep(i,n) scanf("%d",B+i);
    rep(i,n) A[i]=i;

    for(i=n-1;i>=0;i--){
      rep(j,n) if(A[j]==i) break;
      while(B[i]>0){
        if(A[j+1] >= i+k) B[i]--;
        m=A[j+1], A[j+1]=A[j], A[j]=m;
        j++;
      }
    }

    rep(i,n){
      if(i) putchar(' ');
      printf("%d",A[i]+1);
    }
    puts("");
  }


  return 0;
}