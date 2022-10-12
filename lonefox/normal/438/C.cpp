#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const double EPS = 1e-9;
const LD PI = acos(-1.0);

#define MOD 1000000007

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d)
{
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

// determine if line segment from a to b intersects with 
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

int N;
int X[200],Y[200];
bool val[200][200];
int mem[200][200];

LL Cross(LL x1,LL y1,LL x2,LL y2)
{
	return(x1*y2 - x2*y1);
}

int rec(int i,int d)
{
	int j=(i+d)%N;
		if (!val[i][j])
			return(0);
		if (N-d<2)
			return(1);
		if (mem[i][d]>=0)
			return(mem[i][d]);
	int v=0,k,d2;
	int v1,v2,v3;
		FoxI(d2,d+1,N-1)
		{
			k=(i+d2)%N;
				if ((!val[i][k]) || (!val[j][k]))
					continue;
			/*v1=rec(j,N-d);
				if (!v1)
					continue;*/
			v2=rec(k,N-(d2-d));
				if (!v2)
					continue;
			v3=rec(i,d2);
				if (!v3)
					continue;
			v=(v+(LL)v2*v3)%MOD;
		}
	//printf("%d %d %d\n",i,j,v);
	return(mem[i][d]=v);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,a,d;
	LL c;
	bool pos;
	double c1,c2,c3;
	LL v=0;
	PT A,B,C,D,V1,V2,V3;
	Fill(mem,-1);
	Read(N);
		Fox(i,N)
			Read(X[i]),Read(Y[i]);
		Fox(i,N)
		{
			j=(i+1)%N;
			v+=(LL)(X[j]-X[i])*(Y[j]+Y[i]);
		}
	pos=(v>0);
		Fox(i,N)
			Fox1(d,N-1)
			{
				j=(i+d)%N;
					if ((d==1) || (d==N-1))
						goto Good;
					Fox(k,N)
						if ((k!=i) && (k!=j))
						{
							A=PT(X[i],Y[i]);
							B=PT(X[j],Y[j]);
							C=PT(X[k],Y[k]);
								if (DistancePointSegment(A,B,C)<EPS)
									goto Bad;
						}
					Fox(a,N)
					{
						k=(a+1)%N;
							if ((k!=i) && (k!=j) && (a!=i) && (a!=j))
							{
								A=PT(X[i],Y[i]);
								B=PT(X[j],Y[j]);
								C=PT(X[k],Y[k]);
								D=PT(X[a],Y[a]);
									if (SegmentsIntersect(A,B,C,D))
										goto Bad;
							}
					}
				k=(i+1)%N;
				a=(i-1+N)%N;
				V1=PT(X[k]-X[i],Y[k]-Y[i]);
				V2=PT(X[a]-X[i],Y[a]-Y[i]);
				V3=PT(X[j]-X[i],Y[j]-Y[i]);
				c1=cross(V1,V2);
				c2=cross(V1,V3);
				c3=cross(V3,V2);
					if (pos)
						c1=-c1,c2=-c2,c3=-c3;
					if ((c1>-EPS) && (c2>-EPS) && (c3>-EPS))
						goto Good;
					if ((c1<-EPS) && (!((c2<-EPS) && (c3<-EPS))))
						goto Good;
				goto Bad;
Good:;
				val[i][j]=1;
Bad:;
			}
	printf("%d\n",rec(0,1));
	return(0);
}