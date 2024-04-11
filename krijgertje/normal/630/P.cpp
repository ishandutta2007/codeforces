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

int n,r;
const double MYPI=acos(-1);

void run() {
	scanf("%d%d",&n,&r);

	double a=2*MYPI/n;
	double b=a/4;
	double c=MYPI/2-a*3/4;
	double d=a/4;
	double x=r*sin(a/2);
	double y=x*tan(c);
	double Y=x*tan(b+c);
	// r^2*sin(a/2)*sin(a/2)*tan(MYPI/2-a*3/4) = r*sin(a/2)*sin(MYPI/2-a*3/4)/cos(MYPI/2-a*3/4) = r*sin(a/2)*cos(a*3/4)/sin(a*3/4)
	// n*x*Y=n*r*r*sin(a/2)*sin(a/2)*cos(2*d)/sin(2*d)
	//printf("a=%lf, b=%lf, c=%lf, x=%lf, y=%lf, Y=%lf\n",a*180/MYPI,b*180/MYPI,c*180/MYPI,x,y,Y);
	printf("%.12lf\n",1.0*n*r*r*sin(2*d)*sin(2*d)*(cos(2*d)/sin(2*d)-cos(3*d)/sin(3*d)));
}

int main() {
	run();
	return 0;
}