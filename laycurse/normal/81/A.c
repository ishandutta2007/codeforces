#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char in[300000];
int st[300000], st_size;

int main(){
  int i,j,k,l,m,n;

  while(scanf("%s",in)==1){
    st_size = 0;
    for(i=0;;i++){
      if(in[i]<' ') break;
      
      if(st_size && st[st_size-1] == in[i]){
        st_size--;
      } else {
        st[st_size++] = in[i];
      }
    }

    rep(i,st_size) putchar(st[i]); puts("");
  }

  return 0;
}