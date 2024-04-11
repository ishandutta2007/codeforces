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
const int MAXLG=18;
const int MAXVAL=10000000;
const int MAXQ=100000;
const int MOD=1000000007;
struct E { int pw,qid,nodeid; E() {} E(int pw,int qid,int nodeid):pw(pw),qid(qid),nodeid(nodeid) {} };
bool operator<(const E &a,const E &b) { if(a.pw!=b.pw) return a.pw<b.pw; if((a.qid==-1)!=(b.qid==-1)) return a.qid==-1; return false; }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n;
vector<int> adj[MAXN];
int val[MAXN];
int nq;
int qa[MAXQ],qb[MAXQ],qx[MAXQ];
int ans[MAXQ];

int pmn[MAXVAL+1];

int par[MAXN],dep[MAXN];
int lid[MAXN],rid[MAXN],nid;
int up[MAXN][MAXLG+1];

vector<E> e[MAXVAL+1];

int bit[2*MAXN+1];

void dfsinit(int at) {
	lid[at]=nid++;
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at; dfsinit(to);
	}
	rid[at]=nid++;
}

int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}

void bmod(int idx,int by) { ++idx; while(idx<=nid) { bit[idx]+=by; idx+=idx&-idx; } }
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
int bget(int lidx,int ridx) { return bget(ridx)-bget(lidx-1); }


void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	REP(i,n) scanf("%d",&val[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d",&qa[i],&qb[i],&qx[i]),--qa[i],--qb[i];

	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;

	nid=0; par[0]=-1; dfsinit(0);
	//REP(i,n) printf("%d: lid=%d rid=%d\n",i,lid[i],rid[i]);

	REP(i,n) {
		int x=val[i];
		while(x!=1) {
			int p=pmn[x],pw=0;
			while(x%p==0) x/=p,++pw;
			//printf("%d: val=%d -> p=%d pw=%d x=%d\n",i,val[i],p,pw,x);
			FORE(k,1,pw) e[p].PB(E(k,-1,i));
		}
	}
	REP(i,nq) {
		int x=qx[i];
		while(x!=1) {
			int p=pmn[x],pw=0;
			while(x%p==0) x/=p,++pw;
			e[p].PB(E(pw,i,-1));
		}
	}

	REP(i,nq) ans[i]=1;
	memset(bit,0,sizeof(bit));
	FORE(p,2,MAXVAL) if(SZ(e[p])!=0) {
		sort(e[p].begin(),e[p].end());
		//printf("%d:",p); REPSZ(i,e[p]) if(e[p][i].qid!=-1) printf(" q%d",e[p][i].qid+1); else printf(" n%d",e[p][i].nodeid+1); puts("");

		REPSZ(i,e[p]) {
			if(e[p][i].qid!=-1) {
				int qid=e[p][i].qid;
				int a=qa[qid],b=qb[qid];
				if(lid[a]>lid[b]) swap(a,b);
				int c=lca(a,b);
				//printf("a=%d b=%d c=%d -> [%d..%d] [%d..%d] [%d..%d]\n",a+1,b+1,c+1,lid[a],rid[a],lid[b],rid[b],lid[c],rid[c]);
				int sum1=-bget(rid[a],rid[c]),sum2=bget(lid[c],lid[b]),sum3=bget(lid[c],lid[c]),sum=sum1+sum2-sum3;
				//printf("p%d q%d -> %d [%d+%d-%d]\n",p,qid+1,sum,sum1,sum2,sum3);
				ans[qid]=(ll)ans[qid]*pw(p,sum)%MOD;
			}
			if(e[p][i].nodeid!=-1) {
				int at=e[p][i].nodeid;
				bmod(lid[at],+1);
				bmod(rid[at],-1);
			}
		}
		REPSZ(i,e[p]) {
			if(e[p][i].nodeid!=-1) {
				int at=e[p][i].nodeid;
				bmod(lid[at],-1);
				bmod(rid[at],+1);
			}
		}
	}
	REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}