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
const int MAXS=4*MAXN;

int n,nq;
int val[MAXN];
set<int> pos[MAXN];

int qkind[MAXQ],qidx[MAXQ],qnval[MAXQ],ql[MAXQ],qr[MAXQ];

pair<int,int> contrib[MAXN];
int ncontribidx[MAXQ][3]; pair<int,int> ncontrib[MAXQ][3];

vector<int> bounds[MAXN];
vector<int> sbounds[MAXS];
vector<ll> sbit[MAXS];
void bmod(int x,int idx,int by) { ++idx; while(idx>0) { sbit[x][idx]+=by; idx-=idx&-idx; } }
ll bget(int x,int idx) { ++idx; ll ret=0; while(idx<=SZ(sbounds[x])) { ret+=sbit[x][idx]; idx+=idx&-idx; } return ret; }

void sinit(int x,int l,int r) {
	if(l==r) {
		sbounds[x]=bounds[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		int a=0,b=0;
		while(a<SZ(sbounds[2*x+1])||b<SZ(sbounds[2*x+2])) {
			int c=min(a<SZ(sbounds[2*x+1])?sbounds[2*x+1][a]:INT_MAX,b<SZ(sbounds[2*x+2])?sbounds[2*x+2][b]:INT_MAX);
			sbounds[x].PB(c);
			if(a<SZ(sbounds[2*x+1])&&sbounds[2*x+1][a]==c) ++a;
			if(b<SZ(sbounds[2*x+2])&&sbounds[2*x+2][b]==c) ++b;
		}
	}
	sbit[x]=vector<ll>(SZ(sbounds[x])+1,0);
	//printf("%d..%d:",l,r); REPSZ(i,sbounds[x]) printf(" %d",sbounds[x][i]); puts("");
}
void smod(int x,int l,int r,int IDX,int BY,int BOUND) {
	int bidx=lower_bound(sbounds[x].begin(),sbounds[x].end(),BOUND)-sbounds[x].begin(); assert(bidx!=SZ(sbounds[x])&&sbounds[x][bidx]==BOUND);
	bmod(x,bidx,BY);
	if(l!=r) {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*x+1,l,m,IDX,BY,BOUND); else smod(2*x+2,m+1,r,IDX,BY,BOUND);
	}
}
ll sget(int x,int l,int r,int L,int R,int BOUND) {
	if(L<=l&&r<=R) {
		int bidx=lower_bound(sbounds[x].begin(),sbounds[x].end(),BOUND)-sbounds[x].begin();
		return bidx==SZ(sbounds[x])?0:bget(x,bidx);
	} else {
		int m=l+(r-l)/2; ll ret=0;
		if(L<=m) ret+=sget(2*x+1,l,m,L,R,BOUND);
		if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R,BOUND);
		return ret;
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&val[i]),--val[i];
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) scanf("%d%d",&qidx[i],&qnval[i]),--qidx[i],--qnval[i]; else scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	}

	REP(i,n) pos[val[i]].insert(i);
	REP(i,n) { int prv=-1; for(auto it=pos[i].begin();it!=pos[i].end();++it) { int cur=*it; contrib[cur]=prv==-1?MP(0,0):MP(cur-prv,prv); prv=cur; } }
	REP(i,nq) if(qkind[i]==1) {
		int cur=qidx[i],ov=val[cur],nv=qnval[i];
		{
			auto it=pos[ov].find(cur); assert(it!=pos[ov].end());
			auto nxt=it; ++nxt;
			if(nxt==pos[ov].end()) ncontribidx[i][0]=-1; else { ncontribidx[i][0]=*nxt; if(it==pos[ov].begin()) ncontrib[i][0]=MP(0,0); else { auto prv=it; --prv; ncontrib[i][0]=MP(*nxt-*prv,*prv); } }
			pos[ov].erase(it);
		}
		{
			auto it=pos[nv].insert(cur).first; val[cur]=nv;
			auto nxt=it; ++nxt;
			ncontribidx[i][1]=*it; if(it==pos[nv].begin()) ncontrib[i][1]=MP(0,0); else { auto prv=it; --prv; ncontrib[i][1]=MP(*it-*prv,*prv); }
			if(nxt==pos[nv].end()) ncontribidx[i][2]=-1; else { ncontribidx[i][2]=*nxt; ncontrib[i][2]=MP(*nxt-*it,*it); }
		}
	}
	//REP(i,n) printf("%d: gain %d when l<=%d\n",i,contrib[i].first,contrib[i].second);
	//REP(i,nq) if(qkind[i]==1) REP(j,3) if(ncontribidx[i][j]!=-1) printf("q%d.%d: %d becomes %d when l<=%d\n",i,j,ncontribidx[i][j],ncontrib[i][j].first,ncontrib[i][j].second);

	REP(i,n) if(contrib[i].first>0) bounds[i].PB(contrib[i].second);
	REP(i,nq) if(qkind[i]==1) REP(j,3) if(ncontribidx[i][j]!=-1&&ncontrib[i][j].first>0) bounds[ncontribidx[i][j]].PB(ncontrib[i][j].second);
	REP(i,n) sort(bounds[i].begin(),bounds[i].end()),bounds[i].erase(unique(bounds[i].begin(),bounds[i].end()),bounds[i].end());
	//REP(i,n) { printf("%d:",i); REPSZ(j,bounds[i]) printf(" %d",bounds[i][j]); puts(""); }

	sinit(0,0,n-1);
	REP(i,n) if(contrib[i].first>0) smod(0,0,n-1,i,+contrib[i].first,contrib[i].second);
	REP(i,nq) {
		if(qkind[i]==1) {
			REP(j,3) {
				int idx=ncontribidx[i][j]; if(idx==-1) continue;
				if(contrib[idx].first>0) smod(0,0,n-1,idx,-contrib[idx].first,contrib[idx].second);
				contrib[idx]=ncontrib[i][j];
				if(contrib[idx].first>0) smod(0,0,n-1,idx,+contrib[idx].first,contrib[idx].second);
			}
		}
		if(qkind[i]==2) {
			ll ans=sget(0,0,n-1,ql[i],qr[i],ql[i]);
			printf("%lld\n",ans);
		}
	}
}

int main() {
	run();
	return 0;
}