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

int n;
int par[MAXN];
int ans[MAXN+1];

bool isleaf[MAXN];
int sz[MAXN];
int o[MAXN];

void solve() {
	REP(i,n) isleaf[i]=true; REP(i,n) if(par[i]!=-1) isleaf[par[i]]=false;
	REP(i,n) sz[i]=isleaf[i]?1:0; for(int i=n-1;i>=0;--i) if(par[i]!=-1) sz[par[i]]+=sz[i];
	REP(i,n) o[i]=sz[i]; sort(o,o+n);
	REP(i,n) ans[i+1]=o[i];
}

void run() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) { scanf("%d",&par[i]); --par[i]; }
	solve();
	FORE(i,1,n) { if(i!=1) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}