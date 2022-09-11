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

const int MAXN=500000;
typedef struct Res {
	int cnt;
	bool canperfect,canperfectminroot;
	int cntperfectminother,cntperfectminrootminother;
} Res;

Res combine(const Res &a,const Res &b) {
	Res ret;
	ret.cnt=a.cnt+b.cnt-1;
	ret.canperfect=a.canperfect&&b.canperfectminroot||a.canperfectminroot&&b.canperfect;
	ret.canperfectminroot=a.canperfectminroot&&b.canperfectminroot;
	ret.cntperfectminother=(a.canperfect?b.cntperfectminrootminother:0)+(a.canperfectminroot?b.cntperfectminother:0)+(b.canperfect?a.cntperfectminrootminother:0)+(b.canperfectminroot?a.cntperfectminother:0);
	ret.cntperfectminrootminother=(a.canperfectminroot?b.cntperfectminrootminother:0)+(b.canperfectminroot?a.cntperfectminrootminother:0);
	return ret;
}

Res extend(const Res &a) {
	Res ret;
	ret.cnt=a.cnt+1;
	ret.canperfect=a.canperfectminroot;
	ret.canperfectminroot=a.canperfect;
	ret.cntperfectminother=a.cntperfectminrootminother;
	ret.cntperfectminrootminother=(a.canperfectminroot?1:0)+a.cntperfectminother;
	return ret;
}

Res single() {
	Res ret;
	ret.cnt=1;
	ret.canperfect=false;
	ret.canperfectminroot=true;
	ret.cntperfectminother=0;
	ret.cntperfectminrootminother=0;
	return ret;
}

void print(const Res &a) {
	printf("[%d: %c %c %d %d]",a.cnt,a.canperfect?'V':'x',a.canperfectminroot?'V':'x',a.cntperfectminother,a.cntperfectminrootminother);
}

int n;
vector<int> adj[MAXN];
Res subtree[MAXN];

void dfs1(int at,int par) {
	subtree[at]=single();
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs1(to,at);
		subtree[at]=combine(subtree[at],extend(subtree[to]));
	}
	//printf("subtree[%d]: ",at+1); print(subtree[at]); puts("");
}

ll dfs2(int at,int par,Res above) {
	vector<int> ch; REPSZ(i,adj[at]) { int to=adj[at][i]; if(to!=par) ch.PB(to); }
	int nch=SZ(ch); vector<Res> pref(nch+1),suff(nch+1); // pref[i] are all childs < i, suff[i] are all childs >= i
	pref[0]=above; REP(i,nch) pref[i+1]=combine(pref[i],extend(subtree[ch[i]]));
	suff[nch]=single(); for(int i=nch-1;i>=0;--i) suff[i]=combine(extend(subtree[ch[i]]),suff[i+1]);
	ll ret=0;
	REP(i,nch) {
		int to=ch[i];
		Res a=combine(pref[i],suff[i+1]),b=subtree[to];
		ll cur=0;
		if(a.canperfect&&b.canperfect) cur+=(ll)a.cnt*b.cnt;
		else cur+=(ll)((a.canperfectminroot?1:0)+a.cntperfectminother)*((b.canperfectminroot?1:0)+b.cntperfectminother);
		//printf("%d-%d: ",at+1,to+1); print(a); printf(" and "); print(b); printf(" -> %lld\n",cur);
		ret+=cur+dfs2(to,at,extend(a));
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	dfs1(0,-1);
	ll ret=dfs2(0,-1,single());
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}