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

const int MAXN=1000;
const int MAXSUM=10000;

ll dp[MAXN+1][MAXSUM+1];

int n,smana,scap,gaincap,gainmana;
int cnt[MAXN],cost[MAXN];

pair<int,ll> q[MAXSUM+1]; int qhead,qtail;
void addtoq(int idx,ll val) { while(qtail<qhead&&val>=q[qhead-1].second) --qhead; q[qhead++]=MP(idx,val); }

void run() {
	scanf("%d%d%d%d",&n,&smana,&gaincap,&gainmana); scap=smana; REP(i,n) scanf("%d",&cnt[i]); REP(i,n) scanf("%d",&cost[i]);
	
	int sum=0; REP(i,n) sum+=cnt[i];
	REPE(i,n) REPE(j,sum) dp[i][j]=LLONG_MIN; dp[0][0]=smana;
	FORE(i,1,n) {
		qhead=qtail=0;
		REPE(j,sum) {
			while(qtail<qhead&&q[qtail].first<j-cnt[i-1]) ++qtail;
			if(dp[i-1][j]!=LLONG_MIN) addtoq(j,dp[i-1][j]+(ll)j*cost[i-1]);
			if(qtail<qhead&&q[qtail].second-(ll)j*cost[i-1]>=0) dp[i][j]=min(q[qtail].second-(ll)j*cost[i-1]+gainmana,scap+(ll)j*gaincap); else dp[i][j]=LLONG_MIN;
		}
	}
	int ret=-1; REPE(j,sum) if(dp[n][j]!=LLONG_MIN) ret=max(ret,j); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}