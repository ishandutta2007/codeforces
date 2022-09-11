#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;

int n,basew;
int a[MAXN];
int b[MAXN];

bool ok(double fuel) {
	REP(i,n) {
		{
			double w=basew+fuel;
			double need=w/a[i];
			if(need>fuel) return false;
			fuel-=need;
		}
		{
			double w=basew+fuel;
			double need=w/b[(i+1)%n];
			if(need>fuel) return false;
			fuel-=need;
		}
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&basew);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);

	double l=0,h=2*1e9;
	REP(rep,200) {
		double m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	double ret=l+(h-l)/2;
	if(ret>1.5*1e9) printf("-1\n"); else printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}