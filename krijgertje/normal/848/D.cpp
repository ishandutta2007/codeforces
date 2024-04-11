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

const int MAXN=52;
const int MAXFLOW=52;
const int MOD=1000000007;

int inv[MAXN+1];

int calc(int n,int k) {
	int ret=1;
	REP(i,k) ret=(ll)ret*(n+k-1-i)%MOD*inv[i+1]%MOD;
	return ret;
}

int memfsum[MAXN+1][MAXFLOW+1];
int f(int n,int flow);
int fsum(int n,int flow) {
	if(n<2||flow>n-1) return 0;
	int &ret=memfsum[n][flow];
	if(ret==-1) ret=(f(n,flow)+fsum(n,flow+1))%MOD;
	return ret;
}

int memg[MAXN+1][MAXFLOW+1];
int g(int n,int flow) {
	//printf("g(%d,%d)...\n",n,flow);
	if(n<3||flow<1||flow>(n-1)/2) return 0;
	int &ret=memg[n][flow];
	if(ret==-1) {
		ret=0;
		for(int n1=2;n1<n;++n1) {
			int n2=n-n1+1;
			int cur=((ll)f(n1,flow)*fsum(n2,flow)+(ll)fsum(n1,flow+1)*f(n2,flow))%MOD;
			ret=(ret+cur)%MOD;
		}
		//printf("g(%d,%d)=%d\n",n,flow,ret);
	}
	return ret;
}

int memf[MAXN+1][MAXFLOW+1][MAXN+1][MAXFLOW+1];
int f(int n,int flow,int subn,int subflow) {
	//printf("f(%d,%d,%d,%d)...\n",n,flow,subn,subflow);
	if(n==0&&flow==0) return 1;
	if(flow==0) return 0;
	if(subflow>flow) return f(n,flow,subn+1,1);
	if(subn>n) return 0;
	int &ret=memf[n][flow][subn][subflow];
	if(ret==-1) {
		ret=f(n,flow,subn,subflow+1);
		for(int i=1;i*subn<=n&&i*subflow<=flow;++i) {
			int cur=g(2+subn,subflow);
			int mlt=f(n-i*subn,flow-i*subflow,subn,subflow+1);
			ret=(ret+(ll)calc(cur,i)*mlt)%MOD;
		}
		//printf("f(%d,%d,%d,%d)=%d\n",n,flow,subn,subflow,ret);
	}
	return ret;
}
int f(int n,int flow) {
	if(n<2||flow<1||flow>n-1) return 0;
	return f(n-2,flow-1,1,1);
}

void run() {
	memset(memfsum,-1,sizeof(memfsum));
	memset(memg,-1,sizeof(memg));
	memset(memf,-1,sizeof(memf));
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;

	int n,flow; scanf("%d%d",&n,&flow);
	int ret=f(n+2,flow);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}