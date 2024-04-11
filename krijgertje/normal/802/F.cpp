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

const int N=250;

int x[N];

bool solvetype() {
	int mn=x[0]; FOR(i,1,N) if(x[i]<mn) mn=x[i];
	int mx=x[0]; FOR(i,1,N) if(x[i]>mx) mx=x[i];
	double bestunif=-1e200;
	FORE(P,(mx-mn+1)/2,1000) {
		double cur=N*log(1.0/(2*P+1));
		if(cur>bestunif) bestunif=cur;
	}
	double bestpois=-1e200;
	vector<double> lfac(1); lfac[0]=log(1.0);
	double sum=0; REP(i,N) sum+=x[i]; int avg=(int)floor(sum/N+.5);
	FORE(c,avg,avg) FORE(P,max(1,c-mn),1000) {
		int z=c-P;
		//if(!(z==-59&&P==8)&&!(z==-73&&P==22)) continue;
		double cur=0;
		//set<int> seen;
		REP(i,N) {
			// P^y*exp(-P)/y! -> y*log(P)-P-log(y!)
			int y=x[i]-z; while(y>=SZ(lfac)) lfac.PB(lfac.back()+log(1.0*SZ(lfac)));
			long double now=y*log(1.0*P)-lfac[y]-P; cur+=now;
			//if(!seen.count(x[i])) { seen.insert(x[i]); printf("\t%d: %lf (%d*%lf-%lf-%d)\n",x[i],now,y,log(1.0*P),lfac[y],P); }
		}
		if(cur>bestpois) {
			//printf("\tc=%d P=%d cur=%.9lf z=%d\n",c,P,cur,z);
			bestpois=cur;
		}
	}
	//printf("bestunif=%.9lf bestpois=%.9lf diff=%.9lf\n",bestunif,bestpois,bestunif-bestpois);
	return bestunif>bestpois;
}


void run() {
	REP(i,N) scanf("%d",&x[i]);
	printf("%s\n",solvetype()?"uniform":"poisson");	
}

void test(bool have,bool want,int P) {
	if(have!=want) printf("err (have=%s,want=%s,P=%d)\n",have?"uniform":"poisson",want?"uniform":"poisson",P);
}

void testunif() {
	int mod=rand()%201-100;
	int P=rand()%(10-1+1)+1;
	//printf("mod=%d P=%d\n",mod,P);
	REP(i,N) x[i]=rand()%(2*P+1)+mod;
	test(solvetype(),true,P);
}

void testpoisson() {
	int mod=rand()%201-100;
	int P=rand()%(10-1+1)+1;
	//printf("mod=%d P=%d\n",mod,P);
	//int P=1000;
	double L=exp(-1.0*P);
	REP(i,N) {
		int k=0; double p=1;
		do { ++k; double u=1.0*rand()/RAND_MAX; p*=u; } while(p>L);
		x[i]=k-1+mod;
	}
	//REP(i,N) printf("%d ",x[i]); puts("");
	test(solvetype(),false,P);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//REP(i,100) testpoisson();
	//REP(i,100) testunif();
	return 0;
}