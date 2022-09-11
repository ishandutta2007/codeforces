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

const int MAXN=100000;
struct Q {
	int aget,bget; double p;
	double cnst,upto; // E(k)=E(k-1)+p*((k-1)*z-E(k-1))+cnst

};
bool operator<(const Q &a,const Q &b) { return a.cnst>b.cnst; }

int n; ll t;
Q q[MAXN];

Q use[MAXN]; int nuse;

double overtake(const Q &a,const Q &b) {
	return (b.cnst-a.cnst)/(a.p-b.p);
}

double pw(double x,ll n) { double ret=1; while(true) { if(n&1) ret=ret*x; if((n>>=1)==0) return ret; x=x*x; } }

double solve() {
	double z=0; REP(i,n) z=max(z,q[i].bget*q[i].p);
	REP(i,n) q[i].cnst=q[i].p*q[i].aget;
	//REP(i,n) printf("%d: p=%lf cnst=%lf\n",i,q[i].p,q[i].cnst);

	sort(q,q+n);
	nuse=0;
	REP(i,n) {
		if(nuse>0&&q[i].p<=use[nuse-1].p) continue;
		while(nuse>=2&&overtake(use[nuse-1],use[nuse-2])>overtake(q[i],use[nuse-1])) --nuse;
		use[nuse++]=q[i];
	}
	//REP(i,nuse) printf("%d: p=%lf cnst=%lf (%lf)\n",i,use[i].p,use[i].cnst,i+1<nuse?overtake(use[i+1],use[i]):-1);

	double ret=0; ll k=0;
	// E(k)=(1-p)*E(k-1)+p*(k-1)*z+cnst = (1-p)*(1-p)*E(k-2)+p*((k-1)+(1-p)*(k-2))*z+cnst*(1+(1-p))
	// F(k)=k*z-E(k) -> F(k)=z-cnst+(1-p)*F(k-1) = (z-cnst)*(1+(1-p))+(1-p)*(1-p)*F(k-2)
	REP(i,nuse) {
		ll ntimes;
		if(i+1<nuse) {
			ll l=-1,h=t-k;
			while(l+1<h) {
				ll m=l+(h-l)/2;
				double pp=pw(1-use[i].p,m);
				double have=pp*(k*z-ret)+(z-use[i].cnst)*(1-pp)/use[i].p,want=overtake(use[i+1],use[i]);
				//printf("\t%lld: have=%lf want=%lf (%lf,%lf)\n",m,have,want,pp,z-use[i].cnst);
				if(have>want) h=m; else l=m; 
			}
			ntimes=h;
		} else {
			ntimes=t-k;
		}
		{
			//printf("ntimes=%lld\n",ntimes);
			ll nk=k+ntimes;
			double pp=pw(1-use[i].p,ntimes);
			double have=pp*(k*z-ret)+(z-use[i].cnst)*(1-pp)/use[i].p;
			//printf("\t%lld: have=%lf (%lf,%lf)\n",ntimes,have,pp,z-use[i].cnst);
			ret=nk*z-have;
			k=nk;
		}
	}

	return ret;
}

void run() {
	scanf("%d%lld",&n,&t);
	REP(i,n) scanf("%d%d%lf",&q[i].aget,&q[i].bget,&q[i].p);
	printf("%.15lf\n",solve());
}

int main() {
	run();
	return 0;
}