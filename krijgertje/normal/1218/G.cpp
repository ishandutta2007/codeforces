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

const int MAXN=100000;
const int MAXM=100000;

int n,m;
char s[MAXN+1];
int e[MAXM][2]; int ans[MAXM];

vector<pair<int,int>> adj[MAXN];
int par[MAXN],parid[MAXN],dep[MAXN];
bool intree[MAXM];
int sum[MAXN];

void dfs(int at) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,id=adj[at][i].second; if(par[to]!=-2) continue;
		par[to]=at,parid[to]=id,dep[to]=dep[at]+1; dfs(to);
	}
}
void dfs3(int at) {
	sum[at]=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,id=adj[at][i].second; if(par[to]!=-2||!intree[id]) continue;
		par[to]=at,parid[to]=id,dep[to]=dep[at]+1; dfs3(to); sum[at]=(sum[at]+ans[id])%3;
	}
	if(parid[at]!=-1) { int want=s[at]-'X'; ans[parid[at]]=(want+3-sum[at])%3; sum[at]=(sum[at]+ans[parid[at]])%3; assert(sum[at]==want); }
}

void dfs2(int at) {
	sum[at]=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,id=adj[at][i].second; if(par[to]!=-2||!intree[id]) continue;
		par[to]=at,parid[to]=id,dep[to]=dep[at]+1; dfs2(to); sum[at]=(sum[at]+ans[id])%3;
	}
	if(parid[at]!=-1) { int want=dep[at]%2; ans[parid[at]]=(want+3-sum[at])%3; sum[at]=(sum[at]+ans[parid[at]])%3; assert(sum[at]==want); }
}

void solve() {
	REP(i,n) adj[i].clear();
	REP(i,m) REP(j,2) adj[e[i][j]].PB(MP(e[i][1-j],i));
	REP(i,n) par[i]=-2;
	par[0]=-1,parid[0]=-1,dep[0]=0; dfs(0);
	REP(i,n) assert(par[i]!=-2);
	REP(i,m) intree[i]=false;
	REP(i,n) if(par[i]!=-1) intree[parid[i]]=true;

	vector<pair<int,int>> oddcyc;
	REP(i,m) if(!intree[i]) {
		int a=e[i][0],b=e[i][1];
		if(dep[a]%2!=dep[b]%2) continue; 
		vector<int> apath,bpath; while(a!=b) if(dep[a]>=dep[b]) apath.PB(a),a=par[a]; else bpath.PB(b),b=par[b];
		reverse(bpath.begin(),bpath.end()); REPSZ(j,apath) { int x=apath[j]; oddcyc.PB(MP(x,parid[x])); } oddcyc.PB(MP(a,-1)); REPSZ(j,bpath) { int x=bpath[j]; oddcyc.PB(MP(x,parid[x])); } 
		FORSZ(j,SZ(apath)+1,oddcyc) oddcyc[j-1].second=oddcyc[j].second; oddcyc[SZ(oddcyc)-1].second=i;
		assert(SZ(oddcyc)%2==1);
		break;
	}
	//printf("oddcyc:"); REPSZ(i,oddcyc) printf(" %d (%d)",oddcyc[i].first,oddcyc[i].second); puts("");

	if(SZ(oddcyc)==0) {
		int root=0;
		REP(i,n) par[i]=-2;
		REP(i,m) ans[i]=0;
		par[root]=-1,parid[root]=-1,dep[root]=0; dfs2(root);
		//printf("sum[root]=%d\n",sum[root]);
		if(sum[root]==1&&SZ(adj[root])>=2) {
			int a=adj[root][0].first,b=adj[root][1].first,aid=adj[root][0].second,bid=adj[root][1].second;
			assert(sum[a]==1&&sum[b]==1);
			ans[aid]=(ans[aid]+1)%3,ans[bid]=(ans[bid]+1)%3; sum[root]=(sum[root]+2)%3,sum[a]=(sum[a]+1)%3,sum[b]=(sum[b]+1)%3;
		}
	} else {
		int root=oddcyc[0].first;
		REP(i,n) par[i]=-2;
		REP(i,m) ans[i]=0;
		par[root]=-1,parid[root]=-1,dep[root]=0; dfs3(root);
		REP(i,n) assert(par[i]!=-2);
		int wantroot=s[root]-'X';
		int delta=(wantroot+3-sum[root])%3,x=2*delta%3;
		//printf("delta=%d x=%d\n",delta,x);
		REPSZ(i,oddcyc) { int id=oddcyc[i].second; ans[id]=(ans[id]+(i%2==0?x:3-x))%3; } sum[root]=(sum[root]+2*x)%3;
	}
	REP(i,m) if(ans[i]==0) ans[i]=3;
	vector<int> chk(n,0);
	REP(at,n) REPSZ(i,adj[at]) chk[at]+=ans[adj[at][i].second];
	//printf("chk:"); REP(i,n) printf(" %d",chk[i]); puts("");
}

void run() {
	scanf("%d%d",&n,&m);
	scanf("%s",s); assert(strlen(s)==n);
	REP(i,m) REP(j,2) scanf("%d",&e[i][j]);
	solve();
	REP(i,m) printf("%d %d %d\n",e[i][0],e[i][1],ans[i]);
}

int main() {
	run();
	return 0;
}