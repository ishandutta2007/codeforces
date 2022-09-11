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

const int MOD=998244353;
const int MAXN=2000;
const int MAXS=4*MAXN;

int n;
int a[MAXN][MAXN];

pair<int,int> sval[MAXS];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=MP(1,0);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=MP(sval[2*x+1].first+sval[2*x+2].first,sval[2*x+1].second+sval[2*x+2].second);
	}
}
void skill(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=MP(0,0);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) skill(2*x+1,l,m,IDX); else skill(2*x+2,m+1,r,IDX);
		sval[x]=MP(sval[2*x+1].first+sval[2*x+2].first,sval[2*x+1].second+sval[2*x+2].second);
	}
}
void smark(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=MP(sval[x].second,sval[x].first);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) smark(2*x+1,l,m,IDX); else smark(2*x+2,m+1,r,IDX);
		sval[x]=MP(sval[2*x+1].first+sval[2*x+2].first,sval[2*x+1].second+sval[2*x+2].second);
	}
}
pair<int,int> sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2; pair<int,int> ret=MP(0,0);
		if(L<=m) { pair<int,int> cur=sget(2*x+1,l,m,L,R); ret=MP(ret.first+cur.first,ret.second+cur.second); }
		if(m+1<=R) { pair<int,int> cur=sget(2*x+2,m+1,r,L,R); ret=MP(ret.first+cur.first,ret.second+cur.second); }
		return ret;
	}
}

int dp[MAXN+1][MAXN+1]; // dp[i][j] = number of ways to order i elements, j of them having a forbidden position

bool seenincur[MAXN],seeninprev[MAXN];

int calcsmaller(int* cur) {
	int ret=0;
	sinit(0,0,n-1);
	REP(i,n) {
		skill(0,0,n-1,cur[i]);
		pair<int,int> cnt=sget(0,0,n-1,0,cur[i]);
		ret=(ret+(ll)cnt.first*dp[n-i-1][0])%MOD;
	}
	return ret;
}
int calcsmaller(int* cur,int* prev) {
	int ret=0;
	REP(i,n) seenincur[i]=seeninprev[i]=false;
	int numforbidden=n;
	sinit(0,0,n-1);
	REP(i,n) {
		skill(0,0,n-1,cur[i]);
		smark(0,0,n-1,prev[i]);
		pair<int,int> cnt=sget(0,0,n-1,0,cur[i]);
		if(!seenincur[prev[i]]&&prev[i]<=cur[i]) --cnt.second;
		//printf("\t%d: (%d,%d) numforbidden=%d\n",i,cnt.first,cnt.second,numforbidden);
		ret=(ret+(ll)cnt.first*dp[n-i-1][numforbidden-1-(!seenincur[prev[i]]?1:0)])%MOD;
		ret=(ret+(ll)cnt.second*dp[n-i-1][numforbidden-(!seenincur[prev[i]]?1:0)])%MOD;
		if(!seenincur[prev[i]]) --numforbidden;
		if(!seeninprev[cur[i]]) --numforbidden;
		seenincur[cur[i]]=true; seeninprev[prev[i]]=true;
	}
	return ret;
}

void init() {
	REPE(i,n) REPE(j,i) {
		if(j>=1) {
			dp[i][j]=((ll)(i-j)*dp[i-1][j-1]+(j>=2?(ll)(j-1)*dp[i-1][j-2]:0))%MOD;
		} else if(i>=1) {
			dp[i][j]=(ll)i*dp[i-1][j]%MOD;
		} else {
			dp[i][j]=1;
		}
	}
	//REPE(i,n) { printf("dp%d:",i); REPE(j,n) printf(" %d",dp[i][j]); puts(""); }
}

int solve() {
	init();
	int prod=1,ret=0;
	for(int i=n-1;i>=0;--i) {
		int cnt=i==0?calcsmaller(a[i]):calcsmaller(a[i],a[i-1]);
		//printf("%d: cnt=%d\n",i,cnt);
		ret=(ret+(ll)prod*cnt)%MOD;
		prod=(ll)prod*dp[n][n]%MOD;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]),--a[i][j];
	printf("%d\n",solve());
}

int bfcalcsmaller(int *cur,int *prev) {
	vector<int> next(n); REP(i,n) next[i]=i;
	int ret=0;
	do {
		bool smaller=false; REP(i,n) if(next[i]!=cur[i]) { if(next[i]<cur[i]) smaller=true; break; } if(!smaller) continue;
		if(prev!=NULL) { bool ok=true; REP(i,n) if(next[i]==prev[i]) { ok=false; break; } if(!ok) continue; }
		++ret;
	} while(next_permutation(next.begin(),next.end()));
	return ret;
}

void stress1() {
	n=10; init();
	REP(rep,1000) {
		vector<int> a(n),b(n); REP(i,n) a[i]=b[i]=i;
		while(true) { random_shuffle(a.begin(),a.end()); random_shuffle(b.begin(),b.end()); bool ok=true; REP(i,n) if(a[i]==b[i]) ok=false; if(ok) break; }
		bool useprev=false;
		int have=useprev?calcsmaller(a.data(),b.data()):calcsmaller(a.data());
		int want=bfcalcsmaller(a.data(),useprev?b.data():NULL);
		if(have==want) { printf("."); continue; }
		printf("err have=%d want=%d\n",have,want);
	}
}

int main() {
	run();
	//stress1();
	return 0;
}