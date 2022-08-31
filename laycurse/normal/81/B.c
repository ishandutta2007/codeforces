#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int replaceAll(char a[],int *as,char b[],int bs,char c[],int cs){
  int i,j;
  int AS = *as;
  int res=0;

  rep(i,AS-bs+1){
    rep(j,bs) if(a[i+j]!=b[j]) break;
    if(j!=bs) continue;

    AS += cs - bs;
    if(bs < cs){
      for(j=AS-1;j>=i+cs;j--) a[j] = a[j+bs-cs];
    } else if(bs > cs){
      for(j=i+cs;j<AS;j++) a[j] = a[j+bs-cs];
    }

    rep(j,cs) a[i+j] = c[j];
    i += cs-1;
    res++;
  }

  *as = AS;
  return res;
}

int main(){
  int i,j,k,l,m,n,st;
  char in[1000];

  while(gets(in)){
    for(i=0;;i++) if(in[i]<' ') break; n=i;

    while( replaceAll(in,&n,"  ",2," ",1) );
    while( replaceAll(in,&n,", ",2,",",1) );
    while( replaceAll(in,&n," ,",2,",",1) );
    while( replaceAll(in,&n,"... ",4,"...",3) );
    while( replaceAll(in,&n," ...",4,"...",3) );

    replaceAll(in,&n,",",1,", ",2);
    replaceAll(in,&n,"...",3," ...",4);
    while( replaceAll(in,&n,"  ",2," ",1) );

    while(n && in[n-1]==' ') n--;
    st = 0;
    while(st<n && in[st]==' ') st++;
    in[n]='\0'; puts(in+st);
  }

  return 0;
}