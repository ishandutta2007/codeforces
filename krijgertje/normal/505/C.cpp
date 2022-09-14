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

const int N=30001;
const int MAXSUM=6000000;

int ngem,d0;
int gem[30000];

bool can[N];
int mind[N];
int maxd[N];
int offset[N];
int cnt[N];

int dp[MAXSUM];

void run() {
	scanf("%d%d",&ngem,&d0);
	REP(i,ngem) scanf("%d",&gem[i]);
	REP(i,N) cnt[i]=0; REP(i,ngem) cnt[gem[i]]++;

	REP(i,N) can[i]=false;
	can[d0]=true; mind[d0]=maxd[d0]=d0;
	REP(i,N) if(can[i]) FORE(d,mind[i]-1,maxd[i]+1) if(i+d<N) {
		if(!can[i+d]) { can[i+d]=true; mind[i+d]=maxd[i+d]=d; }
		if(d<mind[i+d]) mind[i+d]=d;
		if(d>maxd[i+d]) maxd[i+d]=d;
	}

	int sum=0; REP(i,N) if(can[i]) sum+=maxd[i]-mind[i]+1; assert(sum<MAXSUM);
	offset[0]=0; FOR(i,1,N) offset[i]=offset[i-1]+(can[i-1]?maxd[i-1]-mind[i-1]+1:0);

	int ret=cnt[d0];
	REP(i,sum) dp[i]=-1; dp[offset[d0]+0]=cnt[d0];
	REP(i,N) if(can[i]) FORE(d,mind[i],maxd[i]) if(dp[offset[i]+d-mind[i]]!=-1) FORE(nd,d-1,d+1) if(i+nd<N&&nd>=1) {
		int j=offset[i]+d-mind[i],nj=offset[i+nd]+nd-mind[i+nd],nval=dp[j]+cnt[i+nd];
		//if(nval>dp[j]) printf("%d %d -> %d %d = %d to %d\n",i,d,i+nd,nd,dp[j],nval);
		if(nval>dp[nj]) dp[nj]=nval;
		if(nval>ret) ret=nval;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}