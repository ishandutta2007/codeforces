#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define EPS 1e-11

int sign(double a){if(a>EPS) return 1; if(a<-EPS) return -1; return 0;}
int ab(int a){if(a<0)return -a; return a;}
int GCD(int a,int b){int r; while(a){r=b; b=a; a=r%a;} return b;}

int main(){
  int a,b,A,B,k;
  double c, C;

  scanf("%d%d%lf%d%d%lf",&a,&b,&c,&A,&B,&C);
  if(a<0 || (!a&&b<0)) a=-a, b=-b, c=-c;
  if(A<0 || (!A&&B<0)) A=-A, B=-B, C=-C;
  if(a||b) k=GCD(a,ab(b)), a/=k, b/=k, c/=k;
  if(A||B) k=GCD(A,ab(B)), A/=k, B/=k, C/=k;

  if( (!a&&!b&&sign(c) || (!A&&!B&&sign(C))) ) puts("0");
  else if( (!a&&!b&&!sign(c)) || (!A&&!B&&!sign(C)) )puts("-1");
  else if(a==A && b==B && sign(c-C)==0 ) puts("-1");
  else if(a==A && b==B) puts("0");
  else puts("1");

  return 0;
}