#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

typedef struct P { double x,y; P(double x,double y):x(x),y(y) {} } P;
const P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const P operator*(const double &a,const P &b) { return P(a*b.x,a*b.y); }
void print(const P &p) { printf("%.9lf %.9lf\n",p.x,p.y); }

int px,py,vx,vy,a,b,c,d;

void run() {
	scanf("%d%d%d%d %d%d%d%d",&px,&py,&vx,&vy,&a,&b,&c,&d);

	P p(px,py);
	double v=sqrt(vx*vx+vy*vy); P u(vx/v,vy/v),n(-vy/v,vx/v);
	//printf("\t%.9lf: ",v); print(u);

	print(p+1.0*b*u);
	print(p+0.5*a*n);
	print(p+0.5*c*n);
	print(p-1.0*d*u+0.5*c*n);
	print(p-1.0*d*u-0.5*c*n);
	print(p-0.5*c*n);
	print(p-0.5*a*n);
}

int main() {
	run();
	return 0;
}