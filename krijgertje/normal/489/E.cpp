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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n,want;
int x[1000],val[1000];

double best[1000]; int prv[1000];

double cost(int have) { return sqrt(1.0*abs(have-want)); }

bool debug;
bool can(double r) { // r*sum(gain)-sum(cost)>=0
	REP(i,n) best[i]=r*val[i]-cost(x[i]),prv[i]=-1;
	REP(i,n) FOR(j,i+1,n) {
		double cur=best[i]+r*val[j]-cost(x[j]-x[i]);
		if(cur>best[j]) best[j]=cur,prv[j]=i;
	}
//	if(debug) REP(i,n) printf("\t%d: %lf (%d)\n",i,best[i],prv[i]);
//	printf("%lf -> %lf\n",r,best[n-1]);
	return best[n-1]>=0;
}

int ret[1000],nret;
void save() {
	nret=0;
	for(int x=n-1;x!=-1;x=prv[x]) ret[nret++]=x;
	REP(i,nret/2) swap(ret[i],ret[nret-i-1]);
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d%d",&x[i],&val[i]);

	debug=true; can(.5); debug=false;
	double l=0,h=1000; nret=0;
	REP(times,100) {
		double m=l+(h-l)/2;
		if(can(m)) { save(); h=m; } else l=m;
	}
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}