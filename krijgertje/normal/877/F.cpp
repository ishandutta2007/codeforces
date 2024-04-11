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
const int MAXQ=100000;
const int BSZ=400;
typedef struct Q { int l,r,bl,id; } Q;
bool operator<(const Q &a,const Q &b) { if(a.bl!=b.bl) return a.bl<b.bl; if(a.r!=b.r) return a.bl%2==0?a.r<b.r:a.r>b.r; return a.id<b.id; }

int n,need;
int kind[MAXN],val[MAXN];

ll sum[MAXN+1];
int id[MAXN+1];

ll all[MAXN+1]; int nall;
int prv[MAXN+1],nxt[MAXN+1];

int nq;
Q q[MAXQ];
ll ans[MAXQ];

ll cntpair;
int cnt[MAXN+1];
void init() { cntpair=0; REP(i,nall) cnt[i]=0; }
void pushfront(int x) {
	//printf("pushfront(%d)\n",x);
	if(nxt[x]!=-1) cntpair+=cnt[nxt[x]]; ++cnt[x]; 
}
void pushback(int x) { 
	//printf("pushback(%d)\n",x);
	if(prv[x]!=-1) cntpair+=cnt[prv[x]]; ++cnt[x]; 
}
void popfront(int x) { 
	//printf("popfront(%d)\n",x);
	--cnt[x]; if(nxt[x]!=-1) cntpair-=cnt[nxt[x]]; 
}
void popback(int x) { 
	//printf("popback(%d)\n",x);
	--cnt[x]; if(prv[x]!=-1) cntpair-=cnt[prv[x]]; 
}

void run() {
	scanf("%d%d",&n,&need); REP(i,n) scanf("%d",&kind[i]); REP(i,n) scanf("%d",&val[i]);
	scanf("%d",&nq); REP(i,nq) { scanf("%d%d",&q[i].l,&q[i].r); --q[i].l; q[i].bl=q[i].l/BSZ,q[i].id=i; } sort(q,q+nq);

	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+(kind[i]==1?+val[i]:-val[i]);
	nall=0; REPE(i,n) all[nall++]=sum[i]; sort(all,all+nall); nall=unique(all,all+nall)-all; REPE(i,n) id[i]=lower_bound(all,all+nall,sum[i])-all;
	REP(i,nall) prv[i]=nxt[i]=-1; REP(i,nall) { int pos=lower_bound(all,all+nall,all[i]-need)-all; if(pos!=nall&&all[pos]==all[i]-need) prv[i]=pos,nxt[pos]=i; }

	//printf("sum:"); REPE(i,n) printf(" %lld",sum[i]); puts("");
	//printf("id:"); REPE(i,n) printf(" %d",id[i]); puts("");
	//printf("all:"); REP(i,nall) printf(" %lld",all[i]); puts("");
	//printf("prv:"); REP(i,nall) printf(" %d",prv[i]); puts("");
	//printf("nxt:"); REP(i,nall) printf(" %d",nxt[i]); puts("");

	int l=0,r=0; init(); pushback(id[0]);
	REP(i,nq) {
		while(l>q[i].l) pushfront(id[--l]);
		while(r<q[i].r) pushback(id[++r]);
		while(l<q[i].l) popfront(id[l++]);
		while(r>q[i].r) popback(id[r--]);
		//printf("answering [%d..%d] = %lld\n",q[i].l,q[i].r,cntpair);
		ans[q[i].id]=cntpair;
	}
	REP(i,nq) printf("%lld\n",ans[i]);
	
}

int main() {
	run();
	return 0;
}