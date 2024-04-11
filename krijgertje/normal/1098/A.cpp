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

const int MAXN=100000;

int n;
int par[MAXN];
int sum[MAXN];

int dep[MAXN];
int minchildsum[MAXN];
int a[MAXN];

ll solve() {
	REP(i,n) dep[i]=par[i]==-1?0:dep[par[i]]+1;
	REP(i,n) assert((sum[i]==-1)==(dep[i]%2==1));
	REP(i,n) minchildsum[i]=INT_MAX; REP(i,n) if(par[i]!=-1&&sum[i]!=-1) minchildsum[par[i]]=min(minchildsum[par[i]],sum[i]);
	REP(i,n) if(par[i]==-1) a[i]=sum[i]; else if(sum[i]==-1) { if(minchildsum[i]==INT_MAX) a[i]=0; else if(minchildsum[i]<sum[par[i]]) return -1; else a[i]=minchildsum[i]-sum[par[i]]; sum[i]=sum[par[i]]+a[i]; } else { assert(sum[i]>=sum[par[i]]); a[i]=sum[i]-sum[par[i]]; }
	ll ret=0; REP(i,n) ret+=a[i]; return ret;
}

void run() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) scanf("%d",&sum[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}