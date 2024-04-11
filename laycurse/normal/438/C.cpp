#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long
#define MD 1000000007

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}


#define EPS 1e-10
#define PI 3.141592653589793238462
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
typedef struct struct_point{double x,y;}pnt;
typedef struct struct_line{pnt a,b;}line;
typedef struct struct_circle{pnt c; double r;}circle;

int doubleSign(double a){if(a>EPS) return 1; if(a<-EPS) return -1; return 0;}
int doubleSignR(double a,double b){ if(doubleSign(b)!=0 && doubleSign(a/b-1)==0) return 0; return doubleSign(a-b);}
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

/* 2 */
double pntAreaOfTriangle2(pnt p1,pnt p2,pnt p3){
  double x1,x2,y1,y2;
  x1=p2.x-p1.x; x2=p3.x-p1.x;
  y1=p2.y-p1.y; y2=p3.y-p1.y;
  return x1*y2-x2*y1;
}

/*                    */
/* p1,p2p3=1  */
/* p1,p2p3=-1 */
/* p1,p2,p3 =0  */
int pntSignAreaOfTriangle(pnt p1,pnt p2,pnt p3){
  return doubleSign( pntAreaOfTriangle2(p1,p2,p3) );
}


/* 1, 0 */
int isPntOnLine(pnt a,line s){
  pnt ab; double r;
  ab=pntMinus(s.b,s.a); r=pntDistance(s.a,a)/pntDistance(s.a,s.b);
  if( !pntIsEqual(a,pntPlus(s.a,pntMultipleDouble(ab,r)) ) && !pntIsEqual(a,pntMinus(s.a,pntMultipleDouble(ab,r)) ) ) return 0;
  return 1;
}

/* 2, 1, 0 */
int isPntOnSegment(pnt a,line s){
  pnt ab; double r;
  ab=pntMinus(s.b,s.a); r=pntDistance(s.a,a)/pntDistance(s.a,s.b);
  if( !pntIsEqual(a,pntPlus(s.a,pntMultipleDouble(ab,r)) ) ) return 0;
  if( doubleSign(r)==-1 || doubleSign(r-1)==1 ) return 0;
  if( doubleSign(r)==0  || doubleSign(r-1)==0 ) return 1;
  return 2;
}

/* bac */
double angleOfTriangle(pnt a,pnt b,pnt c){
  double inner,n1,n2;
  inner=pntInnerProduct(pntMinus(b,a),pntMinus(c,a));
  n1=pntDistance(a,b); n2=pntDistance(a,c);
  inner=inner/n1/n2;
  if(inner>1) inner=1; if(inner<-1) inner=-1;
  return acos(inner);
}

/* =1 =2 =0 */
int isInPolygon(pnt p,pnt poly[],int size){
  int i; double th=0;
  poly[size]=poly[0];

  rep(i,size) th += pntSignAreaOfTriangle(p,poly[i],poly[i+1]) * angleOfTriangle(p,poly[i],poly[i+1]);
  if( -PI/2<th && th<PI/2 ) return 0; return 2;
}

/* 2 () */
/* :  0                     */
/* : return 2                       */
int pntIntersectionLineLine(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double r = (p4.y-p3.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p4.x-p3.x);
  if( doubleSign(r)==0 ) return 0;
  res->x = (p3.x*p4.y-p3.y*p4.x)*(p2.x-p1.x)-(p1.x*p2.y-p1.y*p2.x)*(p4.x-p3.x);
  res->y = (p3.y*p4.x-p3.x*p4.y)*(p2.y-p1.y)-(p1.y*p2.x-p1.x*p2.y)*(p4.y-p3.y);
  res->x /= r; res->y /= -r; return 1;
}

/* s=line, t=segment */
int pntIntersectionLineSegment(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double x1,x2,y1,y2;
  if(pntIntersectionLineLine(s,t,res)!=1) return 0;
  x1=MIN(p3.x,p4.x)-EPS; x2=MAX(p3.x,p4.x)+EPS;
  y1=MIN(p3.y,p4.y)-EPS; y2=MAX(p3.y,p4.y)+EPS;
  if(res->x < x1 || x2 < res->x || res->y < y1 || y2 < res->y) return 0;
  if(pntIsEqual(*res,p3)) return 1;
  if(pntIsEqual(*res,p4)) return 1;
  return 2;
}

/* 2 (2) */
/* : 2=, 1=, 0=                    */
int pntIntersectionSegmentSegment(line s,line t,pnt *res){
  pnt p1=s.a, p2=s.b, p3=t.a, p4=t.b;
  double x1,x2,y1,y2;

  if(pntSignAreaOfTriangle(s.a,s.b,t.a)==0 && pntSignAreaOfTriangle(s.a,s.b,t.b)==0){
    if(fabs(s.a.x - s.b.x) > fabs(s.a.y - s.b.y)){
      x1 = s.a.x; x2 = s.b.x;
      y1 = t.a.x; y2 = t.b.x;
    } else {
      x1 = s.a.y; x2 = s.b.y;
      y1 = t.a.y; y2 = t.b.y;
    }
    if(max(y1,y2) < min(x1,x2) - EPS) return 0;
    if(max(x1,x2) < min(y1,y2) - EPS) return 0;
    if(max(y1,y2) < min(x1,x2) + EPS) return 1;
    if(max(x1,x2) < min(y1,y2) + EPS) return 1;
    return 2;
  }
  
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

int N, X[210], Y[210];
ll dp[210][210];
int isCan[210][210];

pnt p[210];

ll solve(int a, int b){
  int i, j, k;
  ll res = 0, tmp;

  if(dp[a][b] >= 0) return dp[a][b];

  if((a+1)%N==b) return dp[a][b] = 1;
  if((a+2)%N==b) return dp[a][b] = 1;

  for(i=(a+1)%N;i!=b;i=(i+1)%N) if(isCan[a][i]&&isCan[b][i]){
    tmp = solve(a,i) * solve(i,b);
    res = (res + tmp) % MD;
  }

  return dp[a][b] = res;
}

int main(){
  int i, j, k, l;
  double mnX, mxX, mnY, mxY;
  ll res;
  line s, t;
  pnt ptmp;

  reader(&N);
  rep(i,N) reader(X+i,Y+i);

  mnX = mxX = X[0];
  mnY = mxY = Y[0];
  rep(i,N){
    mnX = min(mnX, (double)X[i]);
    mxX = max(mxX, (double)X[i]);
    mnY = min(mnY, (double)Y[i]);
    mxY = max(mxY, (double)Y[i]);
  }
  mxX = max(mxX, mnX+1.0);
  mxY = max(mxY, mnY+1.0);

  rep(i,N) p[i] = pntGenerator((X[i]-mnX)/(mxX-mnX), (Y[i]-mnY)/(mxY-mnY));
  REP(i,N,N+3) p[i] = p[i-N];

  rep(i,N) REP(j,i,N){
    isCan[j][i] = isCan[i][j] = 0;
    if(i==j) continue;
    if((i+1)%N==j){ isCan[j][i]=isCan[i][j]=1; continue; }
    if(i==(j+1)%N){ isCan[j][i]=isCan[i][j]=1; continue; }

    s = pntToLine(p[i], p[j]);
    rep(k,N){
      t = pntToLine(p[k], p[k+1]);
      l = pntIntersectionSegmentSegment(s, t, &ptmp);
      if(l==2) break;
      if(l==1 && (k!=i && k!=j && (k+1)%N!=i && (k+1)%N!=j)) break;
    }
    if(k < N) continue;

    ptmp = pntMultipleDouble( pntPlus(p[i],p[j]), 0.5 );
    l = isInPolygon(ptmp, p, N);
    if(l==0 || l==1) continue;
    
    isCan[j][i] = isCan[i][j] = 1;
  }

  rep(i,N) rep(j,N) dp[i][j] = -1;
  res = solve(0, N-1);
  writer((int)res, '\n');

  myed;
  return 0;
}