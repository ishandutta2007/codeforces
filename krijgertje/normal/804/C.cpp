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

const int MAXN=300000;
const int MAXM=MAXN-1;
const int MAXT=300000;
const int MAXS=500000;

int n,nt;
int cnt[MAXN];
int off[MAXN+1];
int s[MAXS];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

bool done[MAXN];
pair<int,int> o[MAXN];

int col[MAXT];
int fst[MAXT];
int mark[MAXT];
int inuseby[MAXT];
int prv[MAXT];


void dfs(int at,int par,int ncol) {
	assert(!done[at]); done[at]=true;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		REP(i,cnt[to]) {
			int z=s[off[to]+i];
			if(fst[z]==-1) fst[z]=to;
			mark[z]=to;
		}
		int j=0;
		REP(i,cnt[to]) {
			int z=s[off[to]+i];
			if(fst[z]!=to) continue;
			while(j<ncol&&mark[inuseby[j]]==to) ++j;
			assert(j<ncol);
			prv[z]=inuseby[j];
			inuseby[j]=z; col[z]=j;
		}
		dfs(to,at,ncol);
		REP(i,cnt[to]) {
			int z=s[off[to]+i];
			if(fst[z]!=to) continue;
			inuseby[col[z]]=prv[z];
		}
	}
}


void run() {
	scanf("%d%d",&n,&nt);
	off[0]=0; REP(i,n) { scanf("%d",&cnt[i]); REP(j,cnt[i]) scanf("%d",&s[off[i]+j]); off[i+1]=off[i]+cnt[i]; }
	REP(i,off[n]) --s[i];
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}

	int need=0; REP(i,n) if(cnt[i]>need) need=cnt[i]; if(need==0&&nt>=1) need=1;
	REP(i,nt) col[i]=fst[i]=mark[i]=-1;
	REP(i,n) o[i]=MP(-cnt[i],i); sort(o,o+n);
	REP(i,n) {
		int at=o[i].second;
		if(done[at]) continue;
		REP(j,cnt[at]) {
			int z=s[off[at]+j];
			assert(col[z]==-1);
			col[z]=j;
			fst[z]=at;
			inuseby[j]=z;
		}
		dfs(at,-1,cnt[at]);
	}
	printf("%d\n",need);
	REP(i,nt) { if(i!=0) printf(" "); printf("%d",col[i]==-1?1:col[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}