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

const int MAXN=1000000;
const int MAXS=4*MAXN;

int n,len;
int a[MAXN];
int ans[MAXN];

int par[MAXN];
int stck[MAXN],nstck;
vector<int> ch[MAXN];

int smx[MAXS],slazy[MAXS];

void sapply(int x,int val) { slazy[x]+=val; if(smx[x]!=INT_MIN) smx[x]+=val; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { smx[x]=max(smx[2*x+1],smx[2*x+2]); }

void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		smx[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2;
		spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}
void skill(int x,int l,int r,int IDX) {
	if(l==r) {
		smx[x]=INT_MIN;
	} else {
		int m=l+(r-l)/2;
		spush(x);
		if(IDX<=m) skill(2*x+1,l,m,IDX); else skill(2*x+2,m+1,r,IDX);
		spull(x);
	}
}


int lpreidx[MAXN],rpreidx[MAXN],preidx[MAXN],npre;
void dfspre(int at) {
	preidx[at]=lpreidx[at]=npre++;
	REPSZ(i,ch[at]) { int to=ch[at][i]; dfspre(to); }
	rpreidx[at]=npre-1;
}

void revive(int x) {
	smod(0,0,n-1,lpreidx[x],rpreidx[x],+1);
}
void kill(int x) {
	skill(0,0,n-1,preidx[x]);
}


void solve() {
	nstck=0;
	for(int i=n-1;i>=0;--i) {
		while(nstck>0&&a[stck[nstck-1]]<=a[i]) --nstck;
		par[i]=nstck==0?-1:stck[nstck-1];
		stck[nstck++]=i;
	}
	REP(i,n) ch[i].clear(); REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	npre=0; REP(i,n) if(par[i]==-1) dfspre(i);
	//printf("par:"); REP(i,n) printf(" %d",par[i]); puts("");


	REP(i,len) revive(i);
	REPE(i,n-len) {
		ans[i]=smx[0];
		if(i!=n-len) revive(i+len),kill(i);
	}
}

void run() {
	scanf("%d%d",&n,&len);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	REPE(i,n-len) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}