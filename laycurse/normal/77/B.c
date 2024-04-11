#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
  double a,b,res;
  double m1, m2;
  int size;

  scanf("%d",&size);
  while(size--){
    scanf("%lf%lf",&a,&b);
    if(b<EPS){ puts("1.0000000000"); continue; }
    if(a<EPS){ puts("0.5000000000"); continue; }
    
    res = 0;

    if(a > 4*b) m1 = 4*b, m2 = a-m1;
    else        m1 = a,   m2 = 0;

    res += m2 / a;
    res += 0.5 * m1 / a / 2;
    res += MIN(1.0,(4*b+a)/(8*b)) * m1 / a / 2;
    
    printf("%.10lf\n",res);
  }


  return 0;
}