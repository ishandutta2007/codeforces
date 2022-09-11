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
#include <bitset>
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

const int MAXN=100;
const int MAXPOINT=10;
struct Z { int a,p; };
bool operator<(const Z &u,const Z &v) { return u.a>v.a; }

int n;
double C,T;
Z z[MAXN];

double mlt[MAXN];
double dp[MAXN+1][MAXN+1][MAXPOINT*MAXN+1]; // dp[i][j][k] = with j solutions out of the first i the minimum value of sum(ai/0.9^i) when getting k points

void upd(double &a,double b) { a=min(a,b); }
int solve() {
	sort(z,z+n);
	//printf("z:"); REP(i,n) printf(" (%d,%d)",z[i].a,z[i].p); puts("");
	REPE(i,n) REPE(j,n) REPE(k,MAXPOINT*n) dp[i][j][k]=1e200;
	dp[0][0][0]=0;
	mlt[0]=1/0.9; FOR(i,1,n) mlt[i]=mlt[i-1]/0.9;
	REP(i,n) REPE(j,n) REPE(k,MAXPOINT*n) if(dp[i][j][k]<1e100) {
		upd(dp[i+1][j][k],dp[i][j][k]);
		upd(dp[i+1][j+1][k+z[i].p],dp[i][j][k]+z[i].a*mlt[j]);
	}
	int ret=0;
	FORE(j,1,n) REPE(k,MAXPOINT*n) if(dp[n][j][k]<1e100) {
		// j*10+x+dp[n][j][k]/(1+C*x)
		// 1-C*dp[n][j][k]/(1+C*x)^2=0 -> x=sqrt(dp[n][j][k]/C)-1/C
		double x=sqrt(dp[n][j][k]/C)-1.0/C; x=max(x,0.0);
		double t=10*j+x+dp[n][j][k]/(1+C*x);
		if(t<=T) ret=max(ret,k);
		//printf("with %d solutions we can get %d points at cost of %lf -> x=%lf -> t=%lf\n",j,k,dp[n][j][k],x,t);
	}
	return ret;
}

void run() {
	double tmp=0.5;
	scanf("%d",&n);
	scanf("%lf%lf",&C,&T);
	REP(i,n) scanf("%d%d",&z[i].a,&z[i].p);
	printf("%d\n",solve());
}

void stress() {
	REP(rep,20) {
		n=MAXN;
		C=0.01*(1+rand()%1000);
		T=200000;
		REP(i,n) z[i].a=rand()%10000+1,z[i].p=rand()%10+1;
		solve();
		printf(".");
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//stress();
	return 0;
}