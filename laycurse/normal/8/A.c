#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void charReverse(char d[],int size){int a=0,b=size-1;char t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}

int is_same(char a[],char b[],int len){
  int i;
  rep(i,len) if(a[i]!=b[i]) return 0;
  return 1;
}

int get_len(char a[]){
  int i;
  for(i=0;;i++) if(a[i]<' ') break;
  return i;
}

int main(){
  int i,j,k,l,m,n;
  char a[100011], b[200], c[200];
  int as,bs,cs;
  int f1=0, f2=0;

  scanf("%s%s%s",a,b,c);
  as=get_len(a); bs=get_len(b); cs=get_len(c);

  rep(i,as-bs+1) if(is_same(a+i,b,bs)) break; i+=bs;
  REP(i,i,as-cs+1) if(is_same(a+i,c,cs)) break;
  if(i<as-cs+1) f1=1;

  charReverse(a,as);
  
  rep(i,as-bs+1) if(is_same(a+i,b,bs)) break; i+=bs;
  REP(i,i,as-cs+1) if(is_same(a+i,c,cs)) break;
  if(i<as-cs+1) f2=1;

  if( f1 &&  f2) puts("both");
  if( f1 && !f2) puts("forward");
  if(!f1 &&  f2) puts("backward");
  if(!f1 && !f2) puts("fantasy");

  return 0;
}