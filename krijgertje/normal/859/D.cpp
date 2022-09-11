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

const int MAXN=6;

int n;
int p[1<<MAXN][1<<MAXN];

double pwins[1<<MAXN][MAXN+1];

double dp[1<<MAXN][MAXN]; // dp[i][r] = maximum expected points in subbracket of i for round <= r, assuming i is our canditate for round r

void run() {
	scanf("%d",&n); REP(i,1<<n) REP(j,1<<n) scanf("%d",&p[i][j]);

	REP(i,1<<n) pwins[i][0]=1;
	REP(r,n) REP(i,1<<n) {
		int rsz=2<<r,hsz=1<<r,ra=i/rsz*rsz; 
		pwins[i][r+1]=0;
		REP(dj,rsz) if((i%rsz/hsz)!=(dj%rsz/hsz)) {
			int j=ra+dj;
			pwins[i][r+1]+=pwins[i][r]*pwins[j][r]*0.01*p[i][j];
		}
	}
	//REP(i,1<<n) { printf("%d:",i); REPE(r,n) printf(" %lf",pwins[i][r]); puts(""); }

	REPE(r,n) REP(i,1<<n) {
		int rsz=2<<r,hsz=1<<r,ra=i/rsz*rsz,rp=1<<r;
		dp[i][r]=0;
		double here=0;
		REP(dj,rsz) if((i%rsz/hsz)!=(dj%rsz/hsz)) {
			int j=ra+dj;
			here+=rp*pwins[i][r]*pwins[j][r]*0.01*p[i][j];
		}
		REP(dj,rsz) if((i%rsz/hsz)!=(dj%rsz/hsz)) {
			int j=ra+dj; double cur=here;
			if(r!=0) cur+=dp[i][r-1];
			if(r!=0) cur+=dp[j][r-1];
			if(cur>dp[i][r]) dp[i][r]=cur;
		}
		//printf("round %d player %d: here=%lf -> %lf\n",r,i,here,dp[i][r]);
	}

	double ret=0; REP(i,1<<n) ret=max(ret,dp[i][n-1]); printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}