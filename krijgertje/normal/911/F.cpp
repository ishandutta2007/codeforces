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

queue<int> q;

void calcdst(int s,int *d) {
	REP(i,n) d[i]=INT_MAX; d[s]=0; q.push(s);
	while(!q.empty()) {
		int at=q.front(); q.pop();
		REPSZ(i,adj[at]) {
			int to=adj[at][i];
			if(d[to]==INT_MAX) d[to]=d[at]+1,q.push(to);
		}
	}
}

int du[MAXN],dv[MAXN];
int deg[MAXN];

int ret[MAXN][3],nret;

int drt[MAXN];
int farthest(int rt) {
	calcdst(rt,drt);
	int ret=rt; REP(i,n) if(drt[i]>drt[ret]) ret=i; return ret;
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	int u=farthest(0),v=farthest(u);
	calcdst(u,du); calcdst(v,dv);
	//printf("%d..%d\n",u+1,v+1);
	REP(i,n) deg[i]=SZ(adj[i]);
	REP(i,n) if(i!=u&&i!=v&&deg[i]==1) q.push(i);
	nret=0; ll sum=0;
	while(!q.empty()) {
		int at=q.front(); q.pop();
		//printf("at1=%d\n",at+1);
		int w=du[at]>=dv[at]?u:v;
		ret[nret][0]=at,ret[nret][1]=w,ret[nret][2]=at,++nret; sum+=max(du[at],dv[at]);
		REPSZ(i,adj[at]) {
			int to=adj[at][i]; --deg[to];
			if(to!=u&&to!=v&&deg[to]==1) q.push(to);			
		}
	}
	assert(deg[v]==1); q.push(v);
	while(!q.empty()) {
		int at=q.front(); q.pop();
		//printf("at2=%d\n",at+1);
		int w=u;
		ret[nret][0]=at,ret[nret][1]=w,ret[nret][2]=at,++nret; sum+=du[at];
		REPSZ(i,adj[at]) {
			int to=adj[at][i]; --deg[to];
			if(to!=u&&deg[to]==1) q.push(to);
		}
	}
	printf("%lld\n",sum);
	REP(i,nret) printf("%d %d %d\n",ret[i][0]+1,ret[i][1]+1,ret[i][2]+1);
}

int main() {
	run();
	return 0;
}