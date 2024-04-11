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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n,ncol;
vector<int> adj[MAXN];
int ans[MAXN];

int q[MAXN],qhead,qtail;
int d[MAXN],prv[MAXN];

int diag[MAXN],ndiag;
bool ondiag[MAXN];

int farthest(int s) {
	qhead=qtail=0; REP(i,n) d[i]=INT_MAX,prv[i]=-2;
	d[s]=0,prv[s]=-1,q[qhead++]=s;
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(d[to]==INT_MAX) d[to]=d[at]+1,prv[to]=at,q[qhead++]=to; } }
	assert(qhead==n); return q[n-1];
}

int dfs(int at,int par,int col,int dcol) {
	int ret=0;
	ans[at]=col;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||ondiag[to]) continue;
		ret=max(ret,1+dfs(to,at,(col+dcol+ncol)%ncol,dcol));
	}
	return ret;
}

bool solve() {
	if(ncol==1) { REP(i,n) ans[i]=0; return true; }
	if(ncol==2) { REP(i,n) ondiag[i]=false; dfs(0,-1,0,1); return true; }

	int a=farthest(0);
	int b=farthest(a);
	ndiag=0; for(int at=b;at!=-1;at=prv[at]) diag[ndiag++]=at; reverse(diag,diag+ndiag);
	REP(i,n) ondiag[i]=false;
	REP(i,ndiag) ondiag[diag[i]]=true;
	REP(i,ndiag) {
		int at=diag[i];
		bool onleft=2*i<ndiag;
		int dep=dfs(at,-1,i%ncol,onleft?-1:+1);
		//printf("%d: at=%d dep=%d\n",i,at+1,dep);
		if(dep>=1&&dep+i+1>=ncol&&dep+ndiag-i>=ncol) return false;
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&ncol);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}