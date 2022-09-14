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

const int MAXK=1000;
const int STEPS=2000;
const int MAXSTEP=1000;

double mypow(double x,int n) { double ret=1; while(true) { if(n&1) ret=ret*x; if((n>>=1)==0) return ret; x*=x; } }
double calc(int k,int n) {
	double ret=0; double mlt=1;
	REPE(j,k) {
		double cur=mlt*mypow(1.0*j/k,n);
		if(j%2==0) ret+=cur; else ret-=cur;
		mlt=mlt*(k-j)/(j+1);
	}
	return ret;
}

double dp[2][MAXK+1];

int ans[MAXSTEP+1];

// S(n,k)=k*S(n-1,k)+S(n-1,k-1) S(0,0)=1 S(n,0)=S(0,k)=0
// F(n,k)=k!*S(n,k)/k^n
// F(n,k)=F(n-1,k)+((k-1)/k)^(n-1)*F(n-1,k-1)
// F(n-1,k-1)=(k-1)!/(k-1)^(n-1)*S(n-1,k-1)
double calc2(int k) {
	int idx=0;
	int at=0; REPE(i,k) dp[at][i]=0; dp[at][1]=1;
	while(idx<=MAXSTEP&&dp[at][k]>=1.0*idx/STEPS) ans[idx++]=1;
	for(int i=2;idx<=MAXSTEP;++i) {
		dp[1-at][0]=0;
		FORE(j,1,k) dp[1-at][j]=dp[at][j]+mypow(1.0*(j-1)/j,i-1)*dp[at][j-1];
		at=1-at;
		while(idx<=MAXSTEP&&dp[at][k]>=1.0*idx/STEPS) ans[idx++]=i;
		//REPE(j,k) printf("%.2lf ",dp[at][j]); puts("");
	}
	return dp[at][k];
}


int k,nq;


void run() {
	scanf("%d%d",&k,&nq);
	calc2(k);
	//int at=-1; FORE(i,1,MAXSTEP) if(at==-1||ans[i]!=ans[at]) { at=i; printf("%d: %d\n",i,ans[i]); }
	REP(i,nq) {
		int q; scanf("%d",&q);
		printf("%d\n",ans[q]);
	}
}

int main() {
	run();
	return 0;
}