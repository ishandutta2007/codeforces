#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int a, b, n, x;
  int k, mn, mx;

  mn = -1000000000;
  mx =  1000000000;

  scanf("%d%d",&n,&x);
  while(n--){
    scanf("%d%d",&a,&b);
    if(a > b) k=a, a=b, b=k;
    if(mn < a) mn = a;
    if(mx > b) mx = b;
  }

  if(mn > mx){ puts("-1"); return 0; }
  if(x  > mx){ printf("%d\n",x-mx); return 0; }
  if(x  < mn){ printf("%d\n",mn-x); return 0; }
  puts("0");

  return 0;
}