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
const int MAXLG=16;

int n,nq;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int d[MAXN];
int up[MAXN][MAXLG+1];

void dfs(int at,int par) {
	d[at]=par==-1?0:d[par]+1;
	up[at][0]=par==-1?at:par; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs(to,at);
	}
}
int lca(int a,int b) {
	//printf("?(%d,%d)\n",a+1,b+1);
	if(d[a]<d[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(d[a]-(1<<k)>=d[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	//printf("->(%d,%d)\n",a+1,b+1);
	return a==b?a:up[a][0];
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a=i+1,b; scanf("%d",&b); --b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	dfs(0,-1);
	REP(i,nq) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b,--c;
		int ab=lca(a,b),ac=lca(a,c),bc=lca(b,c);
		int z=ab; if(d[ac]>d[z]) z=ac; if(d[bc]>d[z]) z=bc;
		int az=lca(a,z),bz=lca(b,z),cz=lca(c,z);
		int A=d[a]+d[z]-2*d[az]+1,B=d[b]+d[z]-2*d[bz]+1,C=d[c]+d[z]-2*d[cz]+1;
		//printf("%d,%d,%d -> %d: %d->%d %d->%d %d->%d\n",ab+1,ac+1,bc+1,z+1,az+1,A,bz+1,B,cz+1,C);
		int ans=max(A,max(B,C));
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}