#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define M 1111111
char in[M]; int reach[2222222];

int main(){
  int i,j,k,l,m,n;
  int res1=0,res2=1;
  int a,b,c;

  scanf("%s",in);
  for(i=0;;i++) if(in[i]<' ') break; n=i;

  rep(i,M+M) reach[i]=M;
  k=0;
  rep(i,n){
    if(in[i]=='('){
      k++; if(reach[M+k]==M) reach[M+k]=i;
    } else {
      if(res1 == i+1-reach[M+k]) res2++;
      if(res1 <  i+1-reach[M+k]) res1=i+1-reach[M+k], res2=1;
      reach[M+k+1]=M; k--;
    }
  }

  printf("%d %d\n",res1,res2);

  return 0;
}