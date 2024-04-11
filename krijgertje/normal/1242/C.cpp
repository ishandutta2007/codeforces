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

const int MAXBOX=15;
const int MAXCNT=5000;
const int MAXID=MAXBOX*MAXCNT;

int nbox;
int boxcnt[MAXBOX];
int boxval[MAXBOX][MAXCNT];
int anspick[MAXBOX],ansput[MAXBOX];

int nid;
int id[MAXBOX][MAXCNT];
pair<int,int> pos[MAXID];

map<ll,int> mp;
int replacewith[MAXID];
int state[MAXID];

vector<int> how[1<<MAXBOX];

int act[1<<MAXBOX];

bool solve() {
	nid=0;
	REP(i,nbox) REP(j,boxcnt[i]) { int cur=nid++; id[i][j]=cur; pos[cur]=MP(i,j); }

	mp.clear();
	REP(i,nbox) REP(j,boxcnt[i]) mp[boxval[i][j]]=id[i][j];

	ll sum=0; REP(i,nbox) REP(j,boxcnt[i]) sum+=boxval[i][j];
	if(sum%nbox!=0) return false;
	ll each=sum/nbox;
	REP(i,nbox) {
		ll mysum=0; REP(j,boxcnt[i]) mysum+=boxval[i][j];
		REP(j,boxcnt[i]) { ll need=each-mysum+boxval[i][j]; replacewith[id[i][j]]=mp.count(need)?mp[need]:-1; }
	}
	//printf("replacewith:"); REP(i,nid) printf(" %d",replacewith[i]); puts("");

	REP(i,nid) state[i]=0;
	REP(i,nid) if(state[i]==0) {
		int at=i; while(at!=-1&&state[at]==0) { state[at]=1; at=replacewith[at]; }
		while(at!=-1&&state[at]==1) { state[at]=2; at=replacewith[at]; }
		at=i; while(at!=-1&&state[at]==1) { state[at]=3; at=replacewith[at]; }
	}
	REP(mask,1<<nbox) how[mask].clear();
	REP(i,nid) if(state[i]==2) {
		bool ok=true; int mask=0; vector<int> seen;
		int at=i; while(at!=-1&&state[at]==2) { state[at]=3; seen.PB(at); int cur=pos[at].first; if(mask&(1<<cur)) ok=false; else mask|=1<<cur; at=replacewith[at]; } assert(at!=-1);
		if(ok&&SZ(how[mask])==0) how[mask]=seen;
	}
	//REP(mask,1<<nbox) if(SZ(how[mask])!=0) { printf("%x:",mask); REPSZ(i,how[mask]) printf(" (%d,%d)",pos[how[mask][i]].first,pos[how[mask][i]].second); puts(""); }

	REP(mask,1<<nbox) act[mask]=SZ(how[mask])==0?-1:mask;
	REP(mask,1<<nbox) if(act[mask]==-1) {
		int other=(1<<nbox)-1-mask;
		for(int submask=(other+1)&mask;submask<mask;submask=(submask+other+1)&mask) {
			//printf("%d -> sub = %d\n",mask,submask);
			if(SZ(how[submask])!=0&&act[mask^submask]!=-1) { act[mask]=submask; break; }
		}
	}
	if(act[(1<<nbox)-1]==-1) return false;

	REP(i,nbox) anspick[i]=ansput[i]=-1;
	{
		int mask=(1<<nbox)-1;
		while(mask!=0) {
			int submask=act[mask]; assert(submask!=-1);
			REPSZ(i,how[submask]) {
				int id=how[submask][i];
				anspick[pos[id].first]=boxval[pos[id].first][pos[id].second];
				int j=(i+SZ(how[submask])-1)%SZ(how[submask]);
				int jd=how[submask][j];
				ansput[pos[id].first]=pos[jd].first;
			}
			mask^=submask;
		}
	}
	return true;
}

void run() {
	scanf("%d",&nbox);
	REP(i,nbox) { scanf("%d",&boxcnt[i]); REP(j,boxcnt[i]) scanf("%d",&boxval[i][j]); }
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,nbox) printf("%d %d\n",anspick[i],ansput[i]+1);
}

int main() {
	run();
	return 0;
}