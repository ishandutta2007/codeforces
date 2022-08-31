#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10
#define PI 3.141592653589793238462
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
typedef struct struct_point{double x,y;}pnt;
typedef struct struct_line{pnt a,b;}line;
typedef struct struct_circle{pnt c; double r;}circle;

int doubleSign(double a){if(a>EPS) return 1; if(a<-EPS) return -1; return 0;}
int pntSign(pnt a){int i=doubleSign(a.x); if(i) return i; return doubleSign(a.y);}

pnt pntPlus(pnt a,pnt b){a.x+=b.x; a.y+=b.y; return a;}
pnt pntMinus(pnt a,pnt b){a.x-=b.x; a.y-=b.y; return a;}
pnt pntMultiple(pnt a,pnt b){pnt c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
pnt pntMultipleDouble(pnt a,double k){a.x*=k; a.y*=k; return a;}

int pntIsEqual(pnt a,pnt b){return pntSign(pntMinus(a,b))==0;}

double pntLength(pnt a){return sqrt(a.x*a.x+a.y*a.y);}
double pntLength2(pnt a){return a.x*a.x+a.y*a.y;}
double pntDistance(pnt a,pnt b){return pntLength(pntMinus(a,b));}
double pntDistance2(pnt a,pnt b){return pntLength2(pntMinus(a,b));}
double pntArgument(pnt a){return atan2(a.y,a.x);}

pnt pntNormalize(pnt a){double n=pntLength(a); a.x/=n; a.y/=n; return a;}
double pntInnerProduct(pnt a,pnt b){return a.x*b.x+a.y*b.y;}
double pntOuterProduct(pnt a,pnt b){return a.x*b.y-a.y*b.x;}

pnt pntGenerator(double x,double y){pnt res; res.x=x; res.y=y; return res;}
line pntToLine(pnt a,pnt b){line res; res.a=a; res.b=b; return res;}
circle pntToCircle(pnt c,double r){circle res; res.c=c; res.r=r; return res;}


int isPntOnSegment(pnt a,line s){
  pnt ab; double r;
  ab=pntMinus(s.b,s.a); r=pntDistance(s.a,a)/pntDistance(s.a,s.b);
  if( !pntIsEqual(a,pntPlus(s.a,pntMultipleDouble(ab,r)) ) ) return 0;
  if( doubleSign(r)==-1 || doubleSign(r-1)==1 ) return 0;
  if( doubleSign(r)==0  || doubleSign(r-1)==0 ) return 1;
  return 2;
}

double angleOfTriangle(pnt a,pnt b,pnt c){
  double inner,n1,n2;
  inner=pntInnerProduct(pntMinus(b,a),pntMinus(c,a));
  n1=pntDistance(a,b); n2=pntDistance(a,c);
  inner=inner/n1/n2;
  if(inner>1) inner=1; if(inner<-1) inner=-1;
  return acos(inner);
}


int pntIntersectionLineLine(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double r = (p4.y-p3.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p4.x-p3.x);
  if( doubleSign(r)==0 ) return 0;
  res->x = (p3.x*p4.y-p3.y*p4.x)*(p2.x-p1.x)-(p1.x*p2.y-p1.y*p2.x)*(p4.x-p3.x);
  res->y = (p3.y*p4.x-p3.x*p4.y)*(p2.y-p1.y)-(p1.y*p2.x-p1.x*p2.y)*(p4.y-p3.y);
  res->x /= r; res->y /= -r; return 1;
}

int pntIntersectionSegmentSegment(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double x1,x2,y1,y2;
  if(pntIntersectionLineLine(s,t,res)!=1) return 0;
  x1=MIN(p1.x,p2.x)-EPS; x2=MAX(p1.x,p2.x)+EPS;
  y1=MIN(p1.y,p2.y)-EPS; y2=MAX(p1.y,p2.y)+EPS;
  if(res->x < x1 || x2 < res->x || res->y < y1 || y2 < res->y) return 0;
  x1=MIN(p3.x,p4.x)-EPS; x2=MAX(p3.x,p4.x)+EPS;
  y1=MIN(p3.y,p4.y)-EPS; y2=MAX(p3.y,p4.y)+EPS;
  if(res->x < x1 || x2 < res->x || res->y < y1 || y2 < res->y) return 0;
  if(pntIsEqual(*res,p1)) return 1;
  if(pntIsEqual(*res,p2)) return 1;
  if(pntIsEqual(*res,p3)) return 1;
  if(pntIsEqual(*res,p4)) return 1;
  return 2;
}

void doubleSort(double d[],int s){int i,j;double k1,k2,t;if(s<=1)return;k1=(d[0]+d[s-1])/2.0;k2=k1+EPS;k1-=EPS;i=-1;j=s;for(;;){while(d[++i]<k1);while(d[--j]>k2);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}doubleSort(d,i);doubleSort(d+j+1,s-j-1);}
double ABS(double x){if(x<0) return -x; return x;}

int main(){
  int i,j,k,l,m,n,ok,loop;
  int size;
  pnt a1,a2,b1,b2,c1,c2,d1,d2,p;
  line a,b,c;

  double th, len1, len2, len3, len4, mx;

  scanf("%d",&size);
  while(size--){
    scanf("%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y);
    scanf("%lf%lf%lf%lf",&b1.x,&b1.y,&b2.x,&b2.y);
    scanf("%lf%lf%lf%lf",&c1.x,&c1.y,&c2.x,&c2.y);

    p = pntPlus(pntPlus(pntPlus(a1,a2),pntPlus(b1,b2)),pntPlus(c1,c2));
    p = pntMultipleDouble(p,1/3.0);
    a1 = pntMinus(a1,p);
    a2 = pntMinus(a2,p);
    b1 = pntMinus(b1,p);
    b2 = pntMinus(b2,p);
    c1 = pntMinus(c1,p);
    c2 = pntMinus(c2,p);

    mx=0;
    if(mx<ABS(a1.x)) mx=ABS(a1.x); if(mx<ABS(a1.y)) mx=ABS(a1.y);
    if(mx<ABS(a2.x)) mx=ABS(a2.x); if(mx<ABS(a2.y)) mx=ABS(a2.y);
    if(mx<ABS(b1.x)) mx=ABS(b1.x); if(mx<ABS(b1.y)) mx=ABS(b1.y);
    if(mx<ABS(b2.x)) mx=ABS(b2.x); if(mx<ABS(b2.y)) mx=ABS(b2.y);
    if(mx<ABS(c1.x)) mx=ABS(c1.x); if(mx<ABS(c1.y)) mx=ABS(c1.y);
    if(mx<ABS(c2.x)) mx=ABS(c2.x); if(mx<ABS(c2.y)) mx=ABS(c2.y);

    mx = 1/mx;
    a1=pntMultipleDouble(a1,mx); a2=pntMultipleDouble(a2,mx);
    b1=pntMultipleDouble(b1,mx); b2=pntMultipleDouble(b2,mx);
    c1=pntMultipleDouble(c1,mx); c2=pntMultipleDouble(c2,mx);

    ok=0;
    rep(loop,4){
      if(pntIsEqual(a1,b1)) a=pntToLine(a1,a2), b=pntToLine(b1,b2), c=pntToLine(c1,c2), ok++;
      if(pntIsEqual(a1,b2)) a=pntToLine(a1,a2), b=pntToLine(b2,b1), c=pntToLine(c1,c2), ok++;
      if(pntIsEqual(a1,c1)) a=pntToLine(a1,a2), b=pntToLine(c1,c2), c=pntToLine(b1,b2), ok++;
      if(pntIsEqual(a1,c2)) a=pntToLine(a1,a2), b=pntToLine(c2,c1), c=pntToLine(b1,b2), ok++;
      if(pntIsEqual(a2,b1)) a=pntToLine(a2,a1), b=pntToLine(b1,b2), c=pntToLine(c1,c2), ok++;
      if(pntIsEqual(a2,b2)) a=pntToLine(a2,a1), b=pntToLine(b2,b1), c=pntToLine(c1,c2), ok++;
      if(pntIsEqual(a2,c1)) a=pntToLine(a2,a1), b=pntToLine(c1,c2), c=pntToLine(b1,b2), ok++;
      if(pntIsEqual(a2,c2)) a=pntToLine(a2,a1), b=pntToLine(c2,c1), c=pntToLine(b1,b2), ok++;
      if(ok) break;

      d1=a1; d2=a2;
      a1=b1; a2=b2;
      b1=c1; b2=c2;
      c1=d1; c2=d2;
    }

    if(loop==4 || ok>1){puts("NO"); continue;}

    if(!isPntOnSegment(c.a,a)) c=pntToLine(c.b,c.a);

    th = angleOfTriangle(a.a,a.b,b.b);
    if(th < EPS || th > PI/2+EPS){puts("NO"); continue;}

    if(!isPntOnSegment(c.a,a)) { puts("NO"); continue; }
    if(!isPntOnSegment(c.b,b)) { puts("NO"); continue; }

    len1 = pntDistance(c.a,a.a); len2 = pntDistance(c.a,a.b);
    if(len1/4 > len2+EPS || len2/4 > len1+EPS){ puts("NO"); continue; }

    len1 = pntDistance(c.b,b.a); len2 = pntDistance(c.b,b.b);
    if(len1/4 > len2+EPS || len2/4 > len1+EPS){ puts("NO"); continue; }

    puts("YES");
  }

  return 0;
}