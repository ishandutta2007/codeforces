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
const int MAXCOST=100;

int n,tmax;
int cost[MAXN];
int ans[MAXN];

int mxcost;
int cnt[MAXCOST+1];

void solve() {
	mxcost=cost[0]; FOR(i,1,n) mxcost=max(mxcost,cost[i]); assert(mxcost<=tmax);
	FORE(j,1,mxcost) cnt[j]=0;
	REP(i,n) {
		int rem=tmax; assert(rem>=cost[i]);
		int keep=0; FORE(j,1,mxcost) { int cur=min(cnt[j],(rem-cost[i])/j); keep+=cur; rem-=cur*j; }
		assert(rem>=cost[i]);
		ans[i]=i-keep;
		++cnt[cost[i]];
	}
}



void run() {
	scanf("%d%d",&n,&tmax);
	REP(i,n) scanf("%d",&cost[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}