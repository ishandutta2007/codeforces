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

int n;
int val[MAXN];
int par[MAXN];
int chead[MAXN],cnxt[MAXN];
int d[MAXN];
map<int,int> cnt;

void dfs(int at) {
	d[at]=par[at]==-1?0:d[par[at]]+1;
	for(int to=chead[at];to!=-1;to=cnxt[to]) dfs(to);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&val[i]);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) chead[i]=-1; for(int i=n-1;i>=0;--i) if(par[i]!=-1) cnxt[i]=chead[par[i]],chead[par[i]]=i;
	dfs(0);
	int fstleaf=-1; REP(i,n) if(chead[i]==-1) { fstleaf=i; break; } assert(fstleaf!=-1);
	cnt.clear();
	int sum=0,nsame=0,ndiff=0;
	REP(i,n) if(d[i]%2==d[fstleaf]%2) sum^=val[i],++nsame; else cnt[val[i]]++,++ndiff;
	ll ret=0;
	if(sum==0) ret+=(ll)nsame*(nsame-1)/2;
	if(sum==0) ret+=(ll)ndiff*(ndiff-1)/2;
	REP(i,n) if(d[i]%2==d[fstleaf]%2) ret+=cnt[sum^val[i]];
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}