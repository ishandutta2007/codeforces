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
const int MAXTOY=100000;


int n,ntoy,nreq,nq;
int lastreq[MAXTOY];
int par[MAXN];
int chead[MAXN],cnxt[MAXN];
int sz[MAXN];
int tin[MAXN],tout[MAXN],nt;

void dfs(int at) {
	sz[at]=1; tin[at]=nt++;
	for(int to=chead[at];to!=-1;to=cnxt[to]) {
		dfs(to);
		sz[at]+=sz[to];
	}
	tout[at]=nt-1;
}

void run() {
	scanf("%d%d%d%d",&n,&ntoy,&nreq,&nq);
	REP(i,ntoy) lastreq[i]=-1;
	REP(i,n) par[i]=-1;
	REP(i,nreq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(lastreq[b]==-1) {
			lastreq[b]=a;
		} else {
			assert(par[a]==-1);
			par[a]=lastreq[b];
			lastreq[b]=a;
		}
	}
	REP(i,n) chead[i]=-1; REP(i,n) if(par[i]!=-1) cnxt[i]=chead[par[i]],chead[par[i]]=i;
	nt=0;
	REP(i,n) if(par[i]==-1) dfs(i);

	REP(i,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(lastreq[b]==-1) {
			printf("0\n");
		} else {
			int c=lastreq[b];
			if(tin[a]<=tin[c]&&tin[c]<=tout[a]) {
				printf("%d\n",sz[a]);
			} else {
				printf("0\n");
			}
		}
	}
}

int main() {
	run();
	return 0;
}