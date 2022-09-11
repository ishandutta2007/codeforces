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

const int MAXN=200000;
const int MAXS=4*MAXN;

int n; ll budget;
int cost[MAXN];

ll ssum[MAXS];
int scnt[MAXS];

void spull(int x) {
	ssum[x]=ssum[2*x+1]+ssum[2*x+2];
	scnt[x]=scnt[2*x+1]+scnt[2*x+2];
}

void sinit(int x,int l,int r) {
	if(l==r) {
		ssum[x]=cost[l]; scnt[x]=1;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
}

void supdate(int x,int l,int r,ll have) {
	//printf("supdate(%d,%d..%d,%lld) [%lld,%d]\n",x,l,r,have,ssum[x],scnt[x]);
	if(have>=ssum[x]) return;
	if(l==r) {
		ssum[x]=scnt[x]=0;
	} else {
		int m=l+(r-l)/2;
		supdate(2*x+1,l,m,have);
		have-=ssum[2*x+1];
		supdate(2*x+2,m+1,r,have);
		spull(x);
	}
}

ll solve() {
	sinit(0,0,n-1);
	ll ret=0,rem=budget;
	while(scnt[0]>0&&rem>0) {
		//printf("rem=%lld cnt=%d sum=%lld\n",rem,scnt[0],ssum[0]);
		ll whole=rem/ssum[0];
		ret+=scnt[0]*whole;
		rem-=ssum[0]*whole;
		supdate(0,0,n-1,rem);
	}
	return ret;
}

void run() {
	scanf("%d%lld",&n,&budget);
	REP(i,n) scanf("%d",&cost[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}