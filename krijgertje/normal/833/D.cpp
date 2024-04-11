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
const int MAXM=MAXN-1;
const int MAXBIT=8*MAXN+1;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }

typedef struct BIT {
	char c;
	int prd[MAXBIT+1];
	int cnt[MAXBIT+1];
	int off,mlt;

	BIT() { off=4*MAXN; mlt=1; REPE(i,MAXBIT) prd[i]=1,cnt[i]=0; }

	void changemlt(int by) { /*printf("%c: changemlt(%d)\n",c,by);*/ mlt=(ll)mlt*by%MOD; }
	void changeoff(int by) { /*printf("%c: changeoff(%d)\n",c,by);*/ off-=by; }
	void add(int key,int by,int sgn) {
		key+=off; by=sgn==+1?(ll)by*inv(mlt)%MOD:(ll)inv(by)*mlt%MOD; //printf("%c: add effective key=%d [%d]\n",c,key-4*MAXN,sgn);
		while(key<=MAXBIT) { prd[key]=(ll)prd[key]*by%MOD; cnt[key]+=sgn; key+=key&-key; }
	}
	pair<int,int> query(int key) {
		key+=off; //printf("%c: query effective key=%d\n",c,key-4*MAXN);
		pair<int,int> ret=MP(1,0);
		while(key>0) { ret.first=(ll)ret.first*prd[key]%MOD; ret.second+=cnt[key]; key-=key&-key; }
		ret.first=(ll)ret.first*pw(mlt,ret.second)%MOD;
		return ret;
	}
} BIT;

BIT pos; // store b'-2*a', query 2*a-b
BIT neg; // store 2*b'-a', query a-2*b-1

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gval[MAXM],gcol[MAXM];
int sz[MAXN],heavy[MAXN],eheavy[MAXN];

void dfs(int at,int par) {
	sz[at]=1,heavy[at]=-1,eheavy[at]=-1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs(to,at);
		sz[at]+=sz[to];
		if(heavy[at]==-1||sz[to]>sz[heavy[at]]) heavy[at]=to,eheavy[at]=x>>1;
	}
}
void addpath(int a,int b,int mlt,int sgn) {
	//printf("addpath(%d,%d,%d,%d)\n",a,b,mlt,sgn);
	pos.add(b-2*a,mlt,sgn);
	neg.add(2*b-a,mlt,sgn);
}
int calcpath(int a,int b,int mlt) {
	pair<int,int> posres=pos.query(2*a-b);
	pair<int,int> negres=neg.query(a-2*b-1);
	int ret=(ll)posres.first*pw(mlt,posres.second)%MOD*inv((ll)negres.first*pw(mlt,negres.second)%MOD)%MOD;
	//printf("calcpath(%d,%d,%d)=%d [%d,%d] [%d,%d]\n",a,b,mlt,ret,posres.first,posres.second,negres.first,negres.second);
	return ret;
}
int calctree(int at,int par,int a,int b,int mlt) {
	int ret=calcpath(a,b,mlt);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		ret=(ll)ret*calctree(to,at,a+(gcol[x>>1]==0?1:0),b+(gcol[x>>1]==1?1:0),(ll)mlt*gval[x>>1]%MOD)%MOD;
	}
	return ret;
}
void addtree(int at,int par,int a,int b,int mlt) {
	addpath(a,b,mlt,+1);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		addtree(to,at,a+(gcol[x>>1]==0?1:0),b+(gcol[x>>1]==1?1:0),(ll)mlt*gval[x>>1]%MOD);
	}
}
void remtree(int at,int par,int a,int b,int mlt) {
	addpath(a,b,mlt,-1);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		remtree(to,at,a+(gcol[x>>1]==0?1:0),b+(gcol[x>>1]==1?1:0),(ll)mlt*gval[x>>1]%MOD);
	}
}

int solve(int at,int par,bool keep) {
	//printf("solve(%d,%d,%c)\n",at+1,par+1,keep?'K':'-');
	if(heavy[at]==-1) {
		if(keep) addpath(0,0,1,+1);
		return 1;
	}
	int ret=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par||to==heavy[at]) continue;
		ret=(ll)ret*solve(to,at,false)%MOD;
	}
	{
		int to=heavy[at],eidx=eheavy[at];
		ret=(ll)ret*solve(to,at,true)%MOD;
		if(gcol[eidx]==0) pos.changeoff(-2),neg.changeoff(-1); else pos.changeoff(+1),neg.changeoff(+2);
		pos.changemlt(gval[eidx]),neg.changemlt(gval[eidx]);
	}
	//printf("solvelight(%d,%d,%c)\n",at+1,par+1,keep?'K':'-');
	ret=(ll)ret*calcpath(0,0,1)%MOD;
	addpath(0,0,1,+1);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par||to==heavy[at]) continue;
		ret=(ll)ret*calctree(to,at,gcol[x>>1]==0?1:0,gcol[x>>1]==1?1:0,gval[x>>1])%MOD;
		addtree(to,at,gcol[x>>1]==0?1:0,gcol[x>>1]==1?1:0,gval[x>>1]);
	}
	if(!keep) {
		//printf("remtree(%d,%d)\n",at+1,par+1);
		//FORE(a,-10,+10) { pair<int,int> posres=pos.query(a),negres=neg.query(a); printf("%d: %d/%d %d/%d\n",a,posres.first,posres.second,negres.first,negres.second); } printf("%d %d\n",pos.mlt,neg.mlt);
		remtree(at,par,0,0,1);
	}
	return ret;
}


void run() {
	pos.c='+',neg.c='-';
	scanf("%d",&n); REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d%d",&a,&b,&gval[i],&gcol[i]); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	dfs(0,-1);
	//REP(i,n) { printf("%d:",i+1); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]+1); printf(" -> %d\n",heavy[i]+1); }
	int ret=solve(0,-1,false);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}