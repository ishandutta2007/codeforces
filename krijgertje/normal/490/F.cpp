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

int n;
int pop[6000];
int fst[6000];
int nxt[12000];
int fm[12000];
int to[12000];

int dp[12000]; // dp[i] max nr of concerts when last was in fm[i] and we travel in the direction of to[i]

int go(int at,int prv,int last) {
	int ret=pop[at]>last?1:0;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==prv) continue;
		{
			int cur=go(to[x],at,last);
			if(cur>ret) ret=cur;
		}
		if(pop[at]>last) {
			if(dp[x]==-1) dp[x]=1+go(to[x],at,pop[at]);
			if(dp[x]>ret) ret=dp[x];
		}
	}
	//printf("go(%d,%d,%d)=%d\n",prv,at,last,ret);
	return ret;
}

void run() {
	memset(fst,-1,sizeof(fst));
	scanf("%d",&n);
	REP(i,n) scanf("%d",&pop[i]);
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; fm[2*i+0]=a; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; fm[2*i+1]=b; to[2*i+1]=a;
	}

	memset(dp,-1,sizeof(dp));
	int ret=0;
	REP(i,2*(n-1)) {
		if(dp[i]==-1) dp[i]=1+go(to[i],fm[i],pop[fm[i]]);
		if(dp[i]>ret) ret=dp[i];
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}