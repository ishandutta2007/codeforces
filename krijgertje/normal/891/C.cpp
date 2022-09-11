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

const int MAXN=500000;
const int MAXM=500000;

typedef struct E { int a,b,c,id,aa,bb; } E;
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n,m;
E e[MAXM];
int emp[MAXM];

int par[MAXN],sz[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) { a=find(a),b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; }

int nq;
int qcnt,q[MAXM];

int qmark[MAXN],qcurmark;
int qmp[MAXN];

int qn,qm;
int qhead[MAXN],qnxt[2*MAXM],qto[2*MAXM];
bool qdone[MAXN];


bool qdfs(int at,int xpar) {
	qdone[at]=true;
	for(int x=qhead[at];x!=-1;x=qnxt[x]) {
		if(x==xpar) continue;
		int to=qto[x];
		if(qdone[to]) return false;
		if(!qdfs(to,x^1)) return false;
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b,e[i].id=i;
	sort(e,e+m); REP(i,n) par[i]=i,sz[i]=1;
	REP(i,m) emp[e[i].id]=i;
	for(int l=0,r=l;l<m;l=r) {
		while(r<m&&e[l].c==e[r].c) ++r;
		FOR(i,l,r) {
			int a=find(e[i].a),b=find(e[i].b);
			e[i].aa=find(e[i].a),e[i].bb=find(e[i].b);
		}
		FOR(i,l,r) unite(e[i].a,e[i].b);
	}
	//REP(i,m) printf("%d(%d): %d = %d-%d -> %d-%d\n",i,e[i].id,e[i].c,e[i].a,e[i].b,e[i].aa,e[i].bb);
	scanf("%d",&nq); REP(i,n) qmark[i]=-1; qcurmark=0;
	REP(qi,nq) {
		scanf("%d",&qcnt); REP(i,qcnt) scanf("%d",&q[i]),--q[i],q[i]=emp[q[i]];
		sort(q,q+qcnt);
		//printf("q:"); REP(i,qcnt) printf(" %d",q[i]); puts("");
		bool ok=true;
		for(int l=0,r=l;l<qcnt;l=r) {
			while(r<qcnt&&e[q[l]].c==e[q[r]].c) ++r;
			qn=qm=0;
			FOR(i,l,r) {
				int a=e[q[i]].aa,b=e[q[i]].bb;
				if(qmark[a]!=qcurmark) qmark[a]=qcurmark,qhead[qn]=-1,qmp[a]=qn++;
				if(qmark[b]!=qcurmark) qmark[b]=qcurmark,qhead[qn]=-1,qmp[b]=qn++;
				a=qmp[a],b=qmp[b];
				qnxt[2*qm+0]=qhead[a],qhead[a]=2*qm+0,qto[2*qm+0]=b;
				qnxt[2*qm+1]=qhead[b],qhead[b]=2*qm+1,qto[2*qm+1]=a;
				++qm;
			}
			//printf("\t%d:\n",e[q[l]].c); REP(i,qn) { printf("\t\t%d:",i); for(int x=qhead[i];x!=-1;x=qnxt[x]) printf(" %d",qto[x]); puts(""); }
			REP(i,qn) qdone[i]=false;
			REP(i,qn) if(!qdone[i]&&!qdfs(i,-1)) ok=false;
			++qcurmark;
		}
		printf("%s\n",ok?"YES":"NO");
	}
}

int main() {
	run();
	return 0;
}