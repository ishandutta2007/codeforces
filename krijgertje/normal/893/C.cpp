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
const int MAXM=100000;

int n,m;
int cost[MAXN];
int a[MAXM],b[MAXM];

int par[MAXN],sz[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) { a=find(a),b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; }

int best[MAXN];

void run() {
	scanf("%d%d",&n,&m); REP(i,n) scanf("%d",&cost[i]); REP(i,m) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];

	REP(i,n) par[i]=i,sz[i]=1; REP(i,m) unite(a[i],b[i]);
	REP(i,n) if(find(i)==i) best[i]=INT_MAX; else best[i]=-1;
	REP(i,n) { int j=find(i); best[j]=min(best[j],cost[i]); }
	ll ret=0; REP(i,n) if(best[i]!=-1) ret+=best[i]; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}