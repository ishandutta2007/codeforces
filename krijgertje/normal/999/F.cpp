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

const int MAXPLAYER=500;
const int MAXEACH=10;
const int MAXCARD=MAXPLAYER*MAXEACH;

int nplayer,neach,ncard;
int card[MAXCARD];
int fav[MAXPLAYER];
int gain[MAXEACH+1];

ll dp[MAXPLAYER+1][MAXCARD+1];


void run() {
	scanf("%d%d",&nplayer,&neach); ncard=nplayer*neach;
	REP(i,ncard) scanf("%d",&card[i]);
	REP(i,nplayer) scanf("%d",&fav[i]);
	gain[0]=0; FORE(i,1,neach) scanf("%d",&gain[i]);

	memset(dp,-1,sizeof(dp)); dp[0][0]=0;
	FORE(i,1,nplayer) REPE(j,ncard) {
		if(j!=0) dp[i][j]=dp[i][j-1];
		REPE(k,neach) if(k<=j) {
			int pi=i-1,pj=j-k; if(dp[pi][pj]==-1) continue;
			ll cur=dp[pi][pj]+gain[k];
			if(dp[i][j]==-1||cur>dp[i][j]) dp[i][j]=cur;
		}
	}

	map<int,int> cardcnt; REP(i,ncard) cardcnt[card[i]]++;
	map<int,int> favcnt; REP(i,nplayer) favcnt[fav[i]]++;
	ll ret=0;
	for(auto it=favcnt.begin();it!=favcnt.end();++it) {
		int x=it->first,i=it->second,j=cardcnt[x];
		ret+=dp[i][j];
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}