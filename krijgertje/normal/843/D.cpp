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

const int MAXN=100000;
const int MAXM=100000;
const int MAXQ=2000;
const int MAXLSUM=1000000;

int n,m,nq,lsum;
int ghead[MAXN],gnxt[MAXM],gto[MAXM]; ll gcost[MAXM];

ll pot[MAXN];
set<pair<ll,int> > pq;

void upd2(int at,ll cost) {
	if(cost>=pot[at]) return;
	if(pot[at]!=LLONG_MAX) pq.erase(MP(cost,at));
	pot[at]=cost; pq.insert(MP(cost,at));
}

void init() {
	REP(i,n) pot[i]=LLONG_MAX; upd2(0,0);
	while(!pq.empty()) {
		auto it=pq.begin(); ll cost=it->first; int at=it->second; pq.erase(it);
		if(cost!=pot[at]) continue;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; ll ncost=cost+gcost[x];
			upd2(to,ncost);
		}
	}
	REP(at,n) for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(pot[at]==LLONG_MAX||pot[to]==LLONG_MAX) continue;
		gcost[x]+=pot[at]-pot[to];
	}
}

int qhead[MAXLSUM+1],qtail[MAXLSUM+1],qprv[MAXN],qnxt[MAXN];
int d[MAXN];

void upd(int at,int cost) {
	if(cost>=d[at]) return;
	if(d[at]!=INT_MAX) {
		if(qprv[at]!=-1) qnxt[qprv[at]]=qnxt[at]; else qhead[d[at]]=qnxt[at];
		if(qnxt[at]!=-1) qprv[qnxt[at]]=qprv[at]; else qtail[d[at]]=qprv[at];
	}
	d[at]=cost;
	qprv[at]=qtail[cost],qnxt[at]=-1,qtail[cost]=at; if(qprv[at]!=-1) qnxt[qprv[at]]=at; else qhead[cost]=at;
}
ll solve(int dst) {
	if(pot[dst]==LLONG_MAX) return -1;
	REPE(i,lsum) qhead[i]=qtail[i]=-1; REP(i,n) d[i]=INT_MAX; upd(0,0);
	REPE(cost,lsum) {
		for(int at=qhead[cost];at!=-1;at=qnxt[at]) {
			if(at==dst) return pot[dst]+cost;
			for(int x=ghead[at];x!=-1;x=gnxt[x]) if(cost+gcost[x]<=lsum) {
				int to=gto[x]; int ncost=cost+gcost[x]; upd(to,ncost);
			}
		}
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d%d",&n,&m,&nq); lsum=0;
	REP(i,n) ghead[i]=-1;
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; gnxt[i]=ghead[a],ghead[a]=i,gto[i]=b,gcost[i]=c; }
	init();
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int t; scanf("%d",&t); --t; printf("%lld\n",solve(t));
		}
		if(kind==2) {
			int cnt; scanf("%d",&cnt); REP(i,cnt) { int idx; scanf("%d",&idx); --idx; gcost[idx]++; } lsum+=cnt;
		}
	}
}

int main() {
	run();
	return 0;
}