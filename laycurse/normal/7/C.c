#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void extended_euclid(ll x,ll y,ll *c,ll *a,ll *b){
  ll a0,a1,a2,b0,b1,b2,r0,r1,r2,q;
  r0=x; r1=y; a0=1; a1=0; b0=0; b1=1;
  while(r1>0){
    q=r0/r1; r2=r0%r1; a2=a0-q*a1; b2=b0-q*b1;
    r0=r1; r1=r2; a0=a1; a1=a2; b0=b1; b1=b2;
  }
  *c=r0; *a=a0; *b=b0;
}

ll ab(ll a){if(a<0) return -a; return a;}

int main(){
  int aa,bb,cc;
  ll A,B,C,a,b,c;

  scanf("%d%d%d",&aa,&bb,&cc); A=aa; B=bb; C=cc;
  if(C==0){puts("0 0"); return 0;}
  extended_euclid(ab(A),ab(B),&c,&a,&b);
  if(A<0) a*=-1; if(B<0) b*=-1;
  if(C%c){puts("-1"); return 0;}
  
  A/=c; B/=c; C/=c;
  a*=-C; b*=-C;
  printf("%I64lld %I64lld\n",a,b);

  return 0;
}