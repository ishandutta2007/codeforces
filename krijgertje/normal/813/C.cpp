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
const int MAXM=MAXN-1;

int n,s;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int d[MAXN];
void dfs(int at,int par) {
	d[at]=par==-1?0:d[par]+1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs(to,at);
	}
}

int t[MAXN];
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d%d",&n,&s); --s; REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}

	dfs(0,-1);

	REP(i,n) t[i]=INT_MAX; qhead=qtail=0;
	t[s]=0; q[qhead++]=s;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			if(t[to]!=INT_MAX||t[at]+1>=d[to]) continue;
			t[to]=t[at]+1,q[qhead++]=to;
		}
	}
	int ret=0;
	REP(i,n) if(t[i]!=INT_MAX) ret=max(ret,2*d[i]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}