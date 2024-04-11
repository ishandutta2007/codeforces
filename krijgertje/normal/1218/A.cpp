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

const int MAXN=15000;
const int MAXCYC=MAXN;

int n;
vector<int> adj[MAXN];

int nxt[MAXN];
int cyc[MAXCYC],ncyc;

bool oncyc[MAXN];
int sz[MAXN];
int score1[MAXN]; // score of subtrees (not containing cycle), assuming node itself is already turned on
int score2[MAXN]; // max score of turning on all nodes in subtree hanging of cycle-node, when node in this subtree is kickstarted

int sum[MAXCYC+1];
int dp[MAXCYC]; // best score for turning on segment of length j, starting from cyc[i]
int ndp[MAXCYC];

bool dfscyc(int at,int par) {
	if(nxt[at]!=-1) { ncyc=0; cyc[ncyc++]=at; for(int x=nxt[at];x!=at;x=nxt[x]) cyc[ncyc++]=x; return true; }
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		nxt[at]=to; bool res=dfscyc(to,at); nxt[at]=-1; if(res) return true;
	}
	return false;
}

void dfs1(int at,int par) {
	sz[at]=1,score1[at]=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(oncyc[to]||to==par) continue;
		dfs1(to,at);
		sz[at]+=sz[to];
		score1[at]+=sz[to]+score1[to];
	}
}
void dfs2(int at,int par,int sofar) {
	int sum=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(oncyc[to]||to==par) continue;
		sum+=sz[to]+score1[to];
	}
	score2[at]=n+sofar+sum;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(oncyc[to]||to==par) continue;
		dfs2(to,at,sofar+(n-sz[to])+(sum-sz[to]-score1[to]));
		score2[at]=max(score2[at],score2[to]);
	}
}

int calcsum(int i,int len) {
	return i+len<=ncyc?sum[i+len]-sum[i]:sum[ncyc]-sum[i]+sum[i+len-ncyc];
}

int solve() {
	REP(i,n) nxt[i]=-1;
	assert(dfscyc(0,-1));
	REP(i,n) oncyc[i]=false; REP(i,ncyc) oncyc[cyc[i]]=true;
	REP(i,n) if(oncyc[i]) dfs1(i,-1),dfs2(i,-1,0);
	//REP(i,n) printf("%d: sz=%d score1=%d score2=%d oncyc=%d\n",i,sz[i],score1[i],score2[i],oncyc[i]?1:0);
	
	
	sum[0]=0; REP(i,ncyc) sum[i+1]=sum[i]+sz[cyc[i]];
	REP(i,ncyc) dp[i]=score2[cyc[i]]-score1[cyc[i]];
	FORE(len,2,ncyc) {
		REP(i,ncyc) {
			int j=i+len-1,ii=i+1,jj=j+1; if(j>=ncyc) j-=ncyc; if(ii>=ncyc) ii-=ncyc; if(jj>=ncyc) jj-=ncyc;
			int a=dp[i]+calcsum(j,ncyc-len+1);
			int b=dp[ii]+calcsum(jj,ncyc-len+1);
			ndp[i]=max(a,b);
		}
		REP(i,ncyc) dp[i]=ndp[i];
	}
	int best=0; REP(i,ncyc) best=max(best,dp[i]);
	int sum1=0; REP(i,ncyc) sum1+=score1[cyc[i]];
	return best+sum1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) { int a,b; scanf("%d%d",&a,&b); adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}