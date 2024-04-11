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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXFRIEND=100000;
const int MAXPIZZA=100000;
const int MAXKIND=9;

int nfriend,npizza;
int want[MAXFRIEND];
int have[MAXPIZZA],cost[MAXPIZZA];

int whichpizza[1<<MAXKIND];
int cntfriend[1<<MAXKIND];
pair<int,int> whichpizzas[1<<MAXKIND];

pair<int,int> o[MAXPIZZA];

pair<int,int> solve() {
	memset(whichpizza,-1,sizeof(whichpizza));
	REP(i,npizza) if(whichpizza[have[i]]==-1||cost[i]<cost[whichpizza[have[i]]]) whichpizza[have[i]]=i;

	memset(cntfriend,0,sizeof(cntfriend));
	REP(i,nfriend) ++cntfriend[want[i]];

	memset(whichpizzas,-1,sizeof(whichpizzas));
	REP(i,1<<MAXKIND) if(whichpizza[i]!=-1) FOR(j,i+1,1<<MAXKIND) if(whichpizza[j]!=-1) if(whichpizzas[i|j]==MP(-1,-1)||(ll)cost[whichpizza[i]]+cost[whichpizza[j]]<(ll)cost[whichpizzas[i|j].first]+cost[whichpizzas[i|j].second]) whichpizzas[i|j]=MP(whichpizza[i],whichpizza[j]);

	int best=-1; ll bestcost=0; pair<int,int> ans=MP(-1,-1);
	REP(i,1<<MAXKIND) if(whichpizzas[i]!=MP(-1,-1)) { 
		int cur=0; REP(j,1<<MAXKIND) if((i&j)==j) cur+=cntfriend[j]; ll curcost=(ll)cost[whichpizzas[i].first]+cost[whichpizzas[i].second];
		//printf("%d: cur=%d curcost=%lld (%d,%d)\n",i,cur,curcost,whichpizzas[i].first+1,whichpizzas[i].second+1);
		if(best==-1||cur>best||cur==best&&curcost<bestcost) best=cur,bestcost=curcost,ans=whichpizzas[i];
	}
	REP(i,npizza) o[i]=MP(cost[i],i); sort(o,o+npizza);
	REP(i,1<<MAXKIND) if(whichpizza[i]!=-1) {
		int cur=0; REP(j,1<<MAXKIND) if((i&j)==j) cur+=cntfriend[j]; int other=whichpizza[i]!=o[0].second?o[0].second:o[1].second; ll curcost=(ll)cost[whichpizza[i]]+cost[other];
		//printf("%d: cur=%d curcost=%lld (%d)\n",i,cur,curcost,whichpizza[i]+1);
		if(best==-1||cur>best||cur==best&&curcost<bestcost) best=cur,bestcost=curcost,ans=MP(whichpizza[i],other);
	}
	return ans;
}

void run() {
	scanf("%d%d",&nfriend,&npizza);
	REP(i,nfriend) { want[i]=0; int cnt; scanf("%d",&cnt); REP(j,cnt) { int x; scanf("%d",&x); --x; want[i]|=1<<x; } }
	REP(i,npizza) { have[i]=0; int cnt; scanf("%d%d",&cost[i],&cnt); REP(j,cnt) { int x; scanf("%d",&x); --x; have[i]|=1<<x; } }
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.first+1,ans.second+1);
}

int main() {
	run();
	return 0;
}