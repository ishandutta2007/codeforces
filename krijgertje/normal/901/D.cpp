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
const int MAXM=100000;

int n,m;
int want[MAXN];
vector<pair<int,int> > adj[MAXN];
bool intree[MAXM];

int oddroot;

int col[MAXN];
void dfs(int at,int par) {
	col[at]=par==-1?0:1-col[par];
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(to==par) continue;
		if(col[to]==-1) {
			intree[adj[at][i].second]=true;
			dfs(to,at);
		} else {
			if(oddroot==-1&&col[to]==col[at]) oddroot=at;
		}
	}
}
ll ans[MAXM];
ll solve(int at,int parid) {
	ll sum=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,id=adj[at][i].second; if(id==parid||!intree[id]) continue;
		ll childsum=solve(to,id);
		ans[id]=want[to]-childsum;
		sum+=ans[id];
	}
	return sum;
}
bool modify(int at,int parid,ll by,ll sby) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,id=adj[at][i].second; if(id==parid) continue;
		if(to==oddroot&&by==sby) { ans[id]+=by; return true; }
		if(!intree[id]) continue;
		if(modify(to,id,-by,sby)) { ans[id]+=by; return true; }
	}
	return false;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&want[i]);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(MP(b,i)); adj[b].PB(MP(a,i)); intree[i]=false; }

	memset(col,-1,sizeof(col));
	oddroot=-1; dfs(0,-1);
	//printf("oddroot=%d\n",oddroot+1);

	int root=oddroot; if(root==-1) root=0;
	memset(ans,0,sizeof(ans)); int childsum=solve(root,-1);
	ll diff=want[root]-childsum;
	if(diff!=0&&oddroot!=-1) {
		assert(diff%2==0);
		assert(modify(root,-1,diff/2,diff/2));
		diff=0;
	}
	if(diff!=0) { printf("NO\n"); return; }
	REP(i,m) assert(abs(ans[i])<=(ll)2*n*n);
	printf("YES\n"); REP(i,m) printf("%lld\n",ans[i]);
}

int main() {
	run();
	return 0;
}