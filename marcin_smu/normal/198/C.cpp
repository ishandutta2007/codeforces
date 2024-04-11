#include<cstdio>
#include<cmath>
using namespace std;
#define eps 0.0000001
typedef double D;
int xp,yp,vp;
int x,y,v,r;
D h,o1,o2,o3,xk,yk;
inline D kw(D a){
 return a*a;
}
D odls(D x,D y){
 return sqrt(x*x+y*y);
}
D odl(D x,D y){
 return x*x+y*y;
}
D odl2(D x1,D y1,D x2,D y2){
 return kw(x1-x2)+kw(y1-y2);
}
D pole(D x1,D y1,D x2,D y2){
 return abs(x1*y2-x2*y1);
}
bool czy_prze(){
 h=pole(x,y,xk,yk)/o3;
 return r>h&&sqrt(kw(o1)-kw(h))+sqrt(kw(o2)-kw(h))<o3+eps;
}
bool q(D t){
 D om=vp/odls(xp,yp);
 D a=cos(om*t);
 D b=sin(om*t);
 xk=a*xp-b*yp;
 yk=b*xp+a*yp;
 o1=odls(x,y);
 o2=odls(xp,yp);
 o3=sqrt(odl2(x,y,xk,yk));
 D w;
 if(czy_prze()==0){
  w=o3;
 }else{
  D pom1=sqrt(odl(x,y)-r*r),
    pom2=sqrt(odl(xp,yp)-r*r),
    k1=acos(h/o1)+acos(h/o2)-acos(r/o1)-acos(r/o2);
    w=pom1+pom2+k1*r;
 }
 return w<v*t+eps;
}
main(){
 scanf("%d%d%d",&xp,&yp,&vp);
 scanf("%d%d%d%d",&x,&y,&v,&r);
 D p=0.,k=10000.;
 while(p+eps<k){
  if(q((p+k)/2))
   k=(p+k)/2;
  else
   p=(p+k)/2;
 }
 printf("%lf\n",(p+k)/2);
}