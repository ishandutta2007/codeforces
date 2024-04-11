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

int n;
vector<int> adj[MAXN];

int ret[MAXN][2],nret;

int leaf[MAXN],nleaf;

bool solve() {
	int a=-1; REP(i,n) if(SZ(adj[i])>=3) { if(a!=-1) return false; a=i; }
	nleaf=0; REP(i,n) if(SZ(adj[i])==1) leaf[nleaf++]=i;
	if(a==-1) { assert(nleaf==2); nret=0; ret[nret][0]=leaf[0],ret[nret][1]=leaf[1],++nret; return true; }
	nret=0; REP(i,nleaf) ret[nret][0]=a,ret[nret][1]=leaf[i],++nret; return true;
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	run();
	return 0;
}