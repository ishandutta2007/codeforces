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

const int MAXN=1000;
const int MAXM=MAXN*(MAXN-1)/2;
const int MAXLOGM=19;
typedef struct E { int a,b,c; } E;
typedef struct IMP { int *arr; int n; } IMP;

int sz[MAXN],par[MAXN]; bool same[MAXN];

int lst[MAXN],nlst;
void reset() {
	REP(i,nlst) par[lst[i]]=-1; nlst=0;
}
void find(int &a,bool &asame) {
	if(par[a]==-1) par[a]=a,sz[a]=1,same[a]=true,lst[nlst++]=a;
	//printf("\t\t%d %d %c\n",a,par[a],same[a]?'=':'x');
	if(par[a]!=a) find(par[a],same[a]);
	if(!same[a]) asame=!asame; a=par[a];
}
int unite(int a,int b) {
	//printf("\tuniting %d and %d\n",a,b);
	bool asame=true; find(a,asame);
	bool bsame=true; find(b,bsame);
	//printf("\t\t-> %d and %d (%c,%c)\n",a,b,asame?'=':'x',bsame?'=':'x');
	if(a==b) return asame==bsame?-1:0;
	if(sz[a]<sz[b]) swap(a,b),swap(asame,bsame);
	sz[a]+=sz[b]; par[b]=a; same[b]=asame^bsame; return 1;
}

int n,m,nq;
E e[MAXM];

int allimp[MAXLOGM*MAXM+2*MAXLOGM*MAXN],nallimp;
IMP imp[2*MAXM];


int smerge(IMP &a,IMP &b,IMP &c) {
	//printf("merging %d with %d (%d,%d)\n",&a-imp,&b-imp,a.n,b.n);
	c.arr=allimp+nallimp; c.n=0;
	int i=0,j=0; reset();
	while(i<a.n||j<b.n) {
		if(j>=b.n||i<a.n&&e[a.arr[i]].c>=e[b.arr[j]].c) {
			int res=unite(e[a.arr[i]].a,e[a.arr[i]].b);
			if(res!=0) c.arr[c.n++]=a.arr[i],++nallimp; if(res==-1) return e[a.arr[i]].c;
			++i;
		} else {
			int res=unite(e[b.arr[j]].a,e[b.arr[j]].b);
			if(res!=0) c.arr[c.n++]=b.arr[j],++nallimp; if(res==-1) return e[b.arr[j]].c;
			++j;
		}
	}
	return -1;
}

void sinit() {
	nallimp=0;
	REP(i,m) { imp[m+i].arr=allimp+nallimp; imp[m+i].n=0; imp[m+i].arr[imp[m+i].n++]=i,++nallimp; }
	for(int i=m-1;i>=1;--i) {
		smerge(imp[2*i+0],imp[2*i+1],imp[i]);
	}
}
int sget(int l,int r) {
	int ret=-1,oallimp=nallimp,at=0;
	IMP cur[2]; cur[at].arr=allimp+nallimp; cur[at].n=0;
	for(l+=m,r+=m;l<r;l>>=1,r>>=1) {
		//printf("%d %d\n",l,r);
		if(l&1) ret=smerge(cur[at],imp[l++],cur[1-at]),at=1-at;
		if(r&1) ret=smerge(cur[at],imp[--r],cur[1-at]),at=1-at;
	}
	nallimp=oallimp; return ret;
}


void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b;

	nlst=0; REP(i,n) par[i]=-1;
	sinit();
	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l;
		printf("%d\n",sget(l,r));
	}
}

int main() {
	run();
	return 0;
}