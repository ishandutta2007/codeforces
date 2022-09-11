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

// Only for integer values of x
struct MergableHullNode {
	ll a,b; // a-b*x
	int prv,nxt;
	MergableHullNode() {}
	MergableHullNode(ll a,ll b):a(a),b(b),prv(-1),nxt(-1) {}
	ll eval(ll x) { if(a==LLONG_MAX) return a; return a-b*x; }
};
struct MergableHull {
	static vector<MergableHullNode> nodes;
	static vector<int> pool;
	static int makenode(ll a,ll b) { if(SZ(pool)>0) { int ret=pool.back(); pool.pop_back(); nodes[ret]=MergableHullNode(a,b); return ret; } else { int ret=SZ(nodes); nodes.PB(MergableHullNode(a,b)); return ret; } }
	static void releasenode(int a) { pool.PB(a); } 
	int head,tail; ll maxquery;
	MergableHull():head(-1),tail(-1),maxquery(LLONG_MIN) {}
	void init(ll a,ll b) { head=tail=makenode(a,b); }
	void popback() { int a=tail; assert(a!=-1); if(nodes[a].prv==-1) { assert(head==a); head=-1; } else nodes[nodes[a].prv].nxt=-1; tail=nodes[a].prv; releasenode(a); }
	void popfront() { int a=head; assert(a!=-1); if(nodes[a].nxt==-1) { assert(tail==a); tail=-1; } else nodes[nodes[a].nxt].prv=-1; head=nodes[a].nxt; releasenode(a); }
	ll query(ll x) { assert(x>=maxquery); maxquery=x; assert(head!=-1); while(nodes[head].nxt!=-1&&nodes[nodes[head].nxt].eval(x)<=nodes[head].eval(x)) popfront(); return nodes[head].eval(x); }
	void releaseall() { for(int x=head;x!=-1;x=nodes[x].nxt) releasenode(x); }
};
vector<MergableHullNode> MergableHull::nodes;
vector<int> MergableHull::pool;
ll divup(ll num,ll den) { if(den<0) num=-num,den=-den; if(num>=0) return (num+den-1)/den; else return num/den; }
ll overtake(int pidx,int qidx) {
	MergableHullNode p=MergableHull::nodes[pidx],q=MergableHull::nodes[qidx]; assert(p.b>q.b);
	if(p.a==LLONG_MAX) { assert(q.a!=LLONG_MAX); return LLONG_MIN; }
	if(q.a==LLONG_MAX) { assert(p.a!=LLONG_MAX); return LLONG_MAX; }
	return divup(p.a-q.a,p.b-q.b);
}
MergableHull merge(MergableHull a,MergableHull b) {
	assert(a.head!=-1&&a.tail!=-1&&b.head!=-1&&b.tail!=-1);
	while(true) {
		bool change=false;
		if(MergableHull::nodes[a.tail].prv!=-1&&overtake(b.head,a.tail)<=overtake(a.tail,MergableHull::nodes[a.tail].prv)) { change=true; a.popback(); }
		if(MergableHull::nodes[b.head].nxt!=-1&&overtake(MergableHull::nodes[b.head].nxt,b.head)<=overtake(b.head,a.tail)) { change=true; b.popfront(); }
		if(!change) break;
	}
	MergableHull::nodes[a.tail].nxt=b.head; MergableHull::nodes[b.head].prv=a.tail;
	MergableHull ret; ret.head=a.head,ret.tail=b.tail,ret.maxquery=max(a.maxquery,b.maxquery); return ret;
}

const int MAXN=20000;
const int MAXK=100;
struct Opt { int lj,hj,mx,li,hi; vector<ll> vals; Opt() {} Opt(int lj,int hj,int mx,int li,int hi):lj(lj),hj(hj),mx(mx),li(li),hi(hi) {} };

int n,K;
int a[MAXN];

int stck[MAXN],nstck;
vector<Opt> opt;
vector<int> who[MAXN+1];

ll dp[MAXN+1][MAXK+1];

vector<pair<int,MergableHull>> hull1[MAXK+1];

void printhull(MergableHull h) { for(int x=h.head;x!=-1;x=MergableHull::nodes[x].nxt) { if(x!=h.head) printf(" "); printf("(%lld%c%lld*x[%d,%d])",MergableHull::nodes[x].a,MergableHull::nodes[x].b<=0?'+':'-',abs(MergableHull::nodes[x].b),MergableHull::nodes[x].prv,MergableHull::nodes[x].nxt); } }

void process(int i) {
	//printf("process(%d):",i); FORE(k,1,K) printf(" %lld",dp[i][k]); puts("");
	REPE(k,K) {
		if(k!=0) {
			MergableHull cur; cur.init(dp[i][k],i);
			//printf("hull1[%d]: ",k); REPSZ(j,hull1[k]) { printf(" %d:[",hull1[k][j].first); for(int x=hull1[k][j].second.head;x!=-1;x=MergableHull::nodes[x].nxt) printf(" (%lld-%lld*x)",MergableHull::nodes[x].a,MergableHull::nodes[x].b); printf("]"); } puts("");
			while(SZ(hull1[k])>0&&a[hull1[k][SZ(hull1[k])-1].first]<=a[i]) {
				MergableHull oth=hull1[k][SZ(hull1[k])-1].second; hull1[k].pop_back();
				cur=merge(oth,cur);
			}
			hull1[k].PB(MP(i,cur));
		}
		REPSZ(_,who[i]) {
			int idx=who[i][_]; if(k==0) { opt[idx].vals[k]=opt[idx].lj==0?0:LLONG_MAX; continue; }
			int l=SZ(hull1[k])==1?0:hull1[k][SZ(hull1[k])-2].first+1,h=hull1[k][SZ(hull1[k])-1].first; assert(opt[idx].lj==l&&opt[idx].hj==h);
			opt[idx].vals[k]=hull1[k][SZ(hull1[k])-1].second.query(opt[idx].mx);
		}
	}
	//REPSZ(_,who[i]) { int idx=who[i][_]; printf("opt[%d]:",idx); REPE(k,K) printf(" %lld",opt[idx].vals[k]); puts(""); }
}

void rec(int li,int hi,vector<int> optidx) {
	vector<int> myidx,noptidx;
	REPSZ(i,optidx) {
		int idx=optidx[i];
		if(opt[idx].li<=li&&hi<=opt[idx].hi) myidx.PB(idx); else if(opt[idx].li<=hi&&li<=opt[idx].hi) noptidx.PB(idx);
	}
	//printf("rec(%d..%d):",li,hi); REPSZ(i,myidx) printf(" %d",myidx[i]); puts("");

	FORE(k,1,K) {
		//printf("k=%d\n",k);
		vector<int> curidx; REPSZ(_,myidx) { int idx=myidx[_]; if(opt[idx].vals[k-1]!=LLONG_MAX) curidx.PB(idx); }
		sort(curidx.begin(),curidx.end(),[&](int p,int q) { if(opt[p].mx!=opt[q].mx) return opt[p].mx>opt[q].mx; return opt[p].vals[k-1]<opt[q].vals[k-1]; });
		MergableHull hull2; REPSZ(_,curidx) { int idx=curidx[_],pidx=_==0?-1:curidx[_-1]; if(pidx!=-1&&opt[pidx].mx==opt[idx].mx) continue; MergableHull cur; cur.init(opt[idx].vals[k-1],-opt[idx].mx); /*printf("appending %lld %lld\n",opt[idx].vals[k-1],-(ll)opt[idx].mx);*/ if(_==0) hull2=cur; else hull2=merge(hull2,cur); }
		//printhull(hull2); puts("");
		if(hull2.head!=-1) FORE(i,li,hi) dp[i][k]=min(dp[i][k],hull2.query(i));
		//printhull(hull2); puts("");
		//FORE(i,li,hi) REPSZ(_,myidx) { int idx=myidx[_]; if(opt[idx].vals[k-1]!=LLONG_MAX) dp[i][k]=min(dp[i][k],(ll)i*opt[idx].mx+opt[idx].vals[k-1]); }
		hull2.releaseall();
	}

	if(li==hi) {
		process(li);
	} else {
		int mi=li+(hi-li)/2;
		rec(li,mi,noptidx); rec(mi+1,hi,noptidx);
	}
}

ll solve() {
	nstck=0; opt.clear();
	REP(i,n) {
		while(nstck>0&&a[i]>=a[stck[nstck-1]]) {
			int idx=stck[--nstck];
			opt.PB(Opt(nstck==0?0:stck[nstck-1]+1,idx,a[idx],idx+1,i));
		}
		stck[nstck++]=i;
	}
	while(nstck>0) {
		int idx=stck[--nstck];
		opt.PB(Opt(nstck==0?0:stck[nstck-1]+1,idx,a[idx],idx+1,n));
	}
	REPSZ(i,opt) opt[i].vals=vector<ll>(K+1,-1LL);
	REPE(i,n) who[i].clear(); REPSZ(i,opt) who[opt[i].hj].PB(i);
	//printf("opt:"); REPSZ(i,opt) printf(" [%d..%d,%d,%d..%d]",opt[i].lj,opt[i].hj,opt[i].mx,opt[i].li,opt[i].hi); puts("");

	REPE(k,K) hull1[k].clear();
	REPE(i,n) REPE(k,K) dp[i][k]=i==0?0:LLONG_MAX;
	process(0);
	vector<int> optidx; REPSZ(i,opt) optidx.PB(i);
	rec(1,n,optidx);
	REPE(k,K) REPSZ(j,hull1[k]) hull1[k][j].second.releaseall();

	return dp[n][K];
}

void run() {
	scanf("%d%d",&n,&K);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

ll solvestupid() {
	vector<vector<ll>> dp(n+1,vector<ll>(K+1,LLONG_MAX)); REPE(k,K) dp[0][k]=0;
	FORE(i,1,n) FORE(k,1,K) REP(j,i) { int mx=0; FOR(_,j,i) mx=max(mx,a[_]); if(dp[j][k-1]!=LLONG_MAX) dp[i][k]=min(dp[i][k],dp[j][k-1]+(ll)(i-j)*mx); }
	return dp[n][K];
}

void stress() {
	int mxn=10;
	REP(rep,100000) {
		n=rand()%mxn+1,K=rand()%n+1;
		REP(i,n) a[i]=rand()%100;
		ll have=solve();
		ll want=solvestupid();
		if(have==want) { if(rep%100==99) printf("."); continue; }
		printf("err in rep %d\n",rep);
		printf("have=%lld want=%lld\n",have,want);
		printf("%d %d\n",n,K); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
	}
}

void stresslarge() {
	REP(rep,1) {
		n=20000,K=100;
		REP(i,n) a[i]=n-i-1;
		ll have=solve();
		printf("have=%lld\n",have);
	}
}

int main() {
	run();
	//stress();
	//stresslarge();
	//fprintf(stderr,"SZ(nodes)=%d (%d)\n",SZ(MergableHull::nodes),SZ(MergableHull::pool));
	return 0;
}