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

const int MAXN=500;
const int MAXP=(MAXN+1)*(MAXN+1);
const int DX[]={0,+1,0,-1},DY[]={+1,0,-1,0};
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const int operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
bool ok(const P &a,const P &b,const P &c) { return ((b-a)^(c-a))<0; }

int n;
char g[MAXN][MAXN+1];

P p[MAXP]; int np;

P h[2*MAXP]; int nh;

bool iszero(int x,int y) { return 0<=x&&x<n&&0<=y&&y<n&&g[x][y]=='0'; }
void solve() {
	np=0;
	REP(x,n) REP(y,n) if(g[x][y]=='1') {
		REP(k,4) {
			int kk=(k+1)%4;
			if(iszero(x+DX[k],y+DY[k])&&iszero(x+DX[kk],y+DY[kk])) p[np++]=P(y+((k==1||k==2)?1:0),n-(x+k/2));
		}
	}
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
	//reverse(h,h+nh);
	printf("%d\n",nh);
	REP(i,nh) printf("%d %d\n",h[i].x,h[i].y);
}

void run() {
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		REP(x,n) scanf("%s",g[x]);
		solve();
	}
}

int main() {
	run();
	return 0;
}