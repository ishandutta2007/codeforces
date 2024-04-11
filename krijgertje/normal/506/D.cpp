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

const int LIM=300;
const int MAXN=100000;
const int MAXM=100000;
const int MAXQ=100000;

typedef struct E { int a,b,c; } E;
bool operator<(const E &p,const E &q) { return p.c<q.c; }
typedef struct Q { int a,b,idx; ll id; } Q;
bool operator<(const Q &p,const Q &q) { return p.id<q.id; }

int n,m,nq;
E e[MAXM];
Q q[MAXQ];

int curcol;
int ufcol[MAXN];
int ufpar[MAXN];
int ufrnk[MAXN];
int ncomp;
int comp[2*LIM];

int nextra;
ll extra[((MAXM+LIM-1)/LIM)*(LIM*(LIM+1)/2)];
int ret[MAXQ];

int uffind(int x) {
	if(ufcol[x]!=curcol) { ufcol[x]=curcol; comp[ncomp++]=x; ufpar[x]=-1; ufrnk[x]=0; }
	return ufpar[x]==-1?x:(ufpar[x]=uffind(ufpar[x]));
}

void ufjoin(int x,int y) {
	x=uffind(x),y=uffind(y);
	if(x==y) return;
	if(ufrnk[x]<ufrnk[y]) swap(x,y);
	ufpar[y]=x; if(ufrnk[x]==ufrnk[y]) ++ufrnk[x];
}


void run() {
	// foreach color:
	//   o at most LIM edges
	//      * calc UF (total: m*lg(n))
	//      * foreach pair (2*LIM*(LIM-1) times): determine if they are connected (lg(LIM))
	//   o more than LIM edges (<=m/LIM)
	//      * calc UF (total: m*lg(n))
	//      * foreach query (Q times): determine if they are connected (lg(n))
	// sort queries (Q*lg(Q)) and connected pairs (LIM(LIM-1)/2*m/LIM=(LIM-1)/2*m) + determine how many times each pair occurs (two pointers)

	scanf("%d%d",&n,&m);
	REP(i,m) { scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c); --e[i].a,--e[i].b,--e[i].c; if(e[i].a>e[i].b) swap(e[i].a,e[i].b); }
	sort(e,e+m);
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d%d",&q[i].a,&q[i].b); --q[i].a,--q[i].b; if(q[i].a>q[i].b) swap(q[i].a,q[i].b); q[i].idx=i; q[i].id=(ll)q[i].a*n+q[i].b; }
	sort(q,q+nq);

	nextra=0; REP(i,n) ufcol[i]=-1; REP(i,nq) ret[i]=0;
	for(int i=0,j=0;i<m;i=j) {
		while(j<m&&e[i].c==e[j].c) ++j;
		ncomp=0; curcol=e[i].c; FOR(k,i,j) ufjoin(e[k].a,e[k].b);
		if(j-i<=LIM) {
			REP(k,ncomp) FOR(l,k+1,ncomp) {
				int u=comp[k],v=comp[l]; if(u>v) swap(u,v);
				if(uffind(u)!=uffind(v)) continue;
				ll id=(ll)u*n+v; extra[nextra++]=id;
			}
		} else {
			REP(k,nq) {
				if(uffind(q[k].a)!=uffind(q[k].b)) continue;
				ret[q[k].idx]++;
			}
		}
	}
	sort(extra,extra+nextra);
	for(int i=0,j=0,k=0;i<nextra;i=j) {
		while(j<nextra&&extra[i]==extra[j]) ++j;
		while(k<nq&&q[k].id<extra[i]) ++k;
		while(k<nq&&q[k].id==extra[i]) { ret[q[k].idx]+=j-i; ++k; }
	}
	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}