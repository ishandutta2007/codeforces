#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-9
#define PI 3.141592653589793238462
typedef struct struct_point3{double x,y,z;}pnt3;
typedef struct struct_line3{pnt3 a,b;}line3;
typedef struct struct_plane3{pnt3 a,b,c;}plane3;
typedef struct struct_sphere{pnt3 c; double r;}sphere;

int doubleSign(double a){if(a>EPS) return 1; if(a<-EPS) return -1; return 0;}
int pnt3Sign(pnt3 a){
  int i = doubleSign(a.x); if(i) return i;
      i = doubleSign(a.y); if(i) return i;
  return doubleSign(a.z);
}

pnt3 pnt3Plus(pnt3 a,pnt3 b)             {a.x+=b.x; a.y+=b.y; a.z+=b.z; return a;}
pnt3 pnt3Minus(pnt3 a,pnt3 b)            {a.x-=b.x; a.y-=b.y; a.z-=b.z; return a;}
pnt3 pnt3MultipleDouble(pnt3 a,double k) {a.x*=k;   a.y*=k;   a.z*=k;   return a;}

double pnt3Length(pnt3 a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
double pnt3Length2(pnt3 a){return a.x*a.x+a.y*a.y+a.z*a.z;}
double pnt3Distance(pnt3 a,pnt3 b){return pnt3Length(pnt3Minus(a,b));}
double pnt3Distance2(pnt3 a,pnt3 b){return pnt3Length2(pnt3Minus(a,b));}

pnt3 pnt3Normalize(pnt3 a){return pnt3MultipleDouble(a,1.0/pnt3Length(a));}
double pnt3InnerProduct(pnt3 a,pnt3 b){return a.x*b.x+a.y*b.y+a.z*b.z;}
pnt3 pnt3OuterProduct(pnt3 a,pnt3 b){
  pnt3 res;
  res.x = a.y*b.z-a.z*b.y;
  res.y = a.z*b.x-a.x*b.z;
  res.z = a.x*b.y-a.y*b.x;
  return res;
}

pnt3 pnt3Generator(double x,double y,double z){pnt3 res; res.x=x; res.y=y; res.z=z; return res;}

/* a x^2 + b x + c = 0 2res1 < res2 */
/*  return 3; */
int doubleSolveSecondDegreeEquation(double a,double b,double c,double *res1,double *res2){
  if(doubleSign(a)==-1) a*=-1, b*=-1, c*=-1;
  if(doubleSign(a)){
    double d=b*b-4*a*c; int m=doubleSign(d)+1;
    if(m==1) *res1=-b/(2*a);
    if(m==2){d=sqrt(d); *res1=(-b-d)/(2*a); *res2=(-b+d)/(2*a);}
    return m;
  }
  if(doubleSign(b)){*res1 = -c/b; return 1;}
  if(doubleSign(c)) return 0; return 3;
}


int main(){
  int i,j,k,l,m,n;
  pnt3 p[12000], st, V;
  double v1, v2, dist[12000];
  double a,b,c, tmp1, tmp2, mx, tmp, t, add;
  int ok;
  

  while(scanf("%d",&n)==1){
    n++;
    
    rep(i,n) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
    scanf("%lf%lf",&v2,&v1);
    scanf("%lf%lf%lf",&st.x,&st.y,&st.z);

    dist[0] = 0;
    REP(i,1,n) dist[i] = dist[i-1] + pnt3Distance(p[i],p[i-1]);

    REP(k,1,n){
      a = b = c = 0;
      V = pnt3Normalize(pnt3Minus(p[k],p[k-1]));
      V = pnt3MultipleDouble(V, v1);
      add = dist[k-1]/v1;

      a = pow(v1, 2) - pow(v2, 2);
      b += (p[k-1].x - st.x) * (2 * V.x);
      b += (p[k-1].y - st.y) * (2 * V.y);
      b += (p[k-1].z - st.z) * (2 * V.z);
      b -= pow(v2, 2) * 2 * add;
      c += pow(p[k-1].x - st.x, 2);
      c += pow(p[k-1].y - st.y, 2);
      c += pow(p[k-1].z - st.z, 2);
      c -= pow(add*v2, 2);

      mx = (dist[k]-dist[k-1])/v1;
      i = doubleSolveSecondDegreeEquation(a,b,c,&tmp1,&tmp2);

      ok = 0;
      if(i==3){ ok=1; tmp=0; }
      else {
        if(i>=2 && 0<=tmp2+EPS && tmp2<=mx+EPS){
          ok=1; tmp = tmp2;
        }
        if(i>=1 && 0<=tmp1+EPS && tmp1<=mx+EPS){
          ok=1; tmp = tmp1;
        }
      }

      if(!ok) continue;
      puts("YES");
      t = dist[k-1]/v1 + tmp;
      printf("%.10lf\n",t);

      V = pnt3MultipleDouble(V, tmp);
      V = pnt3Plus(V, p[k-1]);
      printf("%.10lf %.10lf %.10lf\n",V.x,V.y,V.z);
      break;
    }

    if(k==n) puts("NO");
  }
  

  return 0;
}