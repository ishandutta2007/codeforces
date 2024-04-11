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

const int MAXN=300000;
const int MAXNEED=1000000000;
typedef struct S { int l,r,cnt,id; } S;
typedef struct Z { int pref,l,cnt; } Z;

int n,budget;
int lx[MAXN],rx[MAXN],scost[MAXN];

int last[2*MAXN];
pair<int,int> e[2*MAXN]; int ne;

pair<int,int> p[MAXN]; int np;
S s[2*MAXN+1]; int ns;
set<int> active;

int have[2*MAXN];
int bestother[MAXN];

map<int,int> one; int best;
Z a[2*MAXN+1]; int na;
Z b[2*MAXN+1]; int nb;

int getone(int rem) {
	auto it=one.lower_bound(rem); if(it==one.end()||it->first>rem) --it;
	//printf("getone(%d)=%d\n",rem,it->second);
	return it->second;
}
void updone(int key,int val) {
	//printf("updone(%d,%d)\n",key,val);
	auto it=one.lower_bound(key); if(it==one.end()||it->first>key) --it; if(it->second>=val) return;
	while(true) { auto nx=it; ++nx; if(nx==one.end()||nx->second>val) break; one.erase(nx); } one[key]=val;
}

int solve(Z *c,int nc,int q) {
	int l=-1,r=nc-1;
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(c[m].pref+c[m].cnt>=q) r=m; else l=m;
	}
	return c[r].l+q-c[r].pref;	
}


void run() {
	scanf("%d%d",&n,&budget); REP(i,n) scanf("%d%d%d",&lx[i],&rx[i],&scost[i]);

	ne=0; REP(i,n) e[ne++]=MP(lx[i],2*i+0),e[ne++]=MP(rx[i],2*i+1);
	sort(e,e+ne);

	ns=0; np=0; active.clear(); REP(i,n) last[i]=-1;
	for(int at=0,to=at;at<ne;at=to) {
		while(to<ne&&e[at].first==e[to].first) ++to;
		s[ns].l=(ns==0?0:s[ns-1].r),s[ns].r=e[at].first,s[ns].cnt=SZ(active),s[ns].id=-1;
		if(SZ(active)==1) { s[ns].id=*active.begin(); last[s[ns].id]=ns; }
		if(SZ(active)==2) { int u=*active.begin(),v=*next(active.begin()); if(u>v) swap(u,v); if(np==0||MP(u,v)!=p[np-1]) p[np]=MP(u,v),++np; s[ns].id=n+np-1; last[s[ns].id]=ns; }
		++ns;
		FOR(i,at,to) if(e[i].second%2==0) active.insert(e[i].second/2); else active.erase(e[i].second/2);
	}
	s[ns].l=(ns==0?0:s[ns-1].r),s[ns].r=s[ns].l+MAXNEED,s[ns].cnt=0,s[ns].id=-1,++ns;
	//REP(i,np) printf("%d = %d+%d\n",n+i,p[i].first,p[i].second);
	//REP(i,ns) printf("%d..%d: %d -> %d\n",s[i].l,s[i].r,s[i].cnt,s[i].id); puts("");
	//REP(i,n+np) printf("%d: last=%d\n",i,last[i]);

	REP(i,n+np) have[i]=0; na=0; one.clear(); one[0]=0; best=0;
	REP(i,ns) {
		if(s[i].cnt==0) { a[na].pref=(na==0?0:a[na-1].pref+a[na-1].cnt),a[na].l=s[i].l,a[na].cnt=s[i].r-s[i].l,++na; }
		if(s[i].cnt==1&&scost[s[i].id]<=budget) {
			int cur=have[s[i].id]+getone(budget-scost[s[i].id]),len=s[i].r-s[i].l,need=best-cur;
			//printf("l=%d cur=%d len=%d need=%d best=%d\n",s[i].l,cur,len,need,best);
			if(len>need) { a[na].pref=(na==0?0:a[na-1].pref+a[na-1].cnt),a[na].l=s[i].l+need,a[na].cnt=len-need,++na; best+=len-need; }
			have[s[i].id]+=len;
			if(i==last[s[i].id]) updone(scost[s[i].id],have[s[i].id]);
		}
	}
	//REP(i,na) printf("a%d: %d before, %d here\n",a[i].l,a[i].pref,a[i].cnt); puts("");

	REP(i,n+np) have[i]=0; REP(i,n) bestother[i]=0; nb=0; best=0;
	REP(i,ns) {
		if(s[i].cnt==0) { b[nb].pref=(nb==0?0:b[nb-1].pref+b[nb-1].cnt),b[nb].l=s[i].l,b[nb].cnt=s[i].r-s[i].l,++nb; }
		if(s[i].cnt==1&&scost[s[i].id]<=budget) {
			int cur=have[s[i].id]+bestother[s[i].id],len=s[i].r-s[i].l,need=best-cur;
			if(len>need) { b[nb].pref=(nb==0?0:b[nb-1].pref+b[nb-1].cnt),b[nb].l=s[i].l+need,b[nb].cnt=len-need,++nb; best+=len-need; }
			have[s[i].id]+=len;
		}
		if(s[i].cnt==2&&scost[p[s[i].id-n].first]+scost[p[s[i].id-n].second]<=budget) {
			int u=p[s[i].id-n].first,v=p[s[i].id-n].second,cur=have[u]+have[v]+have[s[i].id],len=s[i].r-s[i].l,need=best-cur;
			if(len>need) { b[nb].pref=(nb==0?0:b[nb-1].pref+b[nb-1].cnt),b[nb].l=s[i].l+need,b[nb].cnt=len-need,++nb; best+=len-need; }
			have[s[i].id]+=len;
			if(have[v]+have[s[i].id]>bestother[u]) bestother[u]=have[v]+have[s[i].id];
			if(have[u]+have[s[i].id]>bestother[v]) bestother[v]=have[u]+have[s[i].id];
		}
	}
	//REP(i,nb) printf("b%d: %d before, %d here\n",b[i].l,b[i].pref,b[i].cnt); puts("");

	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int q; scanf("%d",&q);
		int ares=solve(a,na,q);
		int bres=solve(b,nb,q);
		int res=min(ares,bres);
		printf("%d\n",res);
	}
}

int main() {
	run();
	return 0;
}