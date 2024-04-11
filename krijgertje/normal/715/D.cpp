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

const int MAXRET=300;

ll want;
int h,w;
int sx[MAXRET],sy[MAXRET],tx[MAXRET],ty[MAXRET]; char d[MAXRET]; int nret;

void addedge(int x,int y,char c) {
	if(x>=0&&y>=0) sx[nret]=x,sy[nret]=y,tx[nret]=x+(c=='D'?1:0),ty[nret]=y+(c=='R'?1:0),d[nret]=c,++nret;
}

void go(ll x) {
	if(x==0) { h=w=3,nret=0; addedge(0,1,'D'); addedge(1,0,'R'); return; }
	go(x/16); x%=16;
	h+=3,w+=3;
	addedge(h-7,w-3,'D'); addedge(h-7,w-2,'D'); addedge(h-7,w-1,'D');
	addedge(h-3,w-7,'R'); addedge(h-2,w-7,'R'); addedge(h-1,w-7,'R');
	addedge(h-2,w-5,'D'); addedge(h-2,w-4,'D'); addedge(h-2,w-3,'D'); 
	addedge(h-5,w-2,'R'); addedge(h-4,w-2,'R'); addedge(h-3,w-2,'R'); 
	addedge(h-4,w-2,'D');
	if(x<9) addedge(h-4,w-6,'R'); else x-=9;
	if(x<7) addedge(h-6,w-4,'D'); else x-=7;
	if(x<4) addedge(h-3,w-6,'R'); else x-=4;
	if(x<2) addedge(h-6,w-3,'D'); else x-=2;
	if(x<1) addedge(h-2,w-6,'R'); else x-=1;
	assert(x==0);
}

void solve() {
	go(want); addedge(h-2,w-2,'D'); addedge(h-3,w-1,'D'); addedge(h-1,w-2,'R');
}

void check() {
	vector<vector<ll> > ways(h,vector<ll>(w,0));
	vector<vector<bool> > up(h,vector<bool>(w,true)); REP(y,w) up[0][y]=false; REP(i,nret) if(d[i]=='D') up[tx[i]][ty[i]]=false;
	vector<vector<bool> > lt(h,vector<bool>(w,true)); REP(x,h) lt[x][0]=false; REP(i,nret) if(d[i]=='R') lt[tx[i]][ty[i]]=false;
	REP(x,h) REP(y,w) if(x==0&&y==0) ways[x][y]=1; else { if(up[x][y]) ways[x][y]+=ways[x-1][y]; if(lt[x][y]) ways[x][y]+=ways[x][y-1]; }
	ll have=ways[h-1][w-1]; if(have!=want) printf("%lld vs %lld\n",have,want);
}

void run() {
	scanf("%lld",&want);
	solve();
	printf("%d %d\n",h,w); printf("%d\n",nret); REP(i,nret) printf("%d %d %d %d\n",sx[i]+1,sy[i]+1,tx[i]+1,ty[i]+1);
	//check();
}

void test() {
	for(want=0;want<=100000;++want) { solve(); check(); }
}


int main() {
	//test();
	run();
	return 0;
}