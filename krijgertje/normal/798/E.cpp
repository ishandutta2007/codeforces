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

int n;
int a[MAXN]; // if a[i]==-1 then p[i] is greater than p[j] for j unmarked, otherwise p[i]<p[a[i]] and p[i] is greater than p[j] for j unmarked and j<a[i]
int b[MAXN]; // if b[i]==-1 then i is never marked, otherwise i is marked by position b[i]

int top[MAXN],ntop;
bool done[MAXN];
int ret[MAXN];

int sval[4*MAXN];
int sbest(int p,int q) { int ret=p==-1?q:q==-1?p:b[p]==-1?p:b[q]==-1?q:b[p]>b[q]?p:q; /*printf("best(%d,%d)=%d\n",p,q,ret);*/ return ret; }
void sinit(int x,int l,int r) {
	//printf("sinit(%d,%d,%d)\n",x,l,r);
	if(l==r) { sval[x]=l; return; }
	int m=l+(r-l)/2;
	sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
	sval[x]=sbest(sval[2*x+1],sval[2*x+2]);
}
int sfind(int x,int l,int r,int L,int R) {
	//printf("sfind(%d,%d,%d,%d,%d)\n",x,l,r,L,R);
	if(L<=l&&r<=R) return sval[x];
	int m=l+(r-l)/2;
	int p=L<=m?sfind(2*x+1,l,m,L,R):-1;
	int q=m+1<=R?sfind(2*x+2,m+1,r,L,R):-1;
	return sbest(p,q);
}
void skill(int x,int l,int r,int IDX) {
	//printf("skill(%d,%d,%d,%d)\n",x,l,r,IDX);
	if(l==r) { sval[x]=-1; return; }
	int m=l+(r-l)/2;
	if(IDX<=m) skill(2*x+1,l,m,IDX); else skill(2*x+2,m+1,r,IDX);
	sval[x]=sbest(sval[2*x+1],sval[2*x+2]);
}

// edges: i->j iff j==b[i] || i!=j&&j<a[i]&&b[j]>i
int findedge(int i) {
	if(b[i]!=-1&&!done[b[i]]) return b[i];
	vector<int> bounds; bounds.PB(-1); bounds.PB(a[i]==-1?n:a[i]); if(-1<i&&(a[i]==-1||i<a[i])) bounds.PB(i); sort(bounds.begin(),bounds.end());
	FORSZ(x,1,bounds) {
		int l=bounds[x-1]+1,r=bounds[x]-1; if(l>r) continue;
		int ret=sfind(0,0,n-1,l,r);
		//printf("%d: %d..%d = %d (%d)\n",i,l,r,ret,ret==-1?-2:b[ret]);
		if(ret!=-1&&(b[ret]==-1||b[ret]>i)) return ret;
	}
	return -1;
}

void dfs(int at) {
	assert(!done[at]); done[at]=true; skill(0,0,n-1,at);
	while(true) {
		int to=findedge(at);
		//printf("%d -> %d\n",at,to);
		if(to==-1) break; else dfs(to);
	}
	top[ntop++]=at;
}

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d",&a[i]); if(a[i]!=-1) --a[i]; }
	REP(i,n) b[i]=-1; REP(i,n) if(a[i]!=-1) b[a[i]]=i;

	//printf("a:"); REP(i,n) printf(" %2d",a[i]); puts("");
	//printf("b:"); REP(i,n) printf(" %2d",b[i]); puts("");

	REP(i,n) done[i]=false; ntop=0; sinit(0,0,n-1);
	REP(i,n) if(!done[i]) dfs(i);
	REP(i,n) ret[top[i]]=i;
	REP(i,ntop) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}