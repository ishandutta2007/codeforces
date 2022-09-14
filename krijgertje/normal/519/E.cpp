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

const int MAXN=100000;
const int MAXM=MAXN-1;

int n,nq;
int fst[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];

int d[MAXN];
int sz[MAXN];
int p[MAXN][17];

int up(int a,int n) {
	for(int k=16;k>=0;--k) if(n&(1<<k)) a=p[a][k];
	return a;
}

int lca(int a,int b) {
	if(d[a]<d[b]) swap(a,b);
	a=up(a,d[a]-d[b]);
	if(a==b) return a;
	for(int k=16;k>=0;--k) if(p[a][k]!=p[b][k]) a=p[a][k],b=p[b][k];
	return p[a][0];
}

void dfs(int at,int par) {
	p[at][0]=par; sz[at]=1;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par) {
		d[to[x]]=d[at]+1;
		dfs(to[x],at);
		sz[at]+=sz[to[x]];
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	d[0]=0; dfs(0,0);
	FORE(k,1,16) REP(i,n) p[i][k]=p[p[i][k-1]][k-1];

	scanf("%d",&nq);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(a==b) { printf("%d\n",n); continue; }
		int c=lca(a,b);
		int dist=d[a]+d[b]-2*d[c];
		if(dist%2!=0) { printf("0\n"); continue; }
		if(d[a]<d[b]) swap(a,b);
		//printf("%d..%d (%d) = %d (%d,%d)\n",a,b,c,dist,d[a],d[b]);
		int ret;
		if(d[a]==d[b]) {
			ret=n-sz[up(a,dist/2-1)]-sz[up(b,dist/2-1)];
		} else {
			//printf("sz[%d]-sz[%d]\n",up(a,dist/2),up(a,dist/2-1));
			ret=sz[up(a,dist/2)]-sz[up(a,dist/2-1)];
		}
		printf("%d\n",ret);
	}

}

int main() {
	run();
	return 0;
}