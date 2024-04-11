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

const int MAXN=200000;
const int MAXQ=200000;
const int MAXBITS=14;
const int BSZ=1024;

int n,sz,nq;
int inita[MAXN];
int initb[MAXN];
char qkind[MAXQ]; int qidx[MAXQ],qval[MAXQ];
int ans[MAXQ+1];

int a[MAXN];
int b[MAXN];
int x[MAXN];

int lazyfixed;
int fixedcount[1<<MAXBITS];
int globfreezerocount;

struct Block {
	int lazy;
	int val[BSZ];
	int cnt[1<<MAXBITS];
	Block() { lazy=0; memset(val,0,sizeof(val)); memset(cnt,0,sizeof(cnt)); cnt[0]=BSZ; }
	void updall(int v) { lazy^=v; }
	void updsingle(int idx,int v) { --cnt[val[idx]]; val[idx]^=v; ++cnt[val[idx]]; }
	int getzerocount() { return cnt[lazy]; }
	int get(int idx) { return val[idx]^lazy; }
};

struct Group { // represents a group of numbers which are the same mod sz
	int id,nfree; bool havefixed; int nblock,nsingle;
	vector<Block> freeblocks;
	vector<int> freesingles;
	int fixed;
	int locfreezerocount;

	void init(int _id,bool _havefixed) { 
		id=_id; havefixed=_havefixed; nfree=(n-(havefixed?sz:0))/sz+(id<(n-(havefixed?sz:0))%sz?1:0); nblock=nfree/BSZ,nsingle=nfree-nblock*BSZ;
		freeblocks=vector<Block>(nblock); freesingles=vector<int>(nsingle,0); fixed=havefixed?0:-1;
		locfreezerocount=nfree; globfreezerocount+=locfreezerocount; if(havefixed) ++fixedcount[fixed]; 
	}
	void upd(int idx,int val) { 
		assert(idx%sz==id); idx=(idx-id)/sz; assert(0<=idx&&idx<nfree+(havefixed?1:0)); 
		globfreezerocount-=locfreezerocount;
		while(idx<nsingle) {
			if(freesingles[idx]==0) --locfreezerocount;
			freesingles[idx]^=val;
			if(freesingles[idx]==0) ++locfreezerocount;
			++idx;
		}
		while((idx-nsingle)%BSZ!=0) {
			int key=(idx-nsingle)/BSZ,off=(idx-nsingle)%BSZ;
			if(freeblocks[key].get(off)==0) --locfreezerocount;
			freeblocks[key].updsingle(off,val);
			if(freeblocks[key].get(off)==0) ++locfreezerocount;
			++idx;
		}
		while(idx<nfree) {
			int key=(idx-nsingle)/BSZ;
			locfreezerocount-=freeblocks[key].getzerocount();
			freeblocks[key].updall(val);
			locfreezerocount+=freeblocks[key].getzerocount();
			idx+=BSZ;
		}
		globfreezerocount+=locfreezerocount;
		if(havefixed) --fixedcount[fixed],fixed^=val,++fixedcount[fixed];
	}
	int get(int idx) { 
		assert(idx%sz==id); idx=(idx-id)/sz; assert(0<=idx&&idx<nfree+(havefixed?1:0)); 
		return idx<nsingle?freesingles[idx]:idx<nfree?freeblocks[(idx-nsingle)/BSZ].get((idx-nsingle)%BSZ):fixed^lazyfixed; 
	}
};

Group g[MAXN];

void upd(int idx,int val) {
	//printf("n=%d sz=%d upd(%d,%d)\n",n,sz,idx,val);
	g[idx%sz].upd(idx,val);
	if(idx+1<=n-sz) {
		g[(idx+1)%sz].upd(idx+1,val);
		int k=(n-sz-(idx+1)+sz-1)/sz;
		if((idx+1)%sz!=n%sz) g[(idx+1)%sz].upd(idx+1+k*sz,val);
	}
	if(idx%sz==n%sz) lazyfixed^=val;

	/*x[idx]^=val;
	if(sz==1) return;
	while(idx<n-sz) {
		x[idx+1]^=val;
		x[idx+sz]^=val;
		idx+=sz;
	}
	if(idx==n-sz) REP(i,sz-1) x[n-(sz-1)+i]^=val;
	REP(i,n) if(g[i%sz].get(i)!=x[i]) {
		printf("actual:"); REP(i,n) printf(" %d",g[i%sz].get(i)); puts("");
		printf("expect:"); REP(i,n) printf(" %d",x[i]); puts("");
		exit(0);
	}*/
}

int calc() {
	if(fixedcount[lazyfixed]!=sz-1) return -1;
	return n-(sz-1)-globfreezerocount;
	//REP(i,sz-1) if(x[n-(sz-1)+i]!=0) return -1;
	//int ret=0; REP(i,n-(sz-1)) if(x[i]!=0) ++ret; return ret;
}

void solve() {
	REP(i,n) x[i]=0,a[i]=inita[i],b[i]=initb[i];
	lazyfixed=0; memset(fixedcount,0,sizeof(fixedcount)); globfreezerocount=0;
	REP(i,sz) g[i].init(i,i%sz!=n%sz);
	REP(i,n) upd(i,a[i]^b[i]);
	REPE(i,nq) {
		ans[i]=calc();
		if(i==nq) break;
		int before,after;
		if(qkind[i]=='a') before=a[qidx[i]],after=a[qidx[i]]=qval[i];
		if(qkind[i]=='b') before=b[qidx[i]],after=b[qidx[i]]=qval[i];
		upd(qidx[i],before^after);
	}
}

void run() {
	scanf("%d%d%d",&n,&sz,&nq);
	REP(i,n) scanf("%d",&inita[i]);
	REP(i,n) scanf("%d",&initb[i]);
	REP(i,nq) scanf(" %c%d%d",&qkind[i],&qidx[i],&qval[i]),--qidx[i];
	solve();
	REPE(i,nq) printf("%d\n",ans[i]);
}


int bfcalc() {
	vector<int> c(MAXN);
	REP(i,n) c[i]=a[i];
	int ret=0;
	REP(i,n) if(c[i]!=b[i]) {
		if(i+sz>n) return -1;
		int x=c[i]^b[i];
		REP(j,sz) c[i+j]^=x;
		++ret;
	}
	return ret;
}

int bfans[MAXQ+1];
void bfsolve() {
	REP(i,n) a[i]=inita[i],b[i]=initb[i];
	REPE(i,nq) {
		bfans[i]=bfcalc();
		if(i==nq) break;
		if(qkind[i]=='a') a[qidx[i]]=qval[i];
		if(qkind[i]=='b') b[qidx[i]]=qval[i];
	}
}

void stress1() {
	REP(rep,1000) {
		n=20; int maxsz=5; sz=1+rand()%maxsz; nq=20; int bits=2;
		REP(i,n) inita[i]=rand()%(1<<bits),initb[i]=rand()%(1<<bits);
		REP(i,nq) qkind[i]='a'+rand()%2,qidx[i]=rand()%n,qval[i]=rand()%(1<<bits);
		solve();
		bfsolve();
		bool ok=true; REP(i,nq) if(ans[i]!=bfans[i]) ok=false;
		if(ok) { printf("."); continue; }
		printf("err: rep=%d\n",rep);
		printf("%d %d %d\n",n,sz,nq); REP(i,n) { if(i!=0) printf(" "); printf("%d",inita[i]); } puts(""); REP(i,n) { if(i!=0) printf(" "); printf("%d",initb[i]); } puts(""); REP(i,nq) printf("%c %d %d\n",qkind[i],qidx[i]+1,qval[i]);
		printf("have: ",sz); REPE(i,nq) { if(i!=0) printf(" "); printf("%2d",ans[i]); } puts("");
		printf("want: ",sz); REPE(i,nq) { if(i!=0) printf(" "); printf("%2d",bfans[i]); } puts("");
		break;
	}
}

void stress2() {
	REP(rep,50) {
		n=MAXN; vector<int> szopt; szopt.PB(1); szopt.PB(2); szopt.PB(3); szopt.PB(5); szopt.PB(10); szopt.PB(100); szopt.PB(1000); szopt.PB(10000); szopt.PB(100000); szopt.PB(MAXN); sz=szopt[rand()%SZ(szopt)]; int nq=MAXQ; int bits=MAXBITS; if(sz>n) continue;
		REP(i,n) inita[i]=rand()%(1<<bits),initb[i]=rand()%(1<<bits);
		REP(i,nq) qkind[i]='a'+rand()%2,qidx[i]=rand()%n,qval[i]=rand()%(1<<bits);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress1();
	//stress2();
	return 0;
}