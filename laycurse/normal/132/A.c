#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int bef;
  char in[1000];
  char bin[100];

  gets(in);

  bef = 0;
  for(i=0;;i++){
    if(in[i]<' ') break;

    m = in[i];
    rep(k,8){
      bin[k] = m%2;
      m /= 2;
    }
    m = 0;
    rep(k,8){
      m *= 2;
      m += bin[k];
    }

    k = (256 + 256 + bef - m)%256;
    bef = m;
    printf("%d\n",k);
  }

  return 0;
}