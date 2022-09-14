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
const int MAXM=MAXN-1;
const int MAXZ=100000;
const int MAXS=2*MAXN;

int n,nz,nq;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int zhead[MAXN],znxt[MAXZ];
int zoff[MAXN],zcnt[MAXN],zid[MAXZ];
int q[MAXN],qhead,qtail;
int par[MAXN],d[MAXN],sz[MAXN];
int heavy[MAXN],hroot[MAXN],hleaf[MAXN];
int stck[MAXN],stckx[MAXN],nstck;
int sidx[MAXN],gidx[MAXN],ns;
int smnidx[MAXN],smxidx[MAXN];
int tidx[MAXS]; ll tmn[MAXS],tlazy[MAXS];

int ret[MAXM],nret;

void sapply(int a,ll by) { tlazy[a]+=by; if(tmn[a]!=LLONG_MAX) tmn[a]+=by; }
void spush(int a) { if(tlazy[a]==0) return; sapply(a<<1,tlazy[a]); sapply(a<<1|1,tlazy[a]); tlazy[a]=0; }
void spushpath(int a) { int h=0; while(a>>(h+1)) ++h; for(int s=h;s>0;--s) spush(a>>s); }
void srecalc(int a) { spush(a); tmn[a]=tmn[a<<1],tidx[a]=tidx[a<<1]; if(tmn[a<<1|1]<tmn[a]) tmn[a]=tmn[a<<1|1],tidx[a]=tidx[a<<1|1]; }
void srecalcpath(int a) { while(a>1) { a>>=1; srecalc(a); } }
void sset(int a,int idx,ll val) {
	//printf("setting %d to (%d,%lld)\n",a,idx,val);
	a+=ns;
	tmn[a]=val,tidx[a]=idx; if(tmn[a]!=LLONG_MAX) tmn[a]+=tlazy[a];
	srecalcpath(a);
}
void sinc(int a,int b,int by) {
	if(a>=b) return;
	a+=ns,b+=ns;
	int aa=a,bb=b;
	for(;a<b;a>>=1,b>>=1) {
		if(a&1) sapply(a++,by);
		if(b&1) sapply(--b,by);
	}
	srecalcpath(aa),srecalcpath(bb-1);
}
void sfound(pair<int,ll> &ret,int a) { if(tmn[a]!=LLONG_MAX&&(ret.first==-1||tmn[a]<ret.second||tmn[a]==ret.second&&tidx[a]<ret.first)) ret=MP(tidx[a],tmn[a]); }
pair<int,ll> sfind(int a,int b) {
	//printf("\tsfind[%d..%d)\n",a,b);
	a+=ns,b+=ns;
	spushpath(a); spushpath(b-1);
	pair<int,ll> ret=MP(-1,0LL);
	for(;a<b;a>>=1,b>>=1) {
		if(a&1) sfound(ret,a++);
		if(b&1) sfound(ret,--b);
	}
	//printf("\t->(%d,%lld)\n",ret.first,ret.second);
	return ret;
}
pair<int,ll> hfind(int a,int b) {
	//printf("hfind(%d,%d)\n",a,b);
	pair<int,ll> ret=MP(-1,0LL);
	while(hroot[a]!=hroot[b]) {
		if(d[hroot[a]]<d[hroot[b]]) swap(a,b);
		pair<int,ll> cur=sfind(sidx[hroot[a]],sidx[a]+1);
		if(cur.first!=-1&&(ret.first==-1||cur.second<ret.second||cur.second==ret.second&&cur.first<ret.first)) ret=cur;
		a=par[hroot[a]];
	}
	{
		if(d[a]<d[b]) swap(a,b);
		pair<int,ll> cur=sfind(sidx[b],sidx[a]+1);
		if(cur.first!=-1&&(ret.first==-1||cur.second<ret.second||cur.second==ret.second&&cur.first<ret.first)) ret=cur;
	}
	return ret;
}

void input() {
	scanf("%d%d%d",&n,&nz,&nq);
	REP(i,n) ghead[i]=zhead[i]=-1,zcnt[i]=0;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	REP(i,nz) {
		int a; scanf("%d",&a); --a;
		znxt[i]=zhead[a]; zhead[a]=i; ++zcnt[a];
	}
}
void init() {
	zoff[0]=0; REP(i,n-1) zoff[i+1]=zoff[i]+zcnt[i];
	REP(i,n) for(int x=zhead[i];x!=-1;x=znxt[x]) zid[zoff[i]++]=x+1;
	REP(i,n) zoff[i]-=zcnt[i];
	REP(i,n) sort(zid+zoff[i],zid+zoff[i]+zcnt[i]);
	//REP(i,n) { printf("%d:",i); REP(j,zcnt[i]) printf(" %d",zid[zoff[i]+j]); puts(""); }

	qhead=qtail=0; REP(i,n) d[i]=-1,sz[i]=1,heavy[i]=-1,hroot[i]=-1;
	par[0]=-1,d[0]=0,q[qhead++]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(d[to]!=-1) continue; par[to]=at,d[to]=d[at]+1,q[qhead++]=to; }
	}
	for(int i=n-1;i>0;--i) sz[par[q[i]]]+=sz[q[i]];
	REP(to,n) if(par[to]!=-1) { int at=par[to]; if(heavy[at]==-1||sz[to]>sz[heavy[at]]) heavy[at]=to; }
	ns=nstck=0; stck[nstck]=0,stckx[nstck]=ghead[0],++nstck;
	while(nstck>0) {
		int at=stck[nstck-1],x=stckx[nstck-1]; --nstck;
		if(x==ghead[at]) {
			if(hroot[at]==-1) {
				for(int y=at;y!=-1;y=heavy[y]) hroot[y]=at;
				for(int y=at;y!=-1;y=heavy[y]) sidx[y]=ns,gidx[ns]=y,++ns;
				for(int y=at;y!=-1;y=heavy[y]) hleaf[y]=gidx[ns-1];
			}
			smnidx[at]=ns;
		}
		if(x==-1) { smxidx[at]=ns; continue; }
		int to=gto[x];
		stck[nstck]=at,stckx[nstck]=gnxt[x],++nstck;
		if(par[to]==at) { stck[nstck]=to,stckx[nstck]=ghead[to],++nstck; }
	}
	//REP(i,n) printf("%d: par=%d, d=%d, sz=%d, heavy=%d, hroot=%d, hleaf=%d, sidx=%d, smnidx=%d, smxidx=%d\n",i,par[i],d[i],sz[i],heavy[i],hroot[i],hleaf[i],sidx[i],smnidx[i],smxidx[i]);

	memset(tlazy,0,sizeof(tlazy));
	REP(i,n) sset(sidx[i],zcnt[i]==0?-1:i,zcnt[i]==0?LLONG_MAX:zid[zoff[i]]);
}
void query(int a,int b,int cnt) {
	nret=0;
	REP(i,cnt) {
		pair<int,ll> cur=hfind(a,b); int c=cur.first; //printf("\t=%lld\n",cur.second);
		if(c==-1) break;
		ret[nret++]=zid[zoff[c]],zoff[c]++,zcnt[c]--;
		sset(sidx[c],zcnt[c]==0?-1:c,zcnt[c]==0?LLONG_MAX:zid[zoff[c]]);
	}
}
void change(int a,int by) {
	sinc(sidx[a],sidx[hleaf[a]]+1,by);
	sinc(smnidx[a],smxidx[a],by);
}

void run() {
	input();
	init();
	
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int a,b,cnt; scanf("%d%d%d",&a,&b,&cnt); --a,--b;
			query(a,b,cnt);
			printf("%d",nret); REP(i,nret) printf(" %d",ret[i]); puts("");
		}
		if(type==2) {
			int a,by; scanf("%d%d",&a,&by); --a;
			change(a,by);
		}
	}
}

/*
int bfret[MAXZ],nbfret;
ll bfinc[MAXN];
vector<int> bflst[MAXN];
int bfq[MAXN],bfqhead,bfqtail;
void bfinit() {
	REP(i,n) bfinc[i]=0;
	REP(i,n) { bflst[i].clear(); for(int x=zhead[i];x!=-1;x=znxt[x]) bflst[i].PB(x+1); sort(bflst[i].begin(),bflst[i].end()); }
}
void bfquery(int a,int b,int cnt) {
	nbfret=0;
	REP(i,cnt) {
		pair<int,ll> ret=MP(-1,0LL);
		while(a!=b) {
			if(d[a]<d[b]) swap(a,b);
			if(SZ(bflst[a])>0&&(ret.first==-1||bfinc[a]+bflst[a][0]<ret.second||bfinc[a]+bflst[a][0]==ret.second&&a<ret.first)) ret.first=a,ret.second=bfinc[a]+bflst[a][0];
			a=par[a];
		}
		if(SZ(bflst[a])>0&&(ret.first==-1||bfinc[a]+bflst[a][0]<ret.second||bfinc[a]+bflst[a][0]==ret.second&&a<ret.first)) ret.first=a,ret.second=bfinc[a]+bflst[a][0];
		if(ret.first==-1) break;
		bfret[nbfret++]=bflst[ret.first][0];
		bflst[ret.first].erase(bflst[ret.first].begin());
	}
	
}
void bfchange(int a,int by) {
	bfqhead=bfqtail=0; bfq[bfqhead++]=a;
	while(bfqtail<bfqhead) {
		int at=bfq[bfqtail++];
		bfinc[at]+=by;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gto[x]!=par[at]) bfq[bfqhead++]=gto[x];
	}
}
bool bfsame() {
	if(nbfret!=nret) return false;
	REP(i,nret) if(ret[i]!=bfret[i]) return false;
	return true;
}

void test() {
	while(true) {
		n=1000,nz=1000,nq=1000;
		//printf("%d %d %d\n",n,nz,nq);
		REP(i,n) ghead[i]=zhead[i]=-1,zcnt[i]=0;
		REP(i,n-1) {
			int a=i+1,b=rand()%(i+1);
			//printf("%d %d\n",a+1,b+1);
			gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
			gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
		}
		REP(i,nz) {
			int a=rand()%n;
			//printf("%d ",a+1);
			znxt[i]=zhead[a]; zhead[a]=i; ++zcnt[a];
		} //puts("");
		init();
		bfinit();
		REP(qi,nq) {
			int type=rand()%2+1;
			if(type==1) {
				int a=rand()%n,b=rand()%n,cnt=min(1,(rand()%n)*(rand()%n)/n);
				//printf("%d %d %d %d\n",1,a+1,b+1,cnt);
				query(a,b,cnt);
				bfquery(a,b,cnt);
				if(!bfsame()) {
					printf("%d",nret); REP(i,nret) printf(" %d",ret[i]); puts("");
					printf("%d",nbfret); REP(i,nbfret) printf(" %d",bfret[i]); puts("");
					printf("diff\n"); exit(0);
				}
			}
			if(type==2) {
				int a=rand()%n,by=rand()%1000;
				//printf("%d %d %d\n",2,a+1,by);
				by*=1000000;
				change(a,by);
				bfchange(a,by);
			}
		}
		printf(".");
	}
}
*/

int main() {
	//test();
	run();
	return 0;
}