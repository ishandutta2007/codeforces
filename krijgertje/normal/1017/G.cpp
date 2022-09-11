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

int n,nq;
int par[MAXN];

vector<int> ch[MAXN];
int cidx[MAXN],fstidx[MAXN],nc;
int sz[MAXN];
int heavy[MAXN];
int hroot[MAXN],hlen[MAXN],hwho[MAXN],hidx[MAXN],nh;

void dfsinit(int at) {
	sz[at]=1,heavy[at]=-1;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfsinit(to);
		sz[at]+=sz[to];
		if(heavy[at]==-1||sz[to]>sz[heavy[at]]) heavy[at]=to;
	}
	REPSZ(i,ch[at]) if(ch[at][i]==heavy[at]) swap(ch[at][i],ch[at][0]); assert(heavy[at]==-1&&SZ(ch[at])==0||SZ(ch[at])>=1&&ch[at][0]==heavy[at]);
	fstidx[at]=nc; REPSZ(i,ch[at]) cidx[ch[at][i]]=i==0?-1:nc++;
}

const int MAXS=2*4*MAXN;
struct Op { bool reset,black; int a,b; /* a*idx+b */ Op():reset(reset),black(false),a(0),b(0) {} Op(bool reset,bool black,int a,int b):reset(reset),black(black),a(a),b(b) {} };

Op sop[MAXS];
pair<int,int> sres[MAXS];
void sapply(int x,int l,int r,Op op) {
	if(op.reset) sop[x].reset=true,sop[x].black=false,sop[x].a=sop[x].b=0,sres[x]=MP(0,r-l+1);
	if(op.black) sop[x].black=true,sres[x]=MP(r-l+1,0);
	sop[x].a+=op.a,sop[x].b+=op.b;
}
pair<int,int> smerge(const pair<int,int> &lres,int lcnt,const pair<int,int> &rres) {
	return lres.first+lres.second<lcnt?lres:lres.first==0?lres.second==0?rres:MP(0,lres.second+(rres.first==0?rres.second:0)):lres.second==0?MP(lres.first+rres.first,rres.second):MP(lres.first,lres.second+(rres.first==0?rres.second:0));
}
void spush(int x,int l,int m,int r) {
	if(sop[x].reset||sop[x].black||sop[x].a!=0||sop[x].b!=0) sapply(2*x+1,l,m,sop[x]),sapply(2*x+2,m+1,r,sop[x]),sop[x]=Op(false,false,0,0);
}
void spull(int x,int l,int m,int r) {
	sres[x]=smerge(sres[2*x+1],m-l+1,sres[2*x+2]);
}

void sinit(int x,int l,int r) {
	sop[x]=Op(false,false,0,0);
	sres[x]=MP(0,r-l+1);
	if(l!=r) {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
	}
}
void sreset(int x,int l,int r,int L,int R) {
	//if(x==0) printf("sreset(%d..%d)\n",L,R);
	if(L<=l&&r<=R) {
		sapply(x,l,r,Op(true,false,0,0));
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(L<=m) sreset(2*x+1,l,m,L,R);
		if(m+1<=R) sreset(2*x+2,m+1,r,L,R);
		spull(x,l,m,r);
	}
}
void smod(int x,int l,int r,int L,int R,int A,int B) {
	//if(x==0) printf("smod(%d..%d,%d*x+%d)\n",L,R,A,B);
	if(L<=l&&r<=R) {
		sapply(x,l,r,Op(false,true,A,B));
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(L<=m) smod(2*x+1,l,m,L,R,A,B);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,A,B);
		spull(x,l,m,r);
	}
}
Op sremove(int x,int l,int r,int IDX) {
	//if(x==0) printf("sremove(%d)\n",IDX);
	if(l==r) {
		Op ret=sop[x]; sop[x]=Op(false,ret.black,0,0); sres[x]=ret.black?MP(1,0):MP(0,1); return ret;
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		Op ret=IDX<=m?sremove(2*x+1,l,m,IDX):sremove(2*x+2,m+1,r,IDX);
		spull(x,l,m,r);
		return ret;
	}
}
pair<int,int> sgetpref(int x,int l,int r,int L,int R) {
	//if(x==0) printf("sgetpref(%d..%d)\n",L,R);
	if(L<=l&&r<=R) {
		return sres[x];
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		pair<int,int> lres=L<=m?sgetpref(2*x+1,l,m,L,R):MP(0,0);
		pair<int,int> rres=m+1<=R?sgetpref(2*x+2,m+1,r,L,R):MP(0,0);
		spull(x,l,m,r);
		pair<int,int> ret=smerge(lres,L<=m?m-max(l,L)+1:0,rres);
		//printf("%d..%d: (%d,%d)+(%d,%d)=(%d,%d) [%d]\n",l,r,lres.first,lres.second,rres.first,rres.second,ret.first,ret.second,L<=m?m-max(l,L)+1:0);
		return ret;
	}
}
bool sget(int x,int l,int r,int IDX) {
	//if(x==0) printf("sget(%d)\n",IDX);
	if(l==r) {
		return sop[x].black;
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		bool ret=IDX<=m?sget(2*x+1,l,m,IDX):sget(2*x+2,m+1,r,IDX);
		spull(x,l,m,r);
		return ret;
	}
}


void creset(int l,int r) { sreset(0,0,nc+nh-1,l,r); }
void cmod(int l,int r,int a,int b) { smod(0,0,nc+nh-1,l,r,a,b); }
void hreset(int l,int r) { sreset(0,0,nc+nh-1,nc+l,nc+r); }
void hmod(int l,int r,int a,int b) { smod(0,0,nc+nh-1,nc+l,nc+r,a,b); }
pair<int,int> hgetpref(int l,int r) { return sgetpref(0,0,nc+nh-1,nc+l,nc+r); }

pair<bool,int> cremove(int at) {
	Op op=sremove(0,0,nc+nh-1,cidx[at]);
	return MP(op.reset,op.a*(cidx[at]-fstidx[par[at]])+op.b);
}
pair<bool,int> hremove(int at) {
	Op op=sremove(0,0,nc+nh-1,nc+hidx[at]);
	return MP(op.reset,op.a*(hidx[at]-hidx[hroot[at]])+op.b);
}

void cmod(int at,bool reset,int cnt) {
	if(reset) creset(fstidx[at],fstidx[at]+SZ(ch[at])-2);
	if(cnt!=0) cmod(fstidx[at],fstidx[at]+SZ(ch[at])-2,0,cnt);
}

void hmod(int at,bool reset,int cnt) {
	int l=hidx[at],r=hidx[hroot[at]]+hlen[hroot[at]]-1,off=hidx[at]-hidx[hroot[at]];
	if(reset) hreset(l,r);
	while(cnt>0) {
		//printf("hmod loop\n");
		pair<int,int> pref=hgetpref(l,r);
		//printf("pref=(%d,%d)\n",pref.first,pref.second);
		if(pref.second==0) {
			assert(pref.first==hlen[hroot[at]]-off);
			hmod(l,r,0,cnt);
			cnt=0;
		} else {
			int cur=min(cnt,pref.second);
			hmod(l,l+pref.first+cur-1,-1,off+pref.first+cur-1);
			if(pref.first!=0) hmod(l,l+pref.first-1,+1,-(pref.first+off-1));
			cnt-=cur;
		}
	}
}

bool hget(int at) {
	return sget(0,0,nc+nh-1,nc+hidx[at]);
}
void hreset(int at) {
	hreset(hidx[at],hidx[hroot[at]]+hlen[hroot[at]]-1);
}

void normalize(int at) {
	//printf("normalizing %d:",at);
	vector<int> lst; for(int x=at;x!=-1;x=par[hroot[x]]) lst.PB(hroot[x]); reverse(lst.begin(),lst.end());
	//REPSZ(i,lst) printf(" %d",lst[i]); puts("");
	FORSZ(i,1,lst) {
		int x=lst[i],y=par[x];
		pair<bool,int> op1=hremove(y);
		cmod(y,op1.first,op1.second);
		pair<bool,int> op2=cremove(x);
		hmod(x,op2.first,op2.second);
	}
}

int qkind[MAXQ],qat[MAXQ];
bool qans[MAXQ];

void solve() {
	REP(i,n) ch[i].clear();
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	nc=0; cidx[0]=-1; dfsinit(0);
	nh=0; REP(i,n) if(par[i]==-1||i!=heavy[par[i]]) { hlen[i]=0; for(int at=i;at!=-1;at=heavy[at]) hroot[at]=i,hwho[nh]=at,hidx[at]=nh++,++hlen[i]; }
	//REP(i,n) printf("%d: par=%d sz=%d heavy=%d hroot=%d hidx=%d cidx=%d\n",i,par[i],sz[i],heavy[i],hroot[i],hidx[i],cidx[i]);

	sinit(0,0,nc+nh-1);
	REP(i,nq) {
		int kind=qkind[i],at=qat[i];
		normalize(at);
		if(kind==1) {
			hmod(at,false,1);
		}
		if(kind==2) {
			hmod(at,true,0);
		}
		if(kind==3) {
			qans[i]=hget(at);
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,nq) scanf("%d%d",&qkind[i],&qat[i]),--qat[i];
	solve();
	REP(i,nq) if(qkind[i]==3) printf("%s\n",qans[i]?"black":"white");
}

bool bfans[MAXQ];
bool bfval[MAXN];
void bfmod(int at,int kind) {
	if(kind==1&&!bfval[at]) { bfval[at]=true; return; }
	if(kind==2) bfval[at]=false;
	REPSZ(i,ch[at]) { int to=ch[at][i]; bfmod(to,kind); }
}
void bfsolve() {
	REP(i,n) bfval[i]=false;
	REP(i,nq) {
		int kind=qkind[i],at=qat[i];
		if(kind==1) bfmod(at,kind);
		if(kind==2) bfmod(at,kind);
		if(kind==3) bfans[i]=bfval[at];
	}
}

void stress() {
	REP(rep,100000) {
		n=10; par[0]=-1; FOR(i,1,n) par[i]=rand()%i;
		nq=100; REP(i,nq) qkind[i]=rand()%3+1,qat[i]=rand()%n;
		solve();
		bfsolve();
		bool ok=true; REP(i,nq) if(qans[i]!=bfans[i]) ok=false;
		if(ok) { printf("."); continue; }
		REP(rep2,10000) {
			nq=8; REP(i,nq) qkind[i]=rand()%3+1,qat[i]=rand()%n;
			solve();
			bfsolve();
			bool ok=true; REP(i,nq) if(qans[i]!=bfans[i]) ok=false;
			if(ok) { printf(","); continue; }
			puts("");
			printf("have: "); REP(i,nq) if(qkind[i]==3) printf("%c",qans[i]?'V':'.'); puts("");
			printf("want: "); REP(i,nq) if(qkind[i]==3) printf("%c",bfans[i]?'V':'.'); puts("");
			printf("%d %d\n",n,nq); FOR(i,1,n) { if(i!=1) printf(" "); printf("%d",par[i]+1); } puts(""); REP(i,nq) printf("%d %d\n",qkind[i],qat[i]+1);
			return;
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}