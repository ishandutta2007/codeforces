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

const int MAXN=1000;

int n;
vector<int> adj[MAXN];
int a[MAXN],na;
int b[MAXN],nb;

bool ina[MAXN];
bool inb[MAXN];

int dfs(int at,int par,int target) {
	if(at==target) return -2;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		int cur=dfs(to,at,target);
		if(cur>=0) return cur;
		if(cur==-2) return ina[at]?at:-2;
	}
	return -1;
}

int btoa(int bid) {
	printf("B %d\n",bid+1); fflush(stdout);
	int ret; scanf("%d",&ret); if(ret==-1) exit(0); --ret; return ret;
}
int atob(int aid) {
	printf("A %d\n",aid+1); fflush(stdout);
	int ret; scanf("%d",&ret); if(ret==-1) exit(0); --ret; return ret;
}

int solve() {
	REP(i,n) ina[i]=false; REP(i,na) ina[a[i]]=true;
	REP(i,n) inb[i]=false; REP(i,nb) inb[b[i]]=true;
	int aroot=a[0];
	int both=b[0],aoth=btoa(both);
	if(ina[aoth]) return aoth;
	int aclosest=dfs(aroot,-1,aoth);
	int bclosest=atob(aclosest);
	if(inb[bclosest]) return aclosest;
	return -1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) adj[i].clear();
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d",&na); REP(i,na) { scanf("%d",&a[i]); --a[i]; }
	scanf("%d",&nb); REP(i,nb) { scanf("%d",&b[i]); --b[i]; }
	int ans=solve();
	printf("C %d\n",ans==-1?-1:ans+1); fflush(stdout);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}