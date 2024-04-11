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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll n;
ll xstartpos,ystartpos;
int xstartdir,ystartdir;

ll solve() {
	ll xpos=xstartpos,ypos=ystartpos;
	int xdir=xstartdir,ydir=ystartdir;
	ll len=n;
	auto norm=[&](ll &pos,int &dir) { if(pos==0) dir=+1; if(pos==len-1) dir=-1; };
	norm(xpos,xdir); norm(ypos,ydir);
	auto move=[&](ll steps) {
		xpos+=steps*xdir; if(xpos<=0) xpos=-xpos,xdir=+1; if(xpos>=len-1) xpos=(len-1)-(xpos-(len-1)),xdir=-1;
		ypos+=steps*ydir; if(ypos<=0) ypos=-ypos,ydir=+1; if(ypos>=len-1) ypos=(len-1)-(ypos-(len-1)),ydir=-1;
	};
	auto simulate=[&]() {
		//printf("simulate from (%lld,%d) and (%lld,%d)\n",xpos,xdir,ypos,ydir);
		if(xpos<ypos) {
			if(xdir==-1) move(xpos);
			if(ydir==+1) move((len-1)-ypos);
			move((ypos-xpos)/2);
			if(xpos!=ypos) { assert(ypos-xpos==1&&xdir==+1&&ydir==-1); ++xpos; norm(xpos,xdir); swap(xpos,ypos),swap(xdir,ydir); }
		}
		if(xpos>ypos) {
			if(xdir==+1) move((len-1)-xpos);
			if(ydir==-1) move(ypos);
			move((xpos-ypos)/2);
			if(xpos!=ypos) { assert(xpos-ypos==1&&xdir==-1&&ydir==+1); --xpos; norm(xpos,xdir); swap(xpos,ypos),swap(xdir,ydir); }
		}
		//printf("-> (%lld,%d) and (%lld,%d)\n",xpos,xdir,ypos,ydir);
	};
	simulate();
	if(xdir==ydir) {
		ll ret=xpos==0?len-1:xpos==len-1?0:xdir==+1?0:len-1;
		return ret;
	}
	ll first=xpos;
	assert(first!=0&&first!=len-1);
	xpos+=xdir; ypos+=ydir; norm(xpos,xdir); norm(ypos,ydir);
	assert(xpos!=first&&ypos!=first);
	--len; if(xpos>=first) --xpos; if(ypos>=first) --ypos;
	simulate();
	if(xdir==ydir) {
		ll ret=xpos==0?len-1:xpos==len-1?0:xdir==+1?0:len-1;
		if(ret>=first) ++ret;
		return ret;
	}
	ll second=xpos;
	++len; if(second>=first) ++second;
	assert(second!=0&&second!=len-1&&second!=first);
	if(first<second) {
		ll before=first,after=len-second-1;
		return before<=after?len-1:0;
	} else {
		ll before=second,after=len-first-1;
		return after<=before?0:len-1;
	}
}

void run() {
	scanf("%lld",&n);
	scanf("%lld%lld",&xstartpos,&ystartpos);
	char xstartdirstr[10],ystartdirstr[10];
	scanf("%s%s",xstartdirstr,ystartdirstr);
	if(strcmp(xstartdirstr,"left")==0) xstartdir=-1; else if(strcmp(xstartdirstr,"right")==0) xstartdir=+1; else assert(false);
	if(strcmp(ystartdirstr,"left")==0) ystartdir=-1; else if(strcmp(ystartdirstr,"right")==0) ystartdir=+1; else assert(false);
	printf("%lld\n",solve());
}

ll solvestupid() {
	ll xpos=xstartpos,ypos=ystartpos;
	int xdir=xstartdir,ydir=ystartdir;
	vector<bool> marked(n,false),dead(n,false);
	int nalive=n;
	while(nalive>1) {
		if(xpos==ypos) marked[xpos]=true;
		if(marked[xpos]&&ypos!=xpos) dead[xpos]=true,--nalive;
		while(true) {
			if(xpos==0) xdir=+1; if(xpos==n-1) xdir=-1;
			xpos+=xdir;
			if(!dead[xpos]) break;			
		}
		swap(xpos,ypos); swap(xdir,ydir);
	}
	ll ret=-1; REP(i,n) if(!dead[i]) { assert(ret==-1); ret=i; } assert(ret!=-1); return ret;
}

void stress() {
	for(n=2;n<=20;++n) for(xstartpos=0;xstartpos<n;++xstartpos) for(ystartpos=0;ystartpos<n;++ystartpos) for(xstartdir=-1;xstartdir<=+1;xstartdir+=2) for(ystartdir=-1;ystartdir<=+1;ystartdir+=2) {
		ll have=solve();
		ll want=solvestupid();
		if(have==want) { printf("."); continue; }
		printf("err have=%lld want=%lld\n",have,want);
		printf("%lld\n%lld %lld\n%s\n%s\n",n,xstartpos,ystartpos,xstartdir==-1?"left":"right",ystartdir==-1?"left":"right");
		return;
	}
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	//stress();
	return 0;
}