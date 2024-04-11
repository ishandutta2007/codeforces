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

const int MAXN=200000;

int n;
vector<int> adj[MAXN];

int sz[MAXN];


vector<int> centroids;
void dfs(int at,int par) {
	sz[at]=1; int cmx=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs(to,at); sz[at]+=sz[to];
		if(sz[to]>cmx) cmx=sz[to];
	}
	if(n-sz[at]>cmx) cmx=n-sz[at];
	if(2*cmx<=n) centroids.PB(at);
}

void calccentroids(int at) {
	centroids.clear(); dfs(at,-1); assert(SZ(centroids)>0&&SZ(centroids)<=2);
}

vector<pair<int,pair<int,int> > > ans;
void transform(int at,int par,int rt,int &a,int &b) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		transform(to,at,rt,a,b);
		if(at==a&&to==b||at==b||to==b) continue;
		//printf("at=%d to=%d\n",at+1,to+1);
		ans.PB(MP(rt,MP(a,to)));
		ans.PB(MP(to,MP(at,b)));
		a=to;
	}
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	calccentroids(0);
	ans.clear();
	REPSZ(k,centroids) {
		int c=centroids[k];
		REPSZ(i,adj[c]) {
			int a=adj[c][i]; if(SZ(centroids)==2&&(a==centroids[0]||a==centroids[1])) continue;
			int b=-1; REPSZ(j,adj[a]) { int to=adj[a][j]; if(to==c) continue; b=to; break; } if(b==-1) continue;
			transform(a,c,c,a,b);
			ans.PB(MP(c,MP(a,b)));
		}
	}
	printf("%d\n",SZ(ans)); REPSZ(i,ans) printf("%d %d %d\n",ans[i].first+1,ans[i].second.first+1,ans[i].second.second+1);
}

int main() {
	run();
	return 0;
}