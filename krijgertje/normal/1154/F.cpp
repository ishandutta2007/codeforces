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

const int MAXN=200000;
const int MAXOFFER=200000;
const int MAXNEED=2000;


int n,noffer,need;
int a[MAXN];
int offersize[MAXOFFER],offerfree[MAXOFFER];

int bestoffer[MAXNEED+1];
ll dp[MAXNEED+1];
ll asum[MAXN+1];

ll solve() {
	sort(a,a+n);
	REPE(i,need) bestoffer[i]=0;
	REP(i,noffer) if(offersize[i]<=need) bestoffer[offersize[i]]=max(bestoffer[offersize[i]],offerfree[i]);

	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	REPE(i,need) dp[i]=LLONG_MAX; dp[0]=0;
	REP(i,need) REPE(j,need-i) {
		ll cur=dp[i]+asum[i+j]-asum[i+bestoffer[j]];
		dp[i+j]=min(dp[i+j],cur);
	}
	return dp[need];
}

void run() {
	scanf("%d%d%d",&n,&noffer,&need);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,noffer) scanf("%d%d",&offersize[i],&offerfree[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}