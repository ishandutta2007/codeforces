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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

void run() {
	int n,m; scanf("%d%d",&n,&m);
	int sum=0;
	VI deg(n,0);
	VVI minlen(n,VI(n,INT_MAX));
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		++deg[a],++deg[b],sum+=c;
		if(c<minlen[a][b]) minlen[a][b]=c; if(c<minlen[b][a]) minlen[b][a]=c;
	}
	VVI reach(n,VI(n,0)); REP(i,n) reach[i][i]=1;
	REP(i,n) REP(j,n) if(minlen[i][j]<INT_MAX) reach[i][j]=1;
	REP(k,n) REP(i,n) REP(j,n) if(reach[i][k]&&reach[k][j]) reach[i][j]=1;
	REP(i,n) if(!reach[0][i]) REP(j,n) if(minlen[i][j]<INT_MAX) { printf("-1\n"); return; }	
		
	VI best(1<<n,INT_MAX); priority_queue<pair<int,int> > q;
	#define ADD(x,y) if(y<best[x]) best[x]=y,q.push(MP(-(y),x));
	int smask=0; REP(i,n) if(deg[i]%2==1) smask|=1<<i;
	ADD(smask,sum);
	while(!q.empty()) {
		int at=q.top().second,cost=-q.top().first; q.pop();
		if(cost>best[at]) continue;
		REP(i,n) if(at&(1<<i)) {
			REP(j,n) if(minlen[i][j]<INT_MAX) {
				int to=at^(1<<i)^(1<<j);
				ADD(to,cost+minlen[i][j]);
			}
			break;
		}
	}
	printf("%d\n",best[0]);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}