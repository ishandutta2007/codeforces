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

const int MAXN=1000000;
const int MAXM=1000000+MAXN;

int n,m;
vector<pair<int,int>> adj[MAXN+1];
vector<pair<int,int>> ans;

int pos[MAXN+1];
bool used[MAXM];
vector<pair<int,int>> path;
vector<bool> keep;

void dfs(int at) {
	while(true) {
		while(pos[at]<SZ(adj[at])&&used[adj[at][pos[at]].second]) ++pos[at];
		if(pos[at]>=SZ(adj[at])) return;
		int to=adj[at][pos[at]].first,id=adj[at][pos[at]].second; ++pos[at];
		used[id]=true; dfs(to); path.PB(MP(to,at));
	}
}

void solve() {
	REP(i,n) if(SZ(adj[i])%2==1) { adj[i].PB(MP(n,m)); adj[n].PB(MP(i,m)); ++m; }
	REPE(i,n) assert(SZ(adj[i])%2==0);

	REPE(i,n) pos[i]=0;
	REP(i,m) used[i]=false;
	ans.clear();
	{
		path.clear();
		dfs(n);
		//printf("npath:"); REPSZ(i,path) printf(" (%d,%d)",path[i].first+1,path[i].second+1); puts("");
		keep=vector<bool>(SZ(path),false);
		REPSZ(i,path) {
			if(i%2==1) continue;
			if(path[i].first==n) keep[(i+1)%SZ(path)]=true;
			else if(path[i].second==n) keep[(i+m-1)%SZ(path)]=true;
			else keep[i]=true;
		}
		REPSZ(i,path) if(keep[i]) ans.PB(path[i]);
	}
	REP(i,n) {
		path.clear();
		dfs(i);
		if(SZ(path)==0) continue;
		//printf("extra path:"); REPSZ(i,path) printf(" (%d,%d)",path[i].first+1,path[i].second+1); puts("");
		REPSZ(i,path) if(i%2==0) ans.PB(path[i]);
	}
	
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(MP(b,i)); adj[b].PB(MP(a,i)); }
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}