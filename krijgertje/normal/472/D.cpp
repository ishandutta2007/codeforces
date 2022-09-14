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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct E { int a,b,c; } E;
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n;
int d[2000][2000];

int par[2000];
int rnk[2000];

int m;
E e[2000000];

int nt;
int fst[2000];
int nxt[4000];
int to[4000];

int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
void unite(int a,int b) {
	a=find(a),b=find(b); if(a==b) return;
	if(rnk[a]<rnk[b]) swap(a,b);
	par[b]=a; if(rnk[a]==rnk[b]) ++rnk[a];
}

bool check(int root,int at,int par,int dst) {
	if(d[root][at]!=dst) return false;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par&&!check(root,to[x],at,dst+d[at][to[x]])) return false;
	return true;
}

bool ok() {
	REP(i,n) if(d[i][i]!=0) return false;
	REP(i,n) FOR(j,i+1,n) if(d[i][j]!=d[j][i]||d[i][j]==0) return false;
	REP(i,n) par[i]=i,rnk[i]=0;
	int m=0; REP(i,n) FOR(j,i+1,n) { e[m].a=i; e[m].b=j; e[m].c=d[i][j]; ++m; } sort(e,e+m);
	nt=0; REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a=e[i].a,b=e[i].b;
		if(find(a)==find(b)) continue; else unite(a,b);
		nxt[2*nt+0]=fst[a]; fst[a]=2*nt+0; to[2*nt+0]=b;
		nxt[2*nt+1]=fst[b]; fst[b]=2*nt+1; to[2*nt+1]=a;
		++nt;
	}
	REP(i,n) if(!check(i,i,-1,0)) return false;
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) REP(j,n) scanf("%d",&d[i][j]);
	printf("%s\n",ok()?"YES":"NO");
}

int main() {
	run();
	return 0;
}