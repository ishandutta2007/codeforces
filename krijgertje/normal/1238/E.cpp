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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXLEN=100000;
const int MAXALPH=20;

int slen,alph;
char s[MAXLEN+1];

int cnt[MAXALPH][MAXALPH];

int dp[1<<MAXALPH];
int val[1<<MAXALPH];

int solve() {
	memset(cnt,0,sizeof(cnt));
	REP(i,slen-1) {
		int x=s[i]-'a',y=s[i+1]-'a';
		if(x!=y) ++cnt[x][y],++cnt[y][x];
	}
	val[0]=0;
	FOR(mask,1,1<<alph) {
		int idx=0; while(idx<alph&&(mask&(1<<idx))==0) ++idx; assert(idx<alph);
		int pmask=mask-(1<<idx);
		val[mask]=val[pmask];
		REP(i,alph) if((pmask&(1<<i))!=0) val[mask]-=cnt[i][idx];
		REP(i,alph) if((mask&(1<<i))==0) val[mask]+=cnt[idx][i];
	}

	REP(mask,1<<alph) dp[mask]=INT_MAX;
	dp[0]=0;
	REP(mask,1<<alph) if(dp[mask]!=INT_MAX) {
		REP(i,alph) if((mask&(1<<i))==0) {
			int nmask=mask|(1<<i);
			int cur=dp[mask]+val[nmask];
			dp[nmask]=min(dp[nmask],cur);
		}
	}
	return dp[(1<<alph)-1];
}

void run() {
	scanf("%d%d",&slen,&alph);
	scanf("%s",s); assert(strlen(s)==slen);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}