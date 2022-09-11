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

const int MAXN=100000;
const int MAXX=2*MAXN-2;

int n;
int b[MAXN-1];
int c[MAXN-1];
int a[MAXN],na;

int x[MAXX],nx;
vector<int> idxadj[MAXX];
int odd[MAXX],nodd;
bool reach[MAXX];
int q[MAXX],qhead,qtail;
bool used[MAXN-1];
int pos[MAXX];

void dfs(int at) {
	while(pos[at]<SZ(idxadj[at])) {
		int idx=idxadj[at][pos[at]++]; if(used[idx]) continue;
		used[idx]=true;
		int to=b[idx]^c[idx]^at;
		dfs(to);
	}
	a[na++]=x[at];
}

bool solve() {
	REP(i,n-1) if(b[i]>c[i]) return false;

	nx=0; REP(i,n-1) x[nx++]=b[i],x[nx++]=c[i]; sort(x,x+nx); nx=unique(x,x+nx)-x; REP(i,n-1) b[i]=lower_bound(x,x+nx,b[i])-x,c[i]=lower_bound(x,x+nx,c[i])-x;
	REP(i,nx) idxadj[i].clear(); REP(i,n-1) { int j=b[i],k=c[i]; idxadj[j].PB(i),idxadj[k].PB(i); }
	nodd=0; REP(i,nx) if(SZ(idxadj[i])%2==1) odd[nodd++]=i; if(nodd>2) return false;
	qhead=qtail=0; REP(i,nx) reach[i]=false;
	reach[0]=true,q[qhead++]=0;
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,idxadj[at]) { int idx=idxadj[at][i],to=b[idx]^c[idx]^at; if(!reach[to]) reach[to]=true,q[qhead++]=to; } }
	REP(i,nx) if(!reach[i]) return false;
	
	REP(i,n-1) used[i]=false;
	REP(i,nx) pos[i]=0;
	int root=nodd>0?odd[0]:0;
	na=0; dfs(root);
	REP(i,n-1) assert(used[i]);
	assert(na==n);
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) scanf("%d",&b[i]);
	REP(i,n-1) scanf("%d",&c[i]);
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
}

int main() {
	run();
	return 0;
}