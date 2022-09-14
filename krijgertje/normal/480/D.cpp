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

typedef struct X { int in,out,w,s,val; } X;
bool operator<(const X &p,const X &q) { if(p.in!=q.in) return p.in<q.in; return p.out<q.out; }

int n,S;
X x[501];

int mem[501][1001];
int dp[1001];

int calc(int at,int s) {
	int &ret=mem[at][s];
	if(ret==-1) {
		REP(i,n) if(i!=at&&x[i].w<=s&&x[at].in<=x[i].in&&x[i].out<=x[at].out) calc(i,min(s-x[i].w,x[i].s));
		FORE(i,x[at].in,x[at].out) dp[i]=x[at].val;
		int last=x[at].in;
		REP(i,n) if(i!=at&&x[i].w<=s&&x[at].in<=x[i].in&&x[i].out<=x[at].out) {
			while(last<x[i].in) { if(dp[last]>dp[last+1]) dp[last+1]=dp[last]; ++last; }
			int nval=dp[x[i].in]+mem[i][min(s-x[i].w,x[i].s)];
			if(nval>dp[x[i].out]) dp[x[i].out]=nval;
		}
		while(last<x[at].out) { if(dp[last]>dp[last+1]) dp[last+1]=dp[last]; ++last; }
		ret=dp[x[at].out];
		//printf("%d %d: %d\n",at,s,ret);
		//FORE(i,x[at].in,x[at].out) printf("%d ",dp[i]); puts("");
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	x[n].in=0,x[n].out=2*n,x[n].w=0,x[n].val=0; scanf("%d",&x[n].s);
	REP(i,n) scanf("%d%d%d%d%d",&x[i].in,&x[i].out,&x[i].w,&x[i].s,&x[i].val);

	sort(x,x+n);
	memset(mem,-1,sizeof(mem));
	int ret=calc(n,x[n].s);
	printf("%d\n",ret);	
}

int main() {
	run();
	return 0;
}