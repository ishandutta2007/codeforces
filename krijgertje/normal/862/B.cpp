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
vector<int> adj[MAXN];
int col[MAXN];

void dfs(int at,int par) {
	col[at]=par==-1?0:1-col[par];
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par) continue; dfs(to,at); }
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	dfs(0,-1);
	int n0=0,n1=0; REP(i,n) if(col[i]==0) ++n0; else if(col[i]==1) ++n1;
	ll maxm=(ll)n0*n1;
	printf("%lld\n",maxm-(n-1));
}

int main() {
	run();
	return 0;
}