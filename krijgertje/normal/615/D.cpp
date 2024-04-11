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

const int MAXN=200000;
const int MOD=1000000007;
const int PMOD=MOD-1;

int np;
int p[MAXN];

int q[MAXN],qcnt[MAXN],nq;
int pre[MAXN],suf[MAXN];

int mypow(int x,int n) { int ret=1; while(n>0) { if(n&1) ret=(ll)ret*x%MOD; n>>=1; x=(ll)x*x%MOD; } return ret; }
void run() {
	scanf("%d",&np);
	REP(i,np) scanf("%d",&p[i]); sort(p,p+np);
	nq=0; REP(i,np) if(nq!=0&&q[nq-1]==p[i]) ++qcnt[nq-1]; else q[nq]=p[i],qcnt[nq]=1,++nq;
	REP(i,nq) pre[i]=i==0?1:(ll)pre[i-1]*(qcnt[i-1]+1)%PMOD;
	for(int i=nq-1;i>=0;--i) suf[i]=i==nq-1?1:(ll)suf[i+1]*(qcnt[i+1]+1)%PMOD;

	int ret=1;
	REP(i,nq) {
		int times=(ll)qcnt[i]*(qcnt[i]+1)/2%PMOD;
		int cur=mypow(q[i],(ll)pre[i]*suf[i]%PMOD*times%PMOD);
		//printf("%d (%d): %d^(%d*%d*%d)=%d\n",q[i],qcnt[i],q[i],pre[i],times,suf[i],cur);
		ret=(ll)ret*cur%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}