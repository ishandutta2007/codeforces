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

const int MAXN=10;

int n;
int a[2][MAXN+1]; int top[2],bot[2];

set<pair<ll,ll>> seen;

void run() {
	scanf("%d",&n);
	REP(i,2) { top[i]=0; scanf("%d",&bot[i]); REP(j,bot[i]) scanf("%d",&a[i][j]),--a[i][j]; }
	int cnt=0;
	while(top[0]!=bot[0]&&top[1]!=bot[1]) {
		//REP(i,2) { printf("%d: [%d,%d]",i,top[i],bot[i]); for(int j=top[i];j!=bot[i];j=j==n?0:j+1) printf(" %d",a[i][j]); puts(""); } puts("");
		ll cur[2]={1,1}; REP(i,2) for(int j=top[i];j!=bot[i];j=j==n?0:j+1) cur[i]=cur[i]*n+a[i][j]; if(seen.count(MP(cur[0],cur[1]))) { printf("-1\n"); return; } else seen.insert(MP(cur[0],cur[1]));

		int p=a[0][top[0]++]; if(top[0]>=n+1) top[0]-=n+1;
		int q=a[1][top[1]++]; if(top[1]>=n+1) top[1]-=n+1;
		int to=p>q?0:1; ++cnt;
		a[to][bot[to]++]=min(p,q); if(bot[to]>=n+1) bot[to]-=n+1;
		a[to][bot[to]++]=max(p,q); if(bot[to]>=n+1) bot[to]-=n+1;
	}
	//REP(i,2) { printf("%d: [%d,%d]",i,top[i],bot[i]); for(int j=top[i];j!=bot[i];j=j==n?0:j+1) printf(" %d",a[i][j]); puts(""); } puts("");
	printf("%d %d\n",cnt,top[0]==bot[0]?2:1);
}


int main() {
	run();
	return 0;
}