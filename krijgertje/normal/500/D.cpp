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

int n,nq;
int fst[100000]; // n->e
int nxt[199998]; // e->e
int to[199998]; // e->n
int w[99999]; // ue

int par[100000]; // n->n
int cnt[199998]; // e
double p[99999];

int dfs(int at) {
	int ret=1;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		par[to[x]]=at;
		int cur=dfs(to[x]);
		ret+=cur;
		cnt[x]=cur;
		cnt[x^1]=n-cnt[x];
	}
	return ret;
}

double calc(int sz) {
	return 1.0*sz*(sz-1)*(sz-2)/n/(n-1)/(n-2);
}

void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d",&a,&b,&w[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	par[0]=-1; dfs(0);
	REP(i,n-1) p[i]=1-calc(cnt[2*i+0])-calc(cnt[2*i+1]);
	double ret=0;
	REP(i,n-1) ret+=2*p[i]*w[i];

	scanf("%d",&nq);
	REP(qi,nq) {
		int at,nw; scanf("%d%d",&at,&nw); --at;
		ret+=2*(nw-w[at])*p[at]; w[at]=nw;
		printf("%.9lf\n",ret);
	}

}

int main() {
	run();
	return 0;
}