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

int n,m;
vector<int> adj[MAXN];
int ans[MAXN],nans;

bool can[MAXN];
priority_queue<int> pq;

void solve() {
	nans=0;
	pq=priority_queue<int>(); REP(i,n) can[i]=false;
	pq.push(-0),can[0]=true;
	while(!pq.empty()) {
		int at=-pq.top(); pq.pop();
		ans[nans++]=at;
		REPSZ(i,adj[at]) { int to=adj[at][i]; if(!can[to]) pq.push(-to),can[to]=true; }
	}
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b),adj[b].PB(a); }
	solve();
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}