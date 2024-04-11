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
#include <chrono>
#include <random>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;
const ll XMIN=0LL;
const ll XMAX=1000000000000000000LL;
mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());

int n;
ll ymax;
ll lans[MAXN],rans[MAXN];

ll eval(int idx,ll x) {
	printf("? %d %lld\n",idx+1,x); fflush(stdout);
	ll y; scanf("%lld",&y); return y;
}

ll findx(int idx,ll y,ll lx,ll hx) {
	//printf("findx(%d,%lld,%lld..%lld)\n",idx,y,lx,hx);
	--lx;
	while(lx+1<hx) {
		ll mx=lx+(hx-lx)/2;
		ll cy=eval(idx,mx);
		if(cy<y) lx=mx; else hx=mx;
	}
	//printf("->%llx\n",hx);
	return hx;
}

void rec(const vector<int> &rem,ll lx,ll hx,ll ly,ll hy) {
	if(SZ(rem)==1) { lans[rem[0]]=lx,rans[rem[0]]=hx; return; }
	vector<int> cand=rem;
	int n1=SZ(rem)/2,n2=SZ(rem)-n1; assert((hy-ly)%(n1+n2)==0); ll mx=-1,my=ly+(hy-ly)/(n1+n2)*n1;
	vector<int> lft,rgt;
	while(true) {
		int cur=cand[rnd()%SZ(cand)];
		ll cx=findx(cur,my,lx,hx);
		vector<int> candbefore,candeq,candafter; candeq.PB(cur); REPSZ(i,cand) { int idx=cand[i]; if(idx==cur) continue; ll cy=eval(idx,cx); if(cy<my) candafter.PB(idx); else if(cy>my) candbefore.PB(idx); else candeq.PB(idx); }
		if(SZ(lft)+SZ(candbefore)>n1) { REPSZ(i,candafter) rgt.PB(candafter[i]); REPSZ(i,candeq) rgt.PB(candeq[i]); cand=candbefore; continue; }
		if(SZ(rgt)+SZ(candafter)>n2) { REPSZ(i,candbefore) lft.PB(candbefore[i]); REPSZ(i,candeq) lft.PB(candeq[i]); cand=candafter; continue; }
		//printf("ok lft=%d rgt=%d before=%d after=%d eq=%d n1=%d n2=%d\n",SZ(lft),SZ(rgt),SZ(candbefore),SZ(candafter),SZ(candeq),n1,n2);
		mx=cx; REPSZ(i,candbefore) lft.PB(candbefore[i]); REPSZ(i,candafter) rgt.PB(candafter[i]); REPSZ(i,candeq) if(SZ(lft)<n1) lft.PB(candeq[i]); else rgt.PB(candeq[i]);
		assert(SZ(lft)==n1&&SZ(rgt)==n2);
		break;
	}
	rec(lft,lx,mx,ly,my);
	rec(rgt,mx,hx,my,hy);
}

void solve() {
	vector<int> all(n); REP(i,n) all[i]=i;
	rec(all,XMIN,XMAX,0,ymax);

}

void run() {
	scanf("%d%lld",&n,&ymax);
	solve();
	printf("!\n"); REP(i,n) printf("%lld %lld\n",lans[i],rans[i]); fflush(stdout);
}

int main() {
	run();
	return 0;
}