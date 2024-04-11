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
#include<bitset>
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
const int MAXQ=100000;

int n,MOD,nq;
int val[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int l[MAXN],r[MAXN],rval[MAXN]; int cid;

typedef struct BS2 {
	ull val[16];
	void clear() { memset(val,0,sizeof(val)); }
	void set(int bit) { val[bit/64]|=1ULL<<(bit%64); }
	void merge(const BS2 &a) { REP(i,16) val[i]|=a.val[i]; }
	void set(const BS2 &a,const BS2 &b) { REP(i,16) val[i]=a.val[i]|b.val[i]; }
	inline ull shft(ull &a,int lft,int rgt) { assert(lft>=0&&rgt>=0); if(lft>=64) return 0; if(rgt>=64) return 0; return (a<<lft)>>rgt; }
	void rot(int by) {
		static ull tmp[16]; memset(tmp,0,sizeof(tmp));
		int a=by/64,b=by%64,A=MOD/64,B=MOD%64;
		REP(i,A+(B!=0?1:0)) {
			if(a==A) {
				tmp[a]|=shft(val[i],64+b-B,64-B),tmp[0]|=shft(val[i],0,B-b);
				//printf("\t\t\t%d: %llx, 0: %llx\n",a,(val[i]<<(64+b-B))>>(64-B),val[i]>>(B-b));
				a=0,b=b+64-B;
			} else if(a+1==A&&B<b) {
				tmp[a]|=shft(val[i],b,0),tmp[a+1]|=shft(val[i],b-B,64-B),tmp[0]|=shft(val[i],0,64+B-b);
				//printf("\t\t\t%d: %llx, %d: %llx, 0: %llx\n",a,val[i]<<b,a+1,(val[i]<<(b-B))>>(64-B),val[i]>>(64+B-b));
				a=0,b=b-B;
			} else {
				tmp[a]|=shft(val[i],b,0),tmp[a+1]|=shft(val[i],0,64-b);
				//printf("\t\t\t%d: %llx, 0: %llx\n",a,val[i]<<b,val[i]>>(64-b));
				++a;
			}
		}
		REP(i,16) val[i]=tmp[i];
	}
	int cnt(const BS2 &a) {
		int ret=0;
		REP(i,16) {
			ull cur=val[i]&a.val[i];
			REP(j,64) if((cur>>j)&1) ++ret;
		}
		return ret;
	}
	void print() { REP(i,MOD) { if(i!=0&&i%8==0) printf(" "); printf("%c",((val[i/64]>>(i%64))&1)?'x':'.' ); } FOR(i,MOD,64*16) if((val[i/64]>>(i%64))&1) printf(" [%d]",i); }
} BS;
//typedef bitset<1003> BS;

void dfs(int at,int par) {
	rval[cid]=val[at]; l[at]=cid++;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gto[x]!=par) dfs(gto[x],at);
	r[at]=cid;
}


BS sval[2*MAXN],pr;
int slazy[2*MAXN];
void sinit() {
	memset(sval,0,sizeof(sval)); memset(slazy,0,sizeof(slazy));
	REP(i,n) sval[n+l[i]].set(val[i]%MOD);
	for(int i=n-1;i>=1;--i) sval[i].set(sval[i<<1],sval[i<<1|1]);
}
void sinc(int idx,int by) { /*printf("\t\tsinc(%d,%d)\n",idx,by);*/ if((slazy[idx]+=by)>=MOD) slazy[idx]-=MOD; }
void spushone(int idx) { if(slazy[idx]==0) return; /*printf("\tspushone(%d)\n",idx);*/ sval[idx].rot(slazy[idx]); if(idx<n) { sinc(idx<<1,slazy[idx]); sinc(idx<<1|1,slazy[idx]); } slazy[idx]=0; }
void spush(int idx) { idx+=n; /*printf("spush(%d)\n",idx);*/ int k=0; while((idx>>k)>=2) ++k; for(;k>=0;--k) { int cidx=idx>>k; spushone(cidx); } }
void sbuild(int idx) { /*printf("sbuild(%d)\n",idx);*/ for(idx+=n,idx>>=1;idx>=1;idx>>=1) { spushone(idx<<1); spushone(idx<<1|1); sval[idx].set(sval[idx<<1],sval[idx<<1|1]); } }
void _smod(int lidx,int ridx,int by) { for(lidx+=n,ridx+=n;lidx<ridx;lidx>>=1,ridx>>=1) { if(lidx&1) sinc(lidx,by),++lidx; if(ridx&1) --ridx,sinc(ridx,by); } }
void smod(int lidx,int ridx,int by) { spush(lidx); spush(ridx-1); _smod(lidx,ridx,by); sbuild(lidx); sbuild(ridx-1); }
void sget(int lidx,int ridx,BS &ret) {
	spush(lidx); spush(ridx-1);
	for(lidx+=n,ridx+=n;lidx<ridx;lidx>>=1,ridx>>=1) { if(lidx&1) spushone(lidx),ret.merge(sval[lidx]),lidx++; if(ridx&1) --ridx,spushone(ridx),ret.merge(sval[ridx]); }
}
//void sprint() { FOR(i,1,2*n) { printf("%2d: ",i); sval[i].print(); printf(" (%d)\n",slazy[i]); } }

int qtype[MAXQ],qx[MAXQ],qby[MAXQ];
int ret[MAXQ],nret;
void input() {
	scanf("%d%d",&n,&MOD);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d",&qtype[i]); if(qtype[i]==1) scanf("%d%d",&qx[i],&qby[i]),--qx[i]; if(qtype[i]==2) scanf("%d",&qx[i]),--qx[i]; }
}

void solve() {
	cid=0; dfs(0,-1); memset(sval,0,sizeof(sval)); sinit(); nret=0; assert(cid==n);
	pr.clear(); FOR(i,2,MOD) { bool ok=true; for(int j=2;j*j<=i;++j) if(i%j==0) ok=false; if(ok) pr.set(i); }
	//printf("pr: "); pr.print(); puts(""); sprint();
	REP(i,nq) {
		if(qtype[i]==1) {
			smod(l[qx[i]],r[qx[i]],qby[i]%MOD);
		}
		if(qtype[i]==2) {
			BS res; memset(&res,0,sizeof(res)); sget(l[qx[i]],r[qx[i]],res);
			//printf("q%d: ",i); res.print(); puts("");
			ret[nret++]=res.cnt(pr);
		}
		//printf("afer q%d\n",i); sprint();
	}
}

void run() {
	input();
	solve();
	REP(i,nret) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}