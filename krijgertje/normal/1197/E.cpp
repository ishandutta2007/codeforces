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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MOD=1000000007;
struct Doll { int in,out; };
bool operator<(const Doll &a,const Doll &b) { return a.out<b.out; }
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;
Doll doll[MAXN];

int dp[MAXN+1],dpways[MAXN+1]; // dp[i] = maximum savings of first i dolls, which is possible in dpways[i] ways

int solve() {
	sort(doll,doll+n);
	//printf("doll:"); REP(i,n) printf(" (%d,%d)",doll[i].in,doll[i].out); puts("");
	int mxin=INT_MIN; REP(i,n) mxin=max(mxin,doll[i].in);
	int mnloss=INT_MAX,mnways=0;
	dp[0]=0,dpways[0]=1;
	REP(i,n) {
		int lo=-1,hi=i; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(doll[mi].out<=doll[i].in) lo=mi; else hi=mi; }
		dp[i+1]=dp[i]; dpways[i+1]=dpways[i];
		int csave=dp[lo+1]+doll[i].out-doll[i].in;
		if(csave>dp[i+1]) dp[i+1]=csave,dpways[i+1]=0;
		if(csave==dp[i+1]) inc(dpways[i+1],dpways[lo+1]);
		int closs=doll[i].in-dp[lo+1];
		if(doll[i].out>mxin) {
			if(closs<mnloss) mnloss=closs,mnways=0;
			if(closs==mnloss) inc(mnways,dpways[lo+1]);
		}
		//printf("use doll %d: csave=%d closs=%d\n",i,csave,closs);
	}
	return mnways;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&doll[i].out,&doll[i].in);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}