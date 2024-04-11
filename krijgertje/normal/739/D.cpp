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

const int MAXN=300;

int n;
char buff[10];
int pre[MAXN],cyc[MAXN];

vector<int> adj[MAXN];
int lmatch[MAXN],rmatch[MAXN]; bool done[MAXN];
bool augment(int at) {
	if(done[at]) return false; else done[at]=true;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(rmatch[to]==-1||augment(rmatch[to])) {
			rmatch[to]=at,lmatch[at]=to; return true;
		}
	}
	return false;
}
int maxflow(int nl,int nr) {
	int ret=0;
	REP(i,nl) lmatch[i]=-1; REP(i,nr) rmatch[i]=-1;
	REP(i,nl) {
		memset(done,false,sizeof(done));
		if(augment(i)) ++ret;
	}
	return ret;
}
bool ok(pair<int,int> want,pair<int,int> have) {
	if(have.first!=-1&&have.first!=want.first) return false;
	if(have.second!=-1&&have.second!=want.second) return false;
	return true;
}


void run() {
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",buff); if(strcmp(buff,"?")==0) pre[i]=-1; else sscanf(buff,"%d",&pre[i]);
		scanf("%s",buff); if(strcmp(buff,"?")==0) cyc[i]=-1; else sscanf(buff,"%d",&cyc[i]);
	}

	int idx=-1; REP(i,n) if(cyc[i]==-1&&pre[i]!=-1&&pre[i]!=0&&(idx==-1||pre[i]>pre[idx])) idx=i;

	FORE(idxcyc,0,n) {
		if((idx==-1)!=(idxcyc==0)) continue;
		map<pair<int,int>,int> need;
		if(idxcyc!=0) need[MP(0,idxcyc)]=idxcyc;
		REP(i,n) {
			if(cyc[i]!=-1) need[MP(0,cyc[i])]=cyc[i];
			if(pre[i]==-1||pre[i]==0||cyc[i]==-1&&i!=idx) continue;
			int curcyc=i==idx?idxcyc:cyc[i],curpre=pre[i];
			while(!need.count(MP(curpre,curcyc))) need[MP(curpre,curcyc)]=1,--curpre;
		}
		vector<pair<int,int> > have; vector<int> haveidx;
		map<pair<int,int>,vector<int> > res;
		REP(i,n) {
			int curcyc=i==idx?idxcyc:cyc[i],curpre=pre[i];
			if(curpre==-1) {
				have.PB(MP(curpre,curcyc)),haveidx.PB(i);
			} else if(curpre==0) {
				if(curcyc!=-1) {
					res[MP(curpre,curcyc)].PB(i);
					need[MP(0,curcyc)]=(need[MP(0,curcyc)]-1+curcyc)%curcyc;
				} else {
					have.PB(MP(curpre,curcyc)),haveidx.PB(i);
				}
			} else {
				if(curcyc!=-1) {
					res[MP(curpre,curcyc)].PB(i);
					need[MP(curpre,curcyc)]=0;
				} else {
					have.PB(MP(curpre,curcyc)),haveidx.PB(i);
				}
			}
		}
		vector<pair<int,int> > want;
		for(map<pair<int,int>,int>::iterator i=need.begin();i!=need.end();++i) REP(j,i->second) want.PB(i->first);
		if(SZ(want)>SZ(have)) continue;
		//printf("want:"); REPSZ(i,want) printf(" (%d,%d)",want[i].first,want[i].second); puts("");
		//printf("have:"); REPSZ(i,have) printf(" (%d,%d)",have[i].first,have[i].second); puts("");
		REPSZ(i,want) adj[i].clear();
		REPSZ(i,want) REPSZ(j,have) if(ok(want[i],have[j])) adj[i].PB(j);
		if(maxflow(SZ(want),SZ(have))!=SZ(want)) continue;
		//printf("solution\n");
		REPSZ(i,have) {
			if(rmatch[i]!=-1) { res[want[rmatch[i]]].PB(haveidx[i]); continue; }
			int curcyc=have[i].second,curpre=have[i].first;
			if((curpre==-1||curpre==0)&&curcyc==-1) res[MP(0,1)].PB(haveidx[i]);
			else if(curpre==-1) res[MP(1,curcyc)].PB(haveidx[i]);
			else if(curcyc==-1&&idxcyc!=0) res[MP(curpre,idxcyc)].PB(haveidx[i]);
			else assert(false);
		}
		vector<int> ret(n,-1);
		for(map<pair<int,int>,vector<int> >::iterator i=res.begin();i!=res.end();++i) {
			int curcyc=i->first.second,curpre=i->first.first; vector<int> idxs=i->second;
			if(curpre==0) {
				assert(SZ(idxs)%curcyc==0);
				REPSZ(i,idxs) ret[idxs[i]]=idxs[i-i%curcyc+(i+1)%curcyc];
			} else {
				assert(res.count(MP(curpre-1,curcyc)));
				REPSZ(i,idxs) ret[idxs[i]]=res[MP(curpre-1,curcyc)][0];
			}
		}
		REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts(""); return;
	}
	printf("-1\n");
}


int main() {
	run();
	return 0;
}