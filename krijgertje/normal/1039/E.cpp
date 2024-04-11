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

const int MAXN=100000;
const int MAXQ=100000;
const int MAXLG=16;

int n,sz,nq;
int x[MAXN];
int qsz[MAXQ],qans[MAXQ];

int rmn[MAXN][MAXLG+1],rmx[MAXN][MAXLG+1];
int steponelim;
int stepone[MAXN],steponemn[MAXN],steponemx[MAXN]; // Next position with one step. Up to date iff stepone[i]-i<=stepmanylim. Updated upto stepone[i]-i<=steponelim.
int stepmanylim;
int stepmany[MAXN],stepmanycost[MAXN]; // Next position with many steps. stepmany[i]-i<=stepmanylim, stepone[stepmany[i]]>=min(n,i+stepmanylim+1)

priority_queue<pair<int,int>> pq; // (csz,idx): csz indicates when stepone[idx] should be increased (only when stepone[idx]-idx<=stepmanylim)

vector<int> lst;
int dst[MAXN];

void init() {
	//printf("initing\n");
	steponelim=pow(n,2/3.0);
	stepmanylim=pow(n,1/3.0);
	REP(i,n) rmn[i][0]=rmx[i][0]=x[i]; FORE(k,1,MAXLG) REPE(i,n-(1<<k)) rmn[i][k]=min(rmn[i][k-1],rmn[i+(1<<(k-1))][k-1]),rmx[i][k]=max(rmx[i][k-1],rmx[i+(1<<(k-1))][k-1]);
	REP(i,n) stepone[i]=i+1,steponemn[i]=x[i],steponemx[i]=x[i];
	REP(i,n) stepmany[i]=min(n,i+stepmanylim),stepmanycost[i]=stepmany[i]-i;
	pq=priority_queue<pair<int,int>>(); REP(i,n-1) pq.push(MP(sz-max(steponemx[i],x[stepone[i]])+min(steponemn[i],x[stepone[i]]),i));
	lst.clear(); REP(i,n) dst[i]=-1;
	//printf("inited\n");
}

void update(int idx,int csz) {
	//printf("updating(%d,%d) [%d (%d vs %d) max(%d,%d)-min(%d,%d)]\n",idx,csz,stepone[idx],stepone[idx]-idx,steponelim,steponemx[idx],x[stepone[idx]],steponemn[idx],x[stepone[idx]]);
	while(stepone[idx]<n&&stepone[idx]-idx<=steponelim&&max(steponemx[idx],x[stepone[idx]])-min(steponemn[idx],x[stepone[idx]])<=sz-csz) {
		steponemx[idx]=max(steponemx[idx],x[stepone[idx]]),steponemn[idx]=min(steponemn[idx],x[stepone[idx]]),++stepone[idx];
	}
	if(stepone[idx]<n&&stepone[idx]-idx<=stepmanylim) pq.push(MP(sz-max(steponemx[idx],x[stepone[idx]])+min(steponemn[idx],x[stepone[idx]]),idx));

	lst.clear(); for(int at=idx;at<=idx+stepmanylim;at=at==n?INT_MAX:stepone[at]) lst.PB(at);
	dst[idx]=0; stepmany[idx]=lst.back(); stepmanycost[idx]=SZ(lst)-1;
	for(int at=idx-1;at>=0&&at>=idx-stepmanylim;--at) {
		int to=stepone[at]; if(dst[to]==-1) continue; else dst[at]=dst[to]+1;
		while(lst.back()-at>stepmanylim) lst.pop_back();
		stepmany[at]=lst.back(); stepmanycost[at]=dst[at]+SZ(lst)-1;
	}
	for(int at=idx;at>=0&&at>=idx-stepmanylim;--at) dst[at]=-1;
	//printf("updated(%d,%d)\n",idx,csz);
}

int calc(int csz) {
	//printf("calculating(%d)\n",csz);
	while(!pq.empty()&&pq.top().first>=csz) { int idx=pq.top().second; pq.pop(); update(idx,csz); }
	int at=0,ret=0;
	while(at<n) {
		while(stepone[at]<n&&stepone[at]-at<=steponelim&&max(steponemx[at],x[stepone[at]])-min(steponemn[at],x[stepone[at]])<=sz-csz) {
			steponemx[at]=max(steponemx[at],x[stepone[at]]),steponemn[at]=min(steponemn[at],x[stepone[at]]),++stepone[at];
		}
		if(stepmany[at]!=at) {
			ret+=stepmanycost[at];
			at=stepmany[at];
		} else if(stepone[at]-at<=steponelim) {
			++ret;
			at=stepone[at];
		} else {
			int cmn=x[at],cmx=x[at],cto=at+1;
			for(int k=MAXLG;k>=0;--k) if(cto+(1<<k)<=n&&max(cmx,rmx[cto][k])-min(cmn,rmn[cto][k])<=sz-csz) cmx=max(cmx,rmx[cto][k]),cmn=min(cmn,rmn[cto][k]),cto+=1<<k;
			++ret;
			at=cto;
		}
	}
	//printf("calculated(%d) -> %d\n",csz,ret);
	return ret;
}

pair<int,int> o[MAXQ];

void solve() {
	init();
	REP(i,nq) o[i]=MP(-qsz[i],i); sort(o,o+nq);
	REP(i,nq) { int csz=-o[i].first,id=o[i].second; qans[id]=calc(csz)-1; }
}

void run() {
	scanf("%d%d%d",&n,&sz,&nq);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,nq) scanf("%d",&qsz[i]);
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}