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
const int MAXSUMLEN=200000;
const int MAXT=MAXSUMLEN+1;
const int MAXQ=500000;
const int ASIZE=26;
typedef struct Q { int x,sgn,l,r,idx; } Q;

int n,nq;
int off[MAXN],len[MAXN];
char s[MAXSUMLEN+1];

int nt,root;
int tnxt[MAXT][ASIZE];
int lst[MAXN];
int f[MAXT];
int q[MAXT],qhead,qtail;
int ufst[MAXT],unxt[MAXT];

int np;
int pfst[MAXT],pnxt[MAXSUMLEN],pidx[MAXSUMLEN];

int na;
int a[MAXSUMLEN];
int la[MAXT],ra[MAXT];
int afst[MAXN],anxt[MAXSUMLEN];

int ql[MAXQ],qr[MAXQ],qk[MAXQ];
int qlfst[MAXN],qlnxt[MAXQ];
int qrfst[MAXN],qrnxt[MAXQ];
int ret[MAXQ];

int fw[MAXN+1];

int create() { REP(i,ASIZE) tnxt[nt][i]=-1; pfst[nt]=-1; return nt++; }

void build(int i) {
	int at=root;
	REP(j,len[i]) {
		int x=s[off[i]+j]-'a';
		if(tnxt[at][x]==-1) tnxt[at][x]=create();
		at=tnxt[at][x];
		pnxt[np]=pfst[at]; pfst[at]=np; pidx[np]=i; ++np;
	}
	lst[i]=at;
}

void ahoc() {
	qhead=qtail=0;
	f[root]=root; q[qhead++]=root;
	while(qtail<qhead) {
		int at=q[qtail++];
		REP(i,ASIZE) if(tnxt[at][i]!=-1) {
			int to=tnxt[at][i];
			q[qhead++]=to;
			f[to]=f[at];
			while(f[to]!=root&&tnxt[f[to]][i]==-1) f[to]=f[f[to]];
			if(at!=root&&tnxt[f[to]][i]!=-1) f[to]=tnxt[f[to]][i];
		}
	}
}

void makea(int at) {
	la[at]=na;
	for(int y=pfst[at];y!=-1;y=pnxt[y]) a[na++]=pidx[y];
	for(int x=ufst[at];x!=-1;x=unxt[x]) makea(x);
	ra[at]=na;
}

void printt(int at,int d=0) {
	REP(i,ASIZE) if(tnxt[at][i]!=-1) {
		int to=tnxt[at][i];
		REP(j,d) printf("  "); printf("%d=%c",to,'a'+i); for(int y=pfst[to];y!=-1;y=pnxt[y]) printf(" %d",pidx[y]); printf(" (%d)\n",f[to]);
		printt(to,d+1);
	}
}

void printu(int at,int d=0) {
	for(int x=ufst[at];x!=-1;x=unxt[x]) {
		int to=x;
		REP(j,d) printf("  "); printf("%d=%c",to,'?'); for(int y=pfst[to];y!=-1;y=pnxt[y]) printf(" %d",pidx[y]); printf(" (%d)\n",f[to]);
		printu(to,d+1);
	}
}

void fwinc(int x) { while(x<=MAXN) { fw[x]++; x+=x&-x; } }
int fwget(int x) { int ret=0; while(x>0) { ret+=fw[x]; x-=x&-x; } return ret; }
int calc(int i) { return fwget(ra[lst[i]])-fwget(la[lst[i]]); }

void input() {
	scanf("%d%d",&n,&nq);
	REP(i,n) {
		off[i]=i==0?0:off[i-1]+len[i-1];
		scanf("%s",s+off[i]);
		len[i]=strlen(s+off[i]);
	}
	s[off[n-1]+len[n-1]]='\0';
	//printf("%s\n",s);
	REP(qi,nq) { scanf("%d%d%d",&ql[qi],&qr[qi],&qk[qi]); --ql[qi],--qr[qi],--qk[qi]; }
}

void solve() {
	nt=np=0; root=create();
	REP(i,n) build(i);
	ahoc();
	//printt(root);

	REP(i,nt) ufst[i]=-1;
	unxt[root]=-1; REP(i,nt) if(i!=root) { unxt[i]=ufst[f[i]]; ufst[f[i]]=i; }
	//printu(root);

	na=0;
	makea(root);
	REP(i,n) afst[i]=-1;
	REP(i,na) anxt[i]=afst[a[i]],afst[a[i]]=i;
	//REP(i,na) printf("%d ",a[i]); puts("");

	REP(i,n) qlfst[i]=qrfst[i]=-1;
	REP(qi,nq) {
		qlnxt[qi]=qlfst[ql[qi]],qlfst[ql[qi]]=qi;
		qrnxt[qi]=qrfst[qr[qi]],qrfst[qr[qi]]=qi;
	}

	memset(fw,0,sizeof(fw)); memset(ret,0,sizeof(ret));
	REP(i,n) {
		for(int x=qlfst[i];x!=-1;x=qlnxt[x]) ret[x]-=calc(qk[x]);
		for(int x=afst[i];x!=-1;x=anxt[x]) fwinc(x+1);
		for(int x=qrfst[i];x!=-1;x=qrnxt[x]) ret[x]+=calc(qk[x]);
	}
}


void run() {
	input();
	solve();
	REP(qi,nq) printf("%d\n",ret[qi]);
}

void test() {
	n=441; nq=11;
	REP(i,MAXSUMLEN) s[i]='a'+rand()%26; s[MAXSUMLEN]='\0';
	while(true) { off[0]=0; FOR(i,1,n) off[i]=rand()%MAXSUMLEN; sort(off,off+n); bool ok=true; FOR(i,1,n) if(off[i]==off[i-1]) ok=false; if(ok) break; }
	REP(i,n-1) len[i]=off[i+1]-off[i]; len[n-1]=MAXSUMLEN-off[n-1];
	REP(i,nq) { ql[i]=rand()%n,qr[i]=rand()%n,qk[i]=rand()%n; if(ql[i]>qr[i]) swap(ql[i],qr[i]); }
	solve();
	REP(qi,nq) printf("%d\n",ret[qi]);
}



int main() {
	run();
	//test();
	return 0;
}