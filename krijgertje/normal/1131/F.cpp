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

const int MAXN=150000;

int n;
int a[MAXN-1],b[MAXN-1];
int ans[MAXN];

int par[MAXN],sz[MAXN],dist[MAXN];

int find(int x) { if(par[x]==x) return x; int ret=find(par[x]); dist[x]+=dist[par[x]]; return par[x]=ret; }
bool unite(int x,int y) { x=find(x),y=find(y); if(x==y) return false; if(sz[x]<sz[y]) swap(x,y); par[y]=x,dist[y]=sz[x],sz[x]+=sz[y]; return true; }


void solve() {
	REP(i,n) par[i]=i,sz[i]=1,dist[i]=0;
	REP(i,n-1) {
		assert(unite(a[i],b[i]));
		//REP(j,n) find(j);
		//printf("after %d-%d:",a[i],b[i]); REP(j,n) printf(" (%d,%d)",par[j],dist[j]); puts("");
	}
	REP(i,n) find(i);
	REP(i,n) ans[dist[i]]=i;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}