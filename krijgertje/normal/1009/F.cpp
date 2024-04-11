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

const int MAXN=1000000;
struct Res { vector<int> d; int idx; };

int n;
vector<int> adj[MAXN];
int ans[MAXN];

Res res[MAXN];
Res single() { Res ret; ret.d=vector<int>(1,1); ret.idx=0; return ret; }
void append(int a) {
	res[a].d.PB(0);
}
int merge(int a,int b) {
	if(SZ(res[a].d)<SZ(res[b].d)) swap(a,b);
	REPSZ(i,res[b].d) {
		int j=SZ(res[a].d)-SZ(res[b].d)+i;
		res[a].d[j]+=res[b].d[i]; if(res[a].d[j]>res[a].d[res[a].idx]||res[a].d[j]==res[a].d[res[a].idx]&&j>res[a].idx) res[a].idx=j;
	}
	return a;
}

int dfs(int at,int par) {
	int ret=at;
	res[ret]=single();
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		int cur=dfs(to,at);
		append(cur);
		ret=merge(ret,cur);
	}
	ans[at]=SZ(res[ret].d)-res[ret].idx-1;
	//printf("%d:",at+1); REPSZ(i,res[ret].d) printf(" %d",res[ret].d[SZ(res[ret].d)-i-1]); puts("");
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	dfs(0,-1);
	REP(i,n) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}