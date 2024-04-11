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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;
const int MAXPATH=1000000;

int n;
char g[MAXN][MAXN+1];
int npath;
int path[MAXPATH];
int ans[MAXPATH]; int nans;

int d[MAXN][MAXN];

void solve() {
	REP(i,n) REP(j,n) d[i][j]=i==j?0:g[i][j]=='1'?1:INT_MAX;
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	nans=0; int at=0; ans[nans++]=path[at];
	while(at+1<npath) {
		int to=at; while(to<npath&&d[path[at]][path[to]]==to-at) ++to;
		//if(to<npath) printf("path[%d]->path[%d] == %d->%d: %d vs %d\n",at,to,path[at]+1,path[to]+1,d[path[at]][path[to]],to-at);
		 --to;
		assert(to>at); ans[nans++]=path[to]; at=to;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%s",g[i]);
	scanf("%d",&npath);
	REP(i,npath) scanf("%d",&path[i]),--path[i];
	solve();
	printf("%d\n",nans);
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");

}

int main() {
	run();
	return 0;
}