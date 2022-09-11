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
const int MAXM=300000;

int n,m;
int want[MAXN];
vector<pair<int,int> > adj[MAXN];
bool been[MAXN];
int ans[MAXM],nans;

bool dfs(int at,int par) {
	been[at]=true;
	bool ret=want[at]==1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(to==par||been[to]) continue;
		if(dfs(to,at)) {
			ans[nans++]=adj[at][i].second;
			ret=!ret;
		}
	}
	return par==-1&&want[at]==-1?false:ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&want[i]);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(MP(b,i)),adj[b].PB(MP(a,i)); }
	int rt=0; REP(i,n) if(want[rt]!=-1&&want[i]==-1) rt=i;
	REP(i,n) been[i]=false; nans=0;
	if(dfs(rt,-1)) { printf("-1\n"); return; }
	printf("%d\n",nans); REP(i,nans) printf("%d\n",ans[i]+1);
}

int main() {
	run();
	return 0;
}