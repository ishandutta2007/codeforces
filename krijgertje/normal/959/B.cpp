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
const int MAXLEN=20;

int n,ngrp,nq;
char s[MAXLEN+1];
map<string,int> id;
int cost[MAXN];
int gcost[MAXN];
int g[MAXN];

void run() {
	scanf("%d%d%d",&n,&ngrp,&nq);
	id.clear(); REP(i,n) { scanf("%s",s); id[s]=i; }
	REP(i,n) scanf("%d",&cost[i]);
	REP(i,ngrp) gcost[i]=INT_MAX; REP(i,ngrp) { int cnt; scanf("%d",&cnt); REP(j,cnt) { int x; scanf("%d",&x); --x; gcost[i]=min(gcost[i],cost[x]); g[x]=i; } }
	ll ret=0; REP(i,nq) { scanf("%s",s); int x=id[s]; ret+=gcost[g[x]]; }
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}