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
const int MAXM=MAXN-1;

int n;
int fst[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];
int len[MAXM];

ll maxdist[MAXN];
ll maxdist2[MAXN];
int maxind[MAXN];



void dfs1(int at,int par) {
	maxdist[at]=0; maxdist2[at]=0; maxind[at]=-1;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par) {
		dfs1(to[x],at);
		ll cur=len[x/2]+maxdist[to[x]];
		if(cur>maxdist[at]) maxdist2[at]=maxdist[at],maxdist[at]=cur,maxind[at]=to[x]; else if(cur>maxdist2[at]) maxdist2[at]=cur;
	}
}

void dfs2(int at,int par) {
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par) {
		ll cur=len[x/2]+(maxind[at]!=to[x]?maxdist[at]:maxdist2[at]);
		//printf("%d->%d: %d (%d)\n",at,to[x],maxdist[to[x]],cur);
		if(cur>maxdist[to[x]]) maxdist2[to[x]]=maxdist[to[x]],maxdist[to[x]]=cur,maxind[to[x]]=at; else if(cur>maxdist2[to[x]]) maxdist2[to[x]]=cur;
		dfs2(to[x],at);
	}
}

int sub[MAXN]; ll maxdiff; int ans;
int p[MAXN][20];

void dfs3(int at) {
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=p[at][0]) {
		p[to[x]][0]=at; dfs3(to[x]);
	}
}

int dfs4(int at,int par) {
	//printf(".");
	//printf("%lld: %d (%d) [%d]\n",maxdiff,at,par,upto);
	int upto=at;
	for(int k=19;k>=0;--k) if(maxdist[at]-maxdist[p[upto][k]]<=maxdiff) upto=p[upto][k];
	sub[upto]++;
	int ret=1;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par) {
		ret+=dfs4(to[x],at);
	}
	if(ret>ans) ans=ret;
	return ret-sub[at];
}




void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; len[i]=c;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	dfs1(0,-1); dfs2(0,-1);
	//REP(i,n) printf("%d: %d\n",i,maxdist[i]);
	int root=0; FOR(i,1,n) if(maxdist[i]<maxdist[root]) root=i;

	p[root][0]=root; dfs3(root);
	REP(k,19) REP(i,n) p[i][k+1]=p[p[i][k]][k];

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		cin>>maxdiff;
		ans=0; REP(i,n) sub[i]=0;
		dfs4(root,-1);
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}