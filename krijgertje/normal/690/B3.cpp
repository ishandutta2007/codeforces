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
const int MAXQ=200000;
const int MAXP=MAXQ;
const int DX[]={0,+1,0,-1},DY[]={+1,0,-1,0};
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const int operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
bool ok(const P &a,const P &b,const P &c) { return ((b-a)^(c-a))<0; }

int n;

P q[MAXQ]; int nq;

P p[MAXP]; int np;

P h[2*MAXP]; int nh;

int mx[MAXN+1],mn[MAXN+1];

bool iszero(int x,int y) { if(y<0||y>=n||mn[y]>mx[y]) return true; return x<mn[y]||x>mx[y]; }
void solve() {
	REP(i,n) mx[i]=INT_MIN,mn[i]=INT_MAX;
	REP(i,nq) { int x=q[i].x,y=q[i].y; if(x<mn[y]) mn[y]=x; if(x>mx[y]) mx[y]=x; }
	np=0;
	REP(i,nq) {
		REP(k,4) {
			int kk=(k+1)%4;
			if(iszero(q[i].x+DX[k],q[i].y+DY[k])&&iszero(q[i].x+DX[kk],q[i].y+DY[kk])) p[np++]=P(q[i].x+k/2,q[i].y+((k==1||k==2)?1:0));
		}
	}
	//nh=np; REP(i,np) h[i]=p[i];
	sort(p,p+np);
	nh=0;
	REP(i,np) {
		while(nh>=2&&!ok(h[nh-2],h[nh-1],p[i])) --nh;
		h[nh++]=p[i];
	}
	int th=nh;
	for(int i=np-1;i>=0;--i) {
		while(nh-th>=1&&!ok(h[nh-2],h[nh-1],p[i])) --nh;
		h[nh++]=p[i];
	}
	--nh;
	printf("%d\n",nh);
	REP(i,nh) printf("%d %d\n",h[i].x,h[i].y);
}

void run() {
	while(scanf("%d%d",&n,&nq)==2) {
		if(n==0&&nq==0) break;
		REP(i,nq) scanf("%d%d",&q[i].x,&q[i].y),--q[i].x,--q[i].y;
		solve();
	}
}

int main() {
	run();
	return 0;
}