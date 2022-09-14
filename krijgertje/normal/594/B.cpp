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

double MYPI=acos(-1);

int n,r,v;
double calc(double t) {
	double a=t*v/r/2;
	a-=floor(a/MYPI)*MYPI;
	return t*v+r*(sin(a)-sin(a-t*v/r));
}

void run() {
	scanf("%d%d%d",&n,&r,&v);
	REP(i,n) {
		int a,b; scanf("%d%d",&a,&b); int want=b-a;
		double l=0,h=1;
		while(calc(h)<want) l=h,h+=h;
		REP(j,100) {
			double m=l+(h-l)/2;
			if(calc(m)<want) l=m; else h=m;
			if(abs(l-h)/max(1.0,l)<1e-6) break;
		}
		printf("%.9lf\n",l+(h-l)/2);
	}
}

int main() {
	run();
	return 0;
}