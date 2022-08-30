#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int GCD(int a,int b){int r; while(a){r=b; b=a; a=r%a;} return b;}

int sod(int n,int b){
  int res=0;
  while(n) res += n%b, n/=b;
  return res;
}

int main(){
  int i,j,k,l,m,n;
  int a,b;

  scanf("%d",&n);
  a=b=0;
  REP(i,2,n) a+=sod(n,i), b++;

  k=GCD(a,b); a/=k; b/=k;
  printf("%d/%d\n",a,b);

  return 0;
}