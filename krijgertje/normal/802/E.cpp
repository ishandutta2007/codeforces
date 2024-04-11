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
	double sum=0; REP(i,N) sum+=x[i]; double avg=sum/N;
	double sumsq=0; REP(i,N) sumsq+=(x[i]-avg)*(x[i]-avg); double var=sumsq/(N-1);
	double res=3*var/avg/avg;
	return res>.6;
}

int solve() {
	if(solvetype()) {
		int ret=x[0]; REP(i,N) ret=max(ret,x[i]); return ret/2;
	} else {
		double sum=0; REP(i,N) sum+=x[i]; double avg=sum/N;
		return (int)floor(avg+.5);
	}
}




void run() {
	REP(i,N) scanf("%d",&x[i]);
	printf("%d\n",solve());	
}

void test(int have,int want) {
	printf("%.9lf (have=%d want=%d)\n",1.0*have/want,have,want);
	//if(have<.95*want||have>1.05*want) { printf("err\n"); exit(0); }
}

void testunif() {
	int P=rand()%(1000-10+1)+10;
	REP(i,N) x[i]=rand()%(2*P+1);
	test(solve(),P);
}

void testpoisson() {
	int P=rand()%(1000-10+1)+10;
	//int P=1000;
	double L=exp(-1.0*P);
	REP(i,N) {
		int k=0; double p=1;
		do { ++k; double u=1.0*rand()/RAND_MAX; p*=u; } while(p>L);
		x[i]=k-1;
	}
	test(solve(),P);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//REP(i,1000) testpoisson();
	//REP(i,1000) testunif();

	return 0;
}