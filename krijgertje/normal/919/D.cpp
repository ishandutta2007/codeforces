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

int n,m;
char s[MAXN+1];
vector<int> adj[MAXN];

bool done[MAXN];
int top[MAXN],toppos[MAXN],ntop;

int cnt[MAXN][26];

void dfstop(int at) {
	done[at]=true; REPSZ(i,adj[at]) { int to=adj[at][i]; if(done[to]) continue; dfstop(to); } toppos[at]=ntop,top[ntop]=at,++ntop;
}

void run() {
	scanf("%d%d",&n,&m); scanf("%s",s); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); }

	ntop=0; REP(i,n) toppos[i]=-1,done[i]=false; REP(i,n) if(!done[i]) dfstop(i);
	//printf("top:"); REP(i,n) printf(" %d",top[i]+1); puts("");
	REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; if(toppos[to]>=toppos[at]) { printf("-1\n"); return; } }

	REP(at,n) REP(k,26) cnt[at][k]=0;
	REP(i,n) { int at=top[i]; REPSZ(j,adj[at]) { int to=adj[at][j]; REP(k,26) cnt[at][k]=max(cnt[at][k],cnt[to][k]); } ++cnt[at][s[at]-'a']; }
	int ret=0; REP(at,n) REP(k,26) ret=max(ret,cnt[at][k]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}