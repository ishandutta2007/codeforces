#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
main(){
 int x1,x2,y1,y2,r1,r2;
 scanf("%d%d%d",&x1,&y1,&r1);
 scanf("%d%d%d",&x2,&y2,&r2);
 if(r1<r2){
  swap(x1,x2);
  swap(y1,y2);
  swap(r1,r2);
 }
 int a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
 int b=(r1+r2)*(r1+r2);
 if((r1-r2)*(r1-r2)>a){
  printf("%lf\n",(r1-r2-sqrt(a))/2.);
  return 0;
 }
 if(a<=b)
 printf("0\n");
 else
 printf("%lf\n",(sqrt(a)-r1-r2)/2.);
}