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
const int NVAL=20;

int n;
vector<int> adj[MAXN];
char s[MAXN+1];

bool alive[MAXN];
ll ans[MAXN];

int cnt[1<<NVAL];

void mark(int at,int par,int mask,int by) {
	mask^=1<<(s[at]-'a');
	cnt[mask]+=by;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		mark(to,at,mask,by);
	}
}

ll dfs(int at,int par,int mask,bool inc) {
	mask^=1<<(s[at]-'a');
	ll ret=0;
	ret+=cnt[mask];
	REP(i,NVAL) ret+=cnt[mask^(1<<i)];
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		ret+=dfs(to,at,mask,inc);
	}
	if(inc) ans[at]+=ret;
	return ret;
}

int sz[MAXN];
void dfssz(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		dfssz(to,at); sz[at]+=sz[to];
	}
}

int dfscentroid(int at,int par,int rtsz) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		if(2*sz[to]>rtsz) return dfscentroid(to,at,rtsz);
	}
	return at;
}

int centroid(int rt) {
	dfssz(rt,-1);
	return dfscentroid(rt,-1,sz[rt]);
}

void decompose(int c) {
	//printf("decompose(%d)\n",c+1);
	c=centroid(c);
	//printf("centroid=%d\n",c+1);
	alive[c]=false;
	REPSZ(i,adj[c]) {
		int to=adj[c][i]; if(!alive[to]) continue;
		mark(to,c,0,+1);
	}
	++cnt[0];
	REPSZ(i,adj[c]) {
		int to=adj[c][i]; if(!alive[to]) continue;
		mark(to,c,0,-1);
		dfs(to,c,1<<(s[c]-'a'),true);
		mark(to,c,0,+1);
	}
	REPSZ(i,adj[c]) {
		int to=adj[c][i]; if(!alive[to]) continue;
		mark(to,c,0,-1);
		ans[c]+=dfs(to,c,1<<(s[c]-'a'),false);
	}
	--cnt[0];
	++ans[c];
	REPSZ(i,adj[c]) {
		int to=adj[c][i]; if(!alive[to]) continue;
		decompose(to);
	}
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); } scanf("%s",s);

	REP(i,n) alive[i]=true,ans[i]=0; memset(cnt,0,sizeof(cnt));
	decompose(0);
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}