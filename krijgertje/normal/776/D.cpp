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

const int MAXROOM=100000;
const int MAXSWITCH=100000;

int nroom,nswitch;
int init[MAXROOM];

int by[MAXROOM][2],nby[MAXROOM];
int shead[MAXSWITCH],snxt[2*MAXROOM],sroom[2*MAXROOM],ns;
int nrem[MAXROOM];
int switchval[MAXSWITCH];
int qroom[MAXROOM],qroomhead,qroomtail;

bool checkroom(int r) {
	//printf("checking room %d\n",r+1);
	int cur=init[r]; REP(i,nby[r]) { int s=by[r][i],v=switchval[s]; assert(v!=-1); if(v) cur=1-cur; } return cur==1;
}

bool setswitch(int s,int to) {
	//printf("setting %d to %d\n",s+1,to);
	assert(switchval[s]==-1);
	switchval[s]=to;
	for(int x=shead[s];x!=-1;x=snxt[x]) {
		int room=sroom[x];
		assert(nrem[room]>0); --nrem[room];
		if(nrem[room]==1) {
			//printf("queing room %d\n",room+1);
			qroom[qroomhead++]=room;
		}
		if(nrem[room]==0&&!checkroom(room)) return false;
	}
	return true;
}

bool solve() {
	REP(i,nswitch) switchval[i]=-1;
	REP(i,nroom) nrem[i]=nby[i];
	qroomhead=qroomtail=0; 
	REP(i,nroom) if(nrem[i]==0&&init[i]==0) return false;
	REP(i,nroom) if(nrem[i]==1) qroom[qroomhead++]=i;
	int atchoice=0;
	while(true) {
		while(qroomhead==qroomtail&&atchoice<nroom) {
			if(nrem[atchoice]==2) {
				//printf("choice for room %d\n",atchoice+1);
				if(!setswitch(by[atchoice][0],0)) return false;
			}
			++atchoice;
		}
		if(qroomhead==qroomtail) break;
		int atroom=qroom[qroomtail++];
		if(nrem[atroom]!=1) continue;
		int atswitch=-1; int cur=init[atroom]; REP(i,nby[atroom]) { int s=by[atroom][i],v=switchval[s]; if(v==-1) assert(atswitch==-1),atswitch=s; else if(v) cur=1-cur; } assert(atswitch!=-1);
		//printf("procesing room %d -> switch %d (cur=%d)\n",atroom+1,atswitch+1,cur);
		if(!setswitch(atswitch,cur==0?1:0)) return false;
	}
	return true;
}

void run() {
	scanf("%d%d",&nroom,&nswitch);
	REP(i,nroom) scanf("%d",&init[i]);
	REP(i,nroom) nby[i]=0;
	REP(i,nswitch) shead[i]=-1; ns=0;
	REP(i,nswitch) { int cnt; scanf("%d",&cnt); REP(j,cnt) { int room; scanf("%d",&room); --room; by[room][nby[room]++]=i; snxt[ns]=shead[i]; sroom[ns]=room; shead[i]=ns++; } }
	//REP(i,nswitch) { printf("%d:",i+1); for(int x=shead[i];x!=-1;x=snxt[x]) printf(" %d",sroom[x]+1); puts(""); }
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}