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

long double MYPI=acos(-1);
double x,y,r,X,Y,R;

long double calc() {
	long double dx=x-X,dy=y-Y,d=std::sqrt(dx*dx+dy*dy);
	if(d>R+r) return 0;
	if(r<=R-d) return MYPI*r*r;
	if(R<=r-d) return MYPI*R*R;
	long double x=(r*r-R*R+d*d)/(2*d),X=d-x;
	long double h=sqrt(r*r-x*x),H=sqrt(R*R-X*X);
	long double a=atan2l(h,x),A=atan2l(H,X);
	//printf("d=%.20Lf x=%.20Lf X=%.20Lf h=%.20Lf H=%.20Lf a=%.20Lf A=%.20Lf\n",d,x,X,h,H,a,A);
	return a*r*r-x*h+A*R*R-X*H;
}

void run() {
	scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&r,&X,&Y,&R);
	printf("%.20lf\n",(double)calc());
}

int main() {
	run();
	return 0;
}