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

const int MAXN=60000;

int n;
int x[MAXN],v[MAXN];

bool ok(double t) {
	//printf("testing %.9lf\n",t);
	double l=x[0]-t*v[0],r=x[0]+t*v[0];
	FOR(i,1,n) {
		l=max(l,x[i]-t*v[i]);
		r=min(r,x[i]+t*v[i]);
	}
	return l<=r;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]); REP(i,n) scanf("%d",&v[i]);
	double l=0,h=1000000000;
	REP(i,100) {
		double m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	printf("%.9lf\n",h);
}

int main() {
	run();
	return 0;
}