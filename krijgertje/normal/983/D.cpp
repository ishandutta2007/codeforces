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
const int MAXYY=2*MAXN-1;
const int MAXS=4*MAXYY;
struct R { int lx,ly,hx,hy; };

int n;
R r[MAXN];

int xx[2*MAXN],nxx;
int yy[2*MAXN],nyy;

set<int> scol[MAXS];
int smxcol[MAXS]; // smxcol[z] is current largest color at this node
int smnsubtreecol[MAXS]; // smnsubtreecol[z] is current smallest color that is visible in subtree (considering only the subtree)
int smnancestorcol[MAXS]; // all colors visible in subtree (considering only the subtree) that are greater than smnancestorcol[z] could have been seen at some point

bool seen[MAXN+1];

void spull(int z,bool isleaf) {
	smxcol[z]=SZ(scol[z])==0?-1:*prev(scol[z].end());
	if(isleaf) {
		smnsubtreecol[z]=smxcol[z];
	} else {
		smnsubtreecol[z]=max(smxcol[z],min(smnsubtreecol[2*z+1],smnsubtreecol[2*z+2]));
	}
}
void spush(int z,bool isleaf) {
	if(smxcol[z]!=-1&&smxcol[z]==smnsubtreecol[z]&&smxcol[z]>smnancestorcol[z]) {
		//printf("mark %d as seen\n",smxcol[z]);
		seen[smxcol[z]]=true;
	}
	if(!isleaf) {
		smnancestorcol[2*z+1]=min(smnancestorcol[2*z+1],max(smnancestorcol[z],smxcol[z]));
		smnancestorcol[2*z+2]=min(smnancestorcol[2*z+2],max(smnancestorcol[z],smxcol[z]));
	}
}

void sinit(int z,int l,int r) {
	scol[z].clear();
	smxcol[z]=smnsubtreecol[z]=smnancestorcol[z]=-1;
	if(l!=r) {
		int m=l+(r-l)/2;
		sinit(2*z+1,l,m);
		sinit(2*z+2,m+1,r);
	}
}
void saddcol(int z,int l,int r,int L,int R,int COL,int ANCCOL) {
	spush(z,l==r);
	smnancestorcol[z]=ANCCOL;
	if(L<=l&&r<=R) {
		scol[z].insert(COL);
	} else {
		int m=l+(r-l)/2;
		if(L<=m) saddcol(2*z+1,l,m,L,R,COL,max(smxcol[z],ANCCOL));
		if(m+1<=R) saddcol(2*z+2,m+1,r,L,R,COL,max(smxcol[z],ANCCOL));
	}
	spull(z,l==r);
}
void sremcol(int z,int l,int r,int L,int R,int COL,int ANCCOL) {
	spush(z,l==r);
	smnancestorcol[z]=ANCCOL;
	if(L<=l&&r<=R) {
		scol[z].erase(COL);
	} else {
		int m=l+(r-l)/2;
		if(L<=m) sremcol(2*z+1,l,m,L,R,COL,max(smxcol[z],ANCCOL));
		if(m+1<=R) sremcol(2*z+2,m+1,r,L,R,COL,max(smxcol[z],ANCCOL));
	}
	spull(z,l==r);
}

struct E { int x,by,id; E() {} E(int x,int by,int id):x(x),by(by),id(id) {} };
bool operator<(const E &a,const E &b) { if(a.x!=b.x) return a.x<b.x; if(a.by!=b.by) return a.by>b.by; if(a.by==+1) return a.id>b.id; else return a.id<b.id; }

E e[2*MAXN]; int ne;

int solve() {
	nxx=0; REP(i,n) xx[nxx++]=r[i].lx,xx[nxx++]=r[i].hx; sort(xx,xx+nxx); nxx=unique(xx,xx+nxx)-xx; REP(i,n) r[i].lx=lower_bound(xx,xx+nxx,r[i].lx)-xx,r[i].hx=lower_bound(xx,xx+nxx,r[i].hx)-xx;
	nyy=0; REP(i,n) yy[nyy++]=r[i].ly,yy[nyy++]=r[i].hy; sort(yy,yy+nyy); nyy=unique(yy,yy+nyy)-yy; REP(i,n) r[i].ly=lower_bound(yy,yy+nyy,r[i].ly)-yy,r[i].hy=lower_bound(yy,yy+nyy,r[i].hy)-yy;

	sinit(0,0,nyy-2);
	ne=0; REP(i,n) e[ne++]=E(r[i].lx,+1,i),e[ne++]=E(r[i].hx,-1,i);
	REPE(i,n) seen[i]=false; seen[0]=true;
	sort(e,e+ne);
	REP(ei,ne) {
		int id=e[ei].id,by=e[ei].by;
		//printf("event: %s rect %d\n",by==+1?"add":"rem",id+1);
		if(by==+1) {
			saddcol(0,0,nyy-2,r[id].ly,r[id].hy-1,id+1,-1);
		} else {
			sremcol(0,0,nyy-2,r[id].ly,r[id].hy-1,id+1,-1);
		}
	}
	int ret=0; REPE(i,n) if(seen[i]) ++ret; return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d%d",&r[i].lx,&r[i].ly,&r[i].hx,&r[i].hy);
	printf("%d\n",solve());
}

R oldr[MAXN];
int bfsolve(int rng) {
	vector<vector<int> > col(rng,vector<int>(rng,0));
	REP(i,n) FOR(x,oldr[i].lx,oldr[i].hx) FOR(y,oldr[i].ly,oldr[i].hy) col[x][y]=i+1;
	vector<bool> seen(n+1,false); seen[0]=true; REP(x,rng) REP(y,rng) seen[col[x][y]]=true;
	int ret=0; REPSZ(i,seen) if(seen[i]) ++ret; return ret;
}

void stress() {
	REP(rep,10000) {
		n=10; int rng=10;
		REP(i,n) {
			r[i].lx=rand()%rng,r[i].hx=rand()%rng; if(r[i].lx>r[i].hx) swap(r[i].lx,r[i].hx); ++r[i].hx; oldr[i].lx=r[i].lx; oldr[i].hx=r[i].hx;
			r[i].ly=rand()%rng,r[i].hy=rand()%rng; if(r[i].ly>r[i].hy) swap(r[i].ly,r[i].hy); ++r[i].hy; oldr[i].ly=r[i].ly; oldr[i].hy=r[i].hy;
		}
		int have=solve();
		int want=bfsolve(rng);
		if(have==want) { printf("."); continue; }
		printf("err have=%d want=%d\n",have,want);
		printf("%d\n",n); REP(i,n) printf("%d %d %d %d\n",oldr[i].lx,oldr[i].ly,oldr[i].hx,oldr[i].hy);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}