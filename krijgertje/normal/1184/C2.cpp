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

const int MAXN=300000;

int n,rxy;
int px[MAXN],py[MAXN];

int ruv;
int pu[MAXN],pv[MAXN];

int vv[2*MAXN],nvv;
int pl[MAXN],pr[MAXN];

pair<int,int> e[2*MAXN]; int ne;
bool alive[MAXN];

int sval[8*MAXN],slazy[8*MAXN];
void sapply(int x,int by) { sval[x]+=by; slazy[x]+=by; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { assert(slazy[x]==0); sval[x]=max(sval[2*x+1],sval[2*x+2]); }
void sinit(int x,int l,int r) {
	sval[x]=slazy[x]=0;
	if(l!=r) { int m=l+(r-l)/2; sinit(2*x+1,l,m); sinit(2*x+2,m+1,r); }
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}

int solve() {
	ruv=2*rxy;
	REP(i,n) pu[i]=px[i]+py[i],pv[i]=px[i]-py[i];
	nvv=0; REP(i,n) vv[nvv++]=pv[i]-ruv,vv[nvv++]=pv[i];
	sort(vv,vv+nvv); nvv=unique(vv,vv+nvv)-vv;
	REP(i,n) pl[i]=lower_bound(vv,vv+nvv,pv[i]-ruv)-vv,pr[i]=lower_bound(vv,vv+nvv,pv[i])-vv;
	//REP(i,n) printf("x=%d y=%d u=%d v=%d l=%d r=%d\n",px[i],py[i],pu[i],pv[i],pl[i],pr[i]);

	ne=0; REP(i,n) alive[i]=false,e[ne++]=MP(pu[i]-ruv,i),e[ne++]=MP(pu[i]+1,i);
	sort(e,e+ne);
	sinit(0,0,nvv-1);
	int ret=0;
	for(int l=0,r=l;l<ne;l=r) {
		while(r<ne&&e[r].first==e[l].first) ++r;
		FOR(i,l,r) {
			int idx=e[i].second;
			//printf("setting %d to %s\n",idx,!alive[idx]?"on":"off");
			smod(0,0,nvv-1,pl[idx],pr[idx],!alive[idx]?+1:-1);
			alive[idx]=!alive[idx];
		}
		//printf("checking\n");
		ret=max(ret,sval[0]);
	}

	return ret;
}

void run() {
	scanf("%d%d",&n,&rxy);
	REP(i,n) scanf("%d%d",&px[i],&py[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}