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

const int MAXN=200000;

int n,nbox,boxsz;
int a[MAXN];

ll sum[MAXN+1];
int nxt[MAXN];
int need[MAXN+1];

int solve() {
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+a[i];
	int to=0;
	REP(at,n) {
		while(to<n&&sum[to+1]-sum[at]<=boxsz) ++to;
		nxt[at]=to;
	}
	//printf("nxt:"); REP(i,n) printf(" %d",nxt[i]); puts("");
	need[n]=0; for(int i=n-1;i>=0;--i) need[i]=1+need[nxt[i]];
	//printf("need:"); REPE(i,n) printf(" %d",need[i]); puts("");
	REPE(i,n) if(need[i]<=nbox) return n-i; return 0;
}

void run() {
	scanf("%d%d%d",&n,&nbox,&boxsz);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}