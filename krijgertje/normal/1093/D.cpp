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

const int MAXN=300000;
const int MAXM=300000;
const int MOD=998244353;

int n,m;
vector<int> adj[MAXN];

bool done[MAXN];
int p2[MAXN+1];

int q[MAXN],col[MAXN],qhead,qtail;

pair<int,int> bfs(int s) {
	qhead=qtail=0; done[s]=true,col[s]=0,q[qhead++]=s;
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,adj[at]) {
			int to=adj[at][i];
			if(!done[to]) done[to]=true,col[to]=1-col[at],q[qhead++]=to;
			if(col[to]==col[at]) return MP(-1,-1);
		}
	}
	pair<int,int> ret=MP(0,0);
	REP(i,qhead) { int at=q[i]; if(col[at]==0) ++ret.first; else ++ret.second; }
	return ret;
}

int solve() {
	REP(i,n) done[i]=false;
	p2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD;
	int ret=1;
	REP(i,n) if(!done[i]) {
		pair<int,int> cur=bfs(i);
		if(cur.first==-1||cur.second==-1) return 0;
		ret=(ll)ret*(p2[cur.first]+p2[cur.second])%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
	REP(i,n) adj[i].clear();
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}