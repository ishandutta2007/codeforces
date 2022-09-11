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
const int MAXM=200000;

int n;
int want[MAXN];
int m;
vector<pair<int,int> > e[MAXN];
int ans[MAXM];

bool done[MAXN];
int dfs(int at,int par) {
	done[at]=true;
	int ret=want[at];
	REPSZ(i,e[at]) {
		int to=e[at][i].first; if(to==par||done[to]) continue;
		int cur=dfs(to,at);
		int id=e[at][i].second/2,dir=e[at][i].second%2;
		ans[id]=dir==0?+cur:-cur;
		ret+=cur;
	}
	return ret;
}

bool solve() {
	REP(i,n) done[i]=false;
	REP(i,m) ans[i]=0;
	REP(i,n) if(!done[i]) {
		int rem=dfs(i,-1);
		if(rem!=0) return false;
	}
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&want[i]);
	scanf("%d",&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[a].PB(MP(b,2*i+0)); e[b].PB(MP(a,2*i+1)); }

	if(!solve()) { printf("Impossible\n"); return; }
	printf("Possible\n"); REP(i,m) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}