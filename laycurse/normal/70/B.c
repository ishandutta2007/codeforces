#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int in[20000], size, res, rest;
  char str[20000];

  for(;;){
    if(!gets(str)) break; n=atoi(str);
    if(!gets(str)) break;

    size=0;
    for(i=0;;i++){
      if(str[i]<' ') break;
      if(str[i]==' '){i++; continue;}

      j=i;
      while(str[j]!='.' && str[j]!='?' && str[j]!='!') j++;

      j++;
      in[size++] = j-i+1;
      i=j;
    }

    res = 0; rest = 0;
    rep(i,size){
      if(rest < in[i]) res++, rest=n+1;
      if(rest < in[i]){ res = -1; break; }
      rest -= in[i];
    }
    if(res<0) puts("Impossible"); else printf("%d\n",res);
  }

  return 0;
}