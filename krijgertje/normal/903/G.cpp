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

const int MAXN=200000;
const int MAXQ=200000;
const int MAXS=4*MAXN;

int n,m,nq;
int lcap[MAXN-1],rcap[MAXN-1];
vector<pair<int,int> > adj[MAXN];

int smn[MAXS],slazy[MAXS];
void sapply(int x,int by) { smn[x]+=by; slazy[x]+=by; }
void spull(int x) { smn[x]=min(smn[2*x+1],smn[2*x+2]); }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		smn[x]=rcap[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return smn[x];
	} else {
		int m=l+(r-l)/2;
		spush(x);
		int ret=INT_MAX;
		if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
		return ret;
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2;
		spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}

int lval[MAXN];
ll lvalsum[MAXN+1];
priority_queue<pair<ll,int> > pq;
bool valid[MAXN+MAXQ];
int cidx[MAXN];

void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,n-1) scanf("%d%d",&lcap[i],&rcap[i]);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); }

	sinit(0,0,n-2);
	REP(at,n) lval[at]=0;
	REP(at,n) REPSZ(i,adj[at]) {
		int to=adj[at][i].first,cap=adj[at][i].second;
		if(to!=n-1) cap=min(cap,sget(0,0,n-2,to,n-2));
		lval[at]+=cap; if(to!=n-1) smod(0,0,n-2,to,n-2,-cap);
	}
	//printf("lval:"); REP(at,n) printf(" %d",lval[at]); puts("");

	lvalsum[0]=0; REP(i,n) lvalsum[i+1]=lvalsum[i]+lval[i];
	pq=priority_queue<pair<ll,int> >(); REP(i,n) pq.push(MP(-(lvalsum[i+1]+(i==n-1?0:lcap[i])),i)),valid[i]=true,cidx[i]=i;
	REPE(i,nq) {
		while(!pq.empty()&&!valid[pq.top().second]) pq.pop();
		printf("%lld\n",pq.empty()?-1:-pq.top().first);
		if(i==nq) break;
		int idx,val; scanf("%d%d",&idx,&val); --idx; valid[cidx[idx]]=false; cidx[idx]=n+i; valid[n+i]=true; pq.push(MP(-(lvalsum[idx+1]+val),n+i));
	}
}

int main() {
	run();
	return 0;
}