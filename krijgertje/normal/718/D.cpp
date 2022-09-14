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
const int MAXM=MAXN-1;

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],deg[MAXN];
int sz[MAXN],mxcsz[MAXN];

void dfs1(int at,int par) {
	sz[at]=1,mxcsz[at];
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		if(gto[x]==par) continue;
		dfs1(gto[x],at);
		sz[at]+=sz[gto[x]];
		if(sz[gto[x]]>mxcsz[at]) mxcsz[at]=sz[gto[x]];
	}
}

int mem[MAXN]; map<vector<int>,int> cache;
int id(int at,int par) {
	if(mem[at]!=-1) return mem[at];
	vector<int> key;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		if(gto[x]==par) continue;
		key.PB(id(gto[x],at));
	}
	sort(key.begin(),key.end());
	if(cache.count(key)) return mem[at]=cache[key]; else return mem[at]=cache[key]=SZ(cache);
}
int go(int at,int par) {
	int ret=deg[at]<=3?1:0;
	set<int> seen;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		if(gto[x]==par) continue;
		int cur=id(gto[x],at);
		if(seen.count(cur)) continue;
		seen.insert(cur);
		ret+=go(gto[x],at);
	}
	return ret;
}


void run() {
	scanf("%d",&n);
	REP(i,n) ghead[i]=-1,deg[i]=0;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b; ++deg[a];
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a; ++deg[b];
	}
	dfs1(0,-1);
	vector<int> cent;
	REP(i,n) if(2*mxcsz[i]<=n&&2*(n-sz[i])<=n) cent.PB(i);
	int ret=0; memset(mem,-1,sizeof(mem)); cache.clear();
	if(SZ(cent)==1) {
		ret=go(cent[0],-1);
	} else {
		ret=go(cent[0],cent[1]);
		if(id(cent[0],cent[1])!=id(cent[1],cent[0])) ret+=go(cent[1],cent[0]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}