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
const int MAXM=200000;

int n,m;
int head[MAXN],nxt[MAXM],to[MAXM];
int deg[MAXN];
int cnt[MAXN];

void run() {
	scanf("%d%d",&n,&m); REP(i,n) head[i]=-1,deg[i]=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b; if(a>b) swap(a,b);
		nxt[i]=head[b]; head[b]=i; to[i]=a; ++deg[a],++deg[b];
	}
	REP(i,n) { cnt[i]=1; for(int x=head[i];x!=-1;x=nxt[x]) if(1+cnt[to[x]]>cnt[i]) cnt[i]=1+cnt[to[x]]; }
	ll ret=0; REP(i,n) { ll cur=(ll)cnt[i]*deg[i]; if(cur>ret) ret=cur; } printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}