#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int is_same(char a[], char b[],int len){
  int i;
  rep(i,len) if(a[i]!=b[i]) return 0;
  return 1;
}

int main(){
  int i,j,k,l,m,n,res,len;
  char in[1000];

  scanf("%s",in);
  res=0;
  for(i=0;;i++) if(in[i]<' ') break; len=i;

  rep(i,len) REP(j,i+1,len) REP(k,res+1,len-j+1) if(is_same(in+i,in+j,k)){
    if(res<k) res=k;
  }

  printf("%d\n",res);

  return 0;
}