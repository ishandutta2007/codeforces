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

const int MAXN=3000;
const int MAXM=3000;
const int MAXQ=400000;

int n,m,nq;
vector<pair<int,bool> > adj[MAXN];

bool reach[MAXN][MAXN];
int q[MAXN],qhead,qtail;

vector<pair<int,int> > qq[MAXN][MAXN];
int ans[MAXQ];

int path[MAXN]; bool been[MAXN];
void dfs(int s,int at,int d,bool ok) {
	path[d++]=at; been[at]=true;
	REPSZ(i,qq[s][at]) {
		int nr=qq[s][at][i].first,id=qq[s][at][i].second;
		//printf("q%d: %d->%d #%d (len=%d)\n",id+1,s+1,at+1,nr+1,d);
		if(ok&&nr<d) ans[id]=path[nr]+1;
	}
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(been[to]) continue;
		dfs(s,to,d,ok&&adj[at][i].second);
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(MP(b,true)); }

	REP(i,n) {
		REP(j,n) reach[i][j]=false; qhead=qtail=0; q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(k,adj[at]) {
				int to=adj[at][k].first;
				if(!reach[i][to]) { reach[i][to]=true; if(to!=i) q[qhead++]=to; }
			}
		}
	}

	REP(i,n) {
		REPSZ(j,adj[i]) {
			int at=adj[i][j].first;
			REPSZ(k,adj[i]) {
				int to=adj[i][k].first;
				if(to<at&&reach[to][at]) adj[i][j].second=false;
			}
		}
		sort(adj[i].begin(),adj[i].end());
	}

	REP(i,nq) {
		int s,t,k; scanf("%d%d%d",&s,&t,&k); --s,--t,--k;
		qq[s][t].PB(MP(k,i));
		ans[i]=-1;
	}

	REP(i,n) {
		REP(j,n) been[j]=false;
		dfs(i,i,0,true);
	}

	REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}