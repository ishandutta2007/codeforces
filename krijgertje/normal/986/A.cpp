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
const int MAXK=100;

int n,m,k,need;
int prod[MAXN];
vector<int> adj[MAXN];

pair<int,int> q[MAXN*MAXK]; int qhead,qtail;
int d[MAXN][MAXK];
int have[MAXN],cost[MAXN];

void upd(int i,int j,int val) { if(d[i][j]==INT_MAX) d[i][j]=val,q[qhead++]=MP(i,j); }
void run() {
	scanf("%d%d%d%d",&n,&m,&k,&need);
	REP(i,n) scanf("%d",&prod[i]),--prod[i];
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	qhead=qtail=0; REP(i,n) REP(j,k) d[i][j]=INT_MAX; REP(i,n) have[i]=0,cost[i]=0;
	REP(i,n) upd(i,prod[i],0);
	while(qtail<qhead) {
		int i=q[qtail].first,j=q[qtail].second; ++qtail;
		//printf("%d %d = %d\n",i+1,j+1,d[i][j]);
		if(have[i]<need) ++have[i],cost[i]+=d[i][j];
		REPSZ(idx,adj[i]) {
			int ni=adj[i][idx];
			upd(ni,j,d[i][j]+1);
		}
	}
	REP(i,n) assert(have[i]==need);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",cost[i]); } puts("");
}

int main() {
	run();
	return 0;
}