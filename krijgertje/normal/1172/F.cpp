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
const int MAXQ=200000;
const int MAXS=4*MAXN;

int n,nq,mod;
int a[MAXN];
int ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

ll asum[MAXN+1];
vector<ll> sval[MAXS];

void smake(vector<ll> &a,ll val) { a.clear(); a.PB(LLONG_MIN); a.PB(mod-val); }
void spull(vector<ll> &c,const vector<ll> &a,const vector<ll> &b,ll adelta) {
	//printf("spull (%lld):",adelta); REPSZ(i,a) printf(" %lld",a[i]); printf(" |"); REPSZ(i,b) printf(" %lld",b[i]); puts("");
	int i,j; ll x,y; c.clear();
	assert(SZ(a)>=2&&SZ(b)>=2&&a[0]==LLONG_MIN&&b[0]==LLONG_MIN); c.PB(LLONG_MIN); if(a[1]<=b[1]-adelta) i=1,j=0,x=a[1],y=x+adelta-mod,c.PB(x); else i=0,j=1,y=b[1],x=y-adelta,c.PB(x);
	while(i+1<SZ(a)||j+1<SZ(b)) {
		//printf("\ti=%d j=%d x=%lld y=%lld\n",i,j,x,y);
		ll dx=LLONG_MAX; if(i+1<SZ(a)) dx=min(dx,a[i+1]-x); if(j+1<SZ(b)) dx=min(dx,b[j+1]-y);
		//printf("dx=%lld\n",dx);
		x+=dx,y+=dx; if(i+1<SZ(a)&&x>=a[i+1]) { ++i,y-=mod; if(y<b[j]) { --j; assert(j>=0&&y>=b[j]); } } else if(j+1<SZ(b)&&y>=b[j+1]) ++j; else assert(false);
		if(i+j==SZ(c)) c.PB(x);		
	}
	//printf("->"); REPSZ(i,c) printf(" %lld",c[i]); puts("");
}
void sinit(int x,int l,int r) {
	if(l==r) {
		smake(sval[x],a[l]);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(sval[x],sval[2*x+1],sval[2*x+2],asum[m+1]-asum[l]);
	}
}
ll scalc(int x,int l,int r,int L,int R,ll VAL) {
	if(L<=l&&r<=R) {
		int cnt=upper_bound(sval[x].begin(),sval[x].end(),VAL)-sval[x].begin()-1;
		return VAL+asum[r+1]-asum[l]-(ll)cnt*mod;
	} else {
		int m=l+(r-l)/2; ll ret=VAL;
		if(L<=m) ret=scalc(2*x+1,l,m,L,R,ret);
		if(m+1<=R) ret=scalc(2*x+2,m+1,r,L,R,ret);
		return ret;
	}
}

void solve() {
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	sinit(0,0,n-1);
	REP(i,nq) qans[i]=scalc(0,0,n-1,ql[i],qr[i],0);
}

void run() {
	scanf("%d%d%d",&n,&nq,&mod);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}


int main() {
	run();
	return 0;
}