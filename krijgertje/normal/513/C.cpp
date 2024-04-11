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

int n;
int l[5],r[5];

double ple[5],pl[5];
double lple[5],lpl[5];
double rple[5],rpl[5];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);
	int ll=l[0]; REP(i,n) if(l[i]<ll) ll=l[i];
	int rr=r[0]; REP(i,n) if(r[i]>rr) rr=r[i];
	double ret=0;
	FORE(x,ll,rr) {
		REP(i,n) ple[i]=x<l[i]?0:x>r[i]?1:1.0*(x-l[i]+1)/(r[i]-l[i]+1);
		REP(i,n) pl[i]=x<l[i]?0:x>r[i]?1:1.0*(x-l[i])/(r[i]-l[i]+1);
		lple[0]=1; FOR(i,1,n) lple[i]=lple[i-1]*ple[i-1];
		lpl[0]=1; FOR(i,1,n) lpl[i]=lpl[i-1]*pl[i-1];
		rple[n-1]=1; for(int i=n-2;i>=0;--i) rple[i]=rple[i+1]*ple[i+1];
		rpl[n-1]=1; for(int i=n-2;i>=0;--i) rpl[i]=rpl[i+1]*pl[i+1];
		double cur=0;
		// p(vi>x)*(p(vj<=x)-p(vj<x))
		REP(i,n) cur+=(1-ple[i])*(lple[i]*rple[i]-lpl[i]*rpl[i]);
		// p(vi=x)*p(vj<x)*(p(vk<=x)-p(vk<x))
		REP(i,n) cur+=(ple[i]-pl[i])*lpl[i]*(rple[i]-rpl[i]);
		//REP(i,n) printf("\t(%lf,%lf) / (%lf,%lf) / (%lf,%lf)\n",lpl[i],lple[i],pl[i],ple[i],rpl[i],rple[i]);
		//printf("%d: %lf\n",x,cur);
		ret+=cur*x;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}