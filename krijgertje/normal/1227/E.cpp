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
#include <chrono>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int h,w;
vector<string> g;
vector<string> startfire;

vector<vector<int>> cnt;

ll cntrect(int lx,int ly,int hx,int hy) {
	return cnt[hx+1][hy+1]-cnt[lx][hy+1]-cnt[hx+1][ly]+cnt[lx][ly];
}

vector<vector<int>> have;
vector<vector<int>> delta;

void markrect(int lx,int ly,int hx,int hy) {
	++delta[lx][ly],--delta[lx][hy+1];
	--delta[hx+1][ly],++delta[hx+1][hy+1];
	++have[lx][ly];
}

bool can(int t) {
	//printf("can(%d)\n",t);
	have=vector<vector<int>>(h,vector<int>(w+1,0));
	delta=vector<vector<int>>(h+1,vector<int>(w+1,0));
	startfire=vector<string>(h,string(w,'.'));
	REP(x,h) REP(y,w) {
		if(x-1>=0) delta[x][y]+=delta[x-1][y];
		if(y-1>=0) have[x][y]+=have[x][y-1];
		//printf("\t(%d,%d) have=%d\n",x,y,have[x][y]);
		have[x][y]+=delta[x][y];
		if(g[x][y]=='.') { assert(have[x][y]==0); continue; }
		int fx=x+t,fy=y+t;
		bool can=true;
		//printf("\ttest marking (%d,%d)\n",fx,fy);
		if(fx-t<0||fx+t>=h||fy-t<0||fy+t>=w) can=false;
		if(can) {
			ll actual=cntrect(fx-t,fy-t,fx+t,fy+t);
			ll expect=(ll)(2*t+1)*(2*t+1);
			//printf("\t->%lld vs %lld\n",actual,expect);
			if(actual!=expect) can=false;
		}
		if(!can) { if(have[x][y]==0) return false; else continue; }
		startfire[fx][fy]='X'; markrect(fx-t,fy-t,fx+t,fy+t);
	}
	return true;
}

int solve() {
	//REP(x,h) printf("%s\n",g[x].c_str());

	cnt=vector<vector<int>>(h+1,vector<int>(w+1,0));
	REP(x,h) REP(y,w) cnt[x+1][y+1]=cnt[x+1][y]+cnt[x][y+1]-cnt[x][y]+(g[x][y]=='X'?1:0);

	int lo=0,hi=(min(h,w)-1)/2+1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		if(can(mi)) lo=mi; else hi=mi;
	}
	//printf("lo=%d hi=%d\n",lo,hi);
	assert(can(lo));
	return lo;
}

void run() {
	scanf("%d%d",&h,&w);
	g=vector<string>(h); REP(x,h) cin>>g[x];
	int ans=solve();
	printf("%d\n",ans);
	REPSZ(x,startfire) printf("%s\n",startfire[x].c_str());
}

int main() {
	run();
	return 0;
}