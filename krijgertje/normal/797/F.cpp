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

const int MAXHOLE=5000;
const int MAXMOUSE=5000;
const int MAXLG=12;

// dp[i+1][j] = min(k>=max(0,j-cnt[i]),dp[i][k]+sum(x=k..j-1,abs(hole[i]-mouse[x])))

// dp[i+1][j] <= +k*hole[i]+(dp[i][k]-mousesum[k])+(mousesum[j]-j*hole[i])															k>=max(0,j-cnt[i]),fst[i]<=k (fst[i] is lowest k such that mouse[k]>=hole[i])
// dp[i+1][j] <= -k*hole[i]+(dp[i][k]+mousesum[k])+fst[i]*hole[i]-mousesum[fst[i]]+mousesum[j]-mousesum[fst[i]]-(j-fst[i])*hole[i]  k>=max(0,j-cnt[i]),k<fst[i]<=j
// dp[i+1][j] <= -k*hole[i]+(dp[i][k]+mousesum[k])+j*hole[i]-mousesum[j]															k>=max(0,j-cnt[i]),j<fst[i]

int nmouse,nhole;
int cnt[MAXHOLE];
int hole[MAXHOLE];
int mouse[MAXMOUSE];
ll mousesum[MAXMOUSE+1];
int fst[MAXHOLE];

ll dp[MAXHOLE+1][MAXMOUSE+1];

ll v[MAXMOUSE+1];
int q[MAXMOUSE+1],qhead,qtail;

ll myadd(ll a,ll b) { return a==LLONG_MAX||b==LLONG_MAX?LLONG_MAX:a+b; }


pair<int,int> o[MAXHOLE];

void run() {
	scanf("%d%d",&nmouse,&nhole);
	REP(i,nmouse) scanf("%d",&mouse[i]);
	REP(i,nhole) scanf("%d%d",&o[i].first,&o[i].second);

	//nmouse=MAXMOUSE; REP(i,nmouse) mouse[i]=rand()%1000;
	//nhole=MAXHOLE; REP(i,nhole) o[i].first=rand()%1000,o[i].second=1;

	sort(mouse,mouse+nmouse);
	sort(o,o+nhole); REP(i,nhole) hole[i]=o[i].first,cnt[i]=o[i].second;
	

	mousesum[0]=0; REP(i,nmouse) mousesum[i+1]=mousesum[i]+mouse[i];
	for(int i=nhole-1;i>=0;--i) { fst[i]=i==nhole-1?nmouse:fst[i+1]; while(fst[i]-1>=0&&mouse[fst[i]-1]>=hole[i]) --fst[i]; }
	//REP(i,nhole) printf("hole%d: %d (cnt=%d) [fst=%d]\n",i,hole[i],cnt[i],fst[i]);
	//REP(i,nmouse) printf("mouse%d: %d\n",i,mouse[i]);

	REPE(j,nmouse) dp[0][j]=j==0?0:LLONG_MAX;
	REP(i,nhole) {
		REPE(j,nmouse) dp[i+1][j]=LLONG_MAX;
		REPE(k,nmouse) v[k]=myadd(dp[i][k],(ll)+k*hole[i]-mousesum[k]); qhead=qtail=0;
		REPE(j,nmouse) {
			while(qtail<qhead&&v[q[qhead-1]]>=v[j]) --qhead; q[qhead++]=j;
			int kmn=max(max(0,j-cnt[i]),fst[i]);
			while(qtail<qhead&&q[qtail]<kmn) ++qtail;
			if(fst[i]<=j&&qtail<qhead) {
				ll cur=myadd(v[q[qtail]],mousesum[j]-(ll)j*hole[i]); 
				//printf("A dp[%d][%d] relaxed with %lld (%d..%d)=%lld/%lld/%d*%d\n",i+1,j,cur,kmn,j,v[q[qtail]],mousesum[j],j,hole[i]);
				if(cur<dp[i+1][j]) dp[i+1][j]=cur;
			}
		}
		REPE(k,nmouse) v[k]=myadd(dp[i][k],(ll)-k*hole[i]+mousesum[k]); qhead=qtail=0;
		REPE(j,nmouse) {
			if(j<fst[i]) { while(qtail<qhead&&v[q[qhead-1]]>=v[j]) --qhead; q[qhead++]=j; }
			int kmn=max(0,j-cnt[i]);
			while(qtail<qhead&&q[qtail]<kmn) ++qtail;
			if(kmn<fst[i]&&fst[i]<=j) {
				ll cur=myadd(v[q[qtail]],(ll)fst[i]*hole[i]-mousesum[fst[i]]+mousesum[j]-mousesum[fst[i]]-(ll)(j-fst[i])*hole[i]);
				//printf("B dp[%d][%d] relaxed with %lld\n",i+1,j,cur);
				if(cur<dp[i+1][j]) dp[i+1][j]=cur;
			}
			if(j<fst[i]) {
				ll cur=myadd(v[q[qtail]],(ll)j*hole[i]-mousesum[j]);
				//printf("C dp[%d][%d] relaxed with %lld\n",i+1,j,cur);
				if(cur<dp[i+1][j]) dp[i+1][j]=cur;
			}
		}
		//puts("");
	}
	ll ret=dp[nhole][nmouse];
	printf("%lld\n",ret==LLONG_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}