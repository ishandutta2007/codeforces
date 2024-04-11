#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int x,y,x1,y1,x2,y2;
  long long res, X, Y, a, b;
  int size;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
    x1 -= x2; y1 -= y2;
    if(x1<0) x1 *= -1; if(y1<0) y1 *= -1;
    X=x; Y=y; a=X-x1; b=Y-y1;

    res = X*Y;
    res -= a*b*2;
    if(X-2*a<0 && y-2*b<0) res += (X-2*a)*(Y-2*b);
    printf("%I64lld\n",res);
  }

  return 0;
}