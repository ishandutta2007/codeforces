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

const int MAXN=1000;
struct E { int a,b,c; E() {} E(int a,int b,int c):a(a),b(b),c(c) {} };

int n;
vector<int> adj[MAXN];
vector<E> ans;

int sz[MAXN];
void dfssz(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par) continue; dfssz(to,at); sz[at]+=sz[to]; }
}
int dfscentroid(int at,int par,int rootsz) {
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par) continue; if(2*sz[to]>rootsz) return dfscentroid(to,at,rootsz); }
	return at;
}

int centroid(int at) {
	dfssz(at,-1);
	return dfscentroid(at,-1,sz[at]);
}

vector<int> subtrees;
vector<int> subtreesum;

void dfsgen(int at,int par,int sofar,int &nxt,int step) {
	int me=nxt; nxt+=step;
	ans.PB(E(par,at,me-sofar));
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par) continue; dfsgen(to,at,me,nxt,step); }
}

void solve() {
	int cent=centroid(0);
	//printf("cent=%d\n",cent+1);
	dfssz(cent,-1);
	subtrees.clear();
	REPSZ(i,adj[cent]) { int to=adj[cent][i]; subtrees.PB(to); }
	sort(subtrees.begin(),subtrees.end(),[&](const int &a,const int &b) { return sz[a]<sz[b]; });
	subtreesum=vector<int>(SZ(subtrees)+1); subtreesum[0]=0; REPSZ(i,subtrees) subtreesum[i+1]=subtreesum[i]+sz[subtrees[i]];
	//printf("subtreesum:"); REPSZ(i,subtreesum) printf(" %d",subtreesum[i]); puts("");
	int best=n-1; int bestidx=0; bool bestleft=true;
	REPSZ(i,subtreesum) {
		{
			int cur=subtreesum[i];
			if(2*cur<=n-1&&(n-1-2*cur)<best) best=n-2*cur,bestidx=i,bestleft=true;
		}
		{
			int cur=n-1-subtreesum[i];
			if(2*cur<=n-1&&(n-1-2*cur)<best) best=n-2*cur,bestidx=i,bestleft=false;
		}
	}
	//printf("bestidx=%d bestleft=%s\n",bestidx,bestleft?"yes":"no");
	vector<int> small,large;
	REPSZ(i,subtrees) if(i<bestidx) small.PB(subtrees[i]); else large.PB(subtrees[i]);
	if(!bestleft) swap(small,large);
	int smallsum=0; REPSZ(i,small) smallsum+=sz[small[i]];
	int largesum=0; REPSZ(i,large) largesum+=sz[large[i]];
	//printf("SZ(small)=%d, SZ(large)=%d\n",smallsum,largesum);

	ans.clear();
	int nxtsmall=1,largestep=smallsum+1,nxtlarge=largestep;
	REPSZ(i,small) dfsgen(small[i],cent,0,nxtsmall,1);
	REPSZ(i,large) dfsgen(large[i],cent,0,nxtlarge,largestep);
	//printf("need=%d have=%d\n",2*n*n/9,nxtlarge);
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REPSZ(i,ans) printf("%d %d %d\n",ans[i].a+1,ans[i].b+1,ans[i].c);
}

void stress() {
	n=MAXN;
	REP(i,n) adj[i].clear();
	FOR(i,1,n) { int a=0,b=i; adj[a].PB(b); adj[b].PB(a); }
	//FOR(i,1,n) { int a=i-1,b=i; adj[a].PB(b); adj[b].PB(a); }
	solve();
	int mx=0;
	REPSZ(i,ans) mx=max(mx,ans[i].c);
	printf("mx=%d\n",mx);
}

int main() {
	run();
	//stress();
	return 0;
}