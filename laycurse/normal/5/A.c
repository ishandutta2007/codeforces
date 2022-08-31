#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  char in[10000];
  int res=0, num=0;

  while(gets(in)){
    if(in[0]=='+'){num++; continue;}
    if(in[0]=='-'){num--; continue;}
    for(i=0;;i++) if(in[i]<' ') break;
    for(k=0;;k++) if(in[k]==':') break;
    res += num*(i-k-1);
  }

  printf("%d\n",res);

  return 0;
}