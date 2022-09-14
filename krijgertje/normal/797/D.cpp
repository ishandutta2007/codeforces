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
int v[MAXN],l[MAXN],r[MAXN];
int par[MAXN];

int lv[MAXN],rv[MAXN]; bool any[MAXN];
map<int,int> cnt;

void dfs(int at,int LV,int RV) {
	if(LV>RV) return;
	any[at]=true; lv[at]=LV,rv[at]=RV;
	if(l[at]!=-1) dfs(l[at],LV,min(RV,v[at]-1));
	if(r[at]!=-1) dfs(r[at],max(LV,v[at]+1),RV);
}



void run() {
	scanf("%d",&n); REP(i,n) { scanf("%d%d%d",&v[i],&l[i],&r[i]); if(l[i]!=-1) --l[i]; if(r[i]!=-1) --r[i]; }
	REP(i,n) par[i]=-1; REP(i,n) if(l[i]!=-1) par[l[i]]=i; REP(i,n) if(r[i]!=-1) par[r[i]]=i; int root=-1; REP(i,n) if(par[i]==-1) root=i;

	REP(i,n) any[i]=false;
	dfs(root,INT_MIN,INT_MAX);
	cnt.clear(); REP(i,n) cnt[v[i]]++;
	int found=0; REP(i,n) if(any[i]&&lv[i]<=v[i]&&v[i]<=rv[i]) found+=cnt[v[i]];
	printf("%d\n",n-found);
}

int main() {
	run();
	return 0;
}