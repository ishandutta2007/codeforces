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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=10000;
const int MAXQ=10000;
const int MAXS=4*MAXN;
const int MAXDEP=20;
struct Q { int l,r,val; };

int n,nq;
Q q[MAXQ];



bitset<MAXN+1> can[MAXDEP];
vector<int> qlst[MAXDEP];

bitset<MAXN+1> ans;
int ret[MAXN],nret;

void rec(int l,int r,int dep) {
	//printf("rec(%d,%d):",l,r); REPE(i,n) if(can[dep][i]) printf(" %d",i); printf(" -"); REPSZ(i,qlst[dep]) printf(" %d",qlst[dep][i]); puts("");
	if(l==r) { ans|=can[dep]; return; }
	int m=l+(r-l)/2;
	{
		can[dep+1]=can[dep]; qlst[dep+1].clear();
		REPSZ(i,qlst[dep]) { int idx=qlst[dep][i]; if(m<q[idx].l) continue; if(q[idx].l<=l&&m<=q[idx].r) can[dep+1]|=can[dep+1]<<q[idx].val; else qlst[dep+1].PB(idx); }
		rec(l,m,dep+1);
	}
	{
		can[dep+1]=can[dep]; qlst[dep+1].clear();
		REPSZ(i,qlst[dep]) { int idx=qlst[dep][i]; if(q[idx].r<m+1) continue; if(q[idx].l<=m+1&&r<=q[idx].r) can[dep+1]|=can[dep+1]<<q[idx].val; else qlst[dep+1].PB(idx); }
		rec(m+1,r,dep+1);
	}
}

void solve() {
	can[0]=ans=bitset<MAXN+1>(0);
	can[0][0]=1;
	qlst[0].clear();
	REP(i,nq) { int idx=i; if(q[idx].l<=0&&n-1<=q[idx].r) can[0]|=can[0]<<q[idx].val; else qlst[0].PB(idx); }
	
	rec(0,n-1,0);
	nret=0; FORE(i,1,n) if(ans[i]==1) ret[nret++]=i;
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,nq) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].val),--q[i].l,--q[i].r;
	solve();
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

bool bfcan[MAXN+1];
int cur[MAXN];
int bfans[MAXN],nbfans;

void bfsolve() {
	memset(bfcan,0,sizeof(bfcan));
	REP(i,1<<nq) {
		REP(j,n) cur[j]=0;
		REP(k,nq) if(i&(1<<k)) FORE(j,q[k].l,q[k].r) cur[j]+=q[k].val;
		int mx=-1; REP(j,n) mx=max(mx,cur[j]); if(mx<=n) bfcan[mx]=true;
	}
	nbfans=0; FORE(i,1,n) if(bfcan[i]) bfans[nbfans++]=i;
}

void stress() {
	REP(rep,1000) {
		n=10,nq=10; REP(i,nq) { int l=rand()%n,r=rand()%n; if(l>r) swap(l,r); q[i].l=l,q[i].r=r,q[i].val=rand()%n+1; }
		solve();
		bfsolve();
		bool same=nret==nbfans; REP(i,min(nret,nbfans)) if(ret[i]!=bfans[i]) same=false;
		if(same) { printf("."); continue; }
		printf("diff\n");
		printf("%d %d\n",n,nq); REP(i,nq) printf("%d %d %d\n",q[i].l+1,q[i].r+1,q[i].val);
		printf("have:"); REP(i,nret) printf(" %d",ret[i]); puts("");
		printf("want:"); REP(i,nbfans) printf(" %d",bfans[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}