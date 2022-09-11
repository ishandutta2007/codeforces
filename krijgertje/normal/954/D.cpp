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

const int MAXN=1000;

int n,m,s,t;
vector<int> adj[MAXN];

int ds[MAXN],dt[MAXN];
bool exists[MAXN][MAXN];

int q[MAXN],qhead,qtail;
void calcdst(int s,int *dst) {
	REP(i,n) dst[i]=INT_MAX; qhead=qtail=0;
	dst[s]=0; q[qhead++]=s;
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(dst[to]!=INT_MAX) continue; dst[to]=dst[at]+1; q[qhead++]=to; } }
}

void run() {
	scanf("%d%d%d%d",&n,&m,&s,&t); --s,--t;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	calcdst(s,ds);
	calcdst(t,dt);

	int ret=0;
	memset(exists,false,sizeof(exists)); REP(i,n) REPSZ(j,adj[i]) exists[i][adj[i][j]]=true;
	REP(i,n) FOR(j,i+1,n) if(!exists[i][j]) {
		if(ds[i]+1+dt[j]<ds[t]||ds[j]+1+dt[i]<ds[t]) continue;
		++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}