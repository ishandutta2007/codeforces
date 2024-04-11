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

const int MAXN=300000;

int n,x,y;
vector<int> adj[MAXN];

pair<int,bool> dfs(int at,int par,int skip) {
	if(at==skip) return MP(0,true);
	pair<int,bool> ret=MP(1,false);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		pair<int,bool> cur=dfs(to,at,skip);
		if(!cur.second) ret.first+=cur.first; else ret.second=true;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&x,&y); --x,--y; REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	int nx=dfs(x,-1,y).first,ny=dfs(y,-1,x).first;
	ll ret=(ll)n*(n-1)-(ll)nx*ny;
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}