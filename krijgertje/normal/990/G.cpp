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

const int MAXN=200000;
const int MAXVAL=200000;

int n;
int val[MAXN];
vector<int> adj[MAXN];

int sz[MAXN];
bool alive[MAXN];

void dfssz(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		dfssz(to,at); sz[at]+=sz[to];
	}
}
int dfscentroid(int at,int par,int root) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		if(2*sz[to]>sz[root]) return dfscentroid(to,at,root);
	}
	return at;
}
int centroid(int root) {
	dfssz(root,-1);
	return dfscentroid(root,-1,root);
}

int mp1[MAXVAL+1];
int lst1[MAXVAL+1],nlst1;
int cnt[MAXVAL+1];
int mp2[MAXVAL+1];
int lst2[MAXVAL+1],nlst2;
int sum[MAXVAL+1];
ll ans[MAXVAL+1];

void dfscnt(int at,int par,int cur) {
	cur=gcd(cur,val[at]);
	if(mp1[cur]==-1) mp1[cur]=nlst1,lst1[nlst1]=cur,++nlst1;
	++cnt[mp1[cur]];
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par||!alive[to]) continue;
		dfscnt(to,at,cur);
	}
}

void process(int cent) {
	//printf("cent=%d\n",cent);
	nlst2=0;
	mp2[val[cent]]=nlst2,lst2[nlst2]=val[cent],++nlst2;
	++ans[val[cent]];
	++sum[mp2[val[cent]]];
	REPSZ(i,adj[cent]) {
		int to=adj[cent][i]; if(!alive[to]) continue;
		nlst1=0;
		dfscnt(to,cent,val[cent]);
		REP(j,nlst1) REP(k,nlst2) { int cur=gcd(lst1[j],lst2[k]); /*printf("%d,%d -> %d (%d*%d)\n",lst1[j],lst2[k],cur,cnt[j],sum[k]);*/ ans[cur]+=(ll)cnt[j]*sum[k]; }
		REP(j,nlst1) { int cur=lst1[j]; if(mp2[cur]==-1) mp2[cur]=nlst2,lst2[nlst2]=cur,++nlst2; sum[mp2[cur]]+=cnt[j]; }
		REP(j,nlst1) mp1[lst1[j]]=-1,cnt[j]=0;
	}
	REP(k,nlst2) mp2[lst2[k]]=-1,sum[k]=0;
}

void decompose(int root) {
	int cent=centroid(root);
	process(cent);
	alive[cent]=false;
	REPSZ(i,adj[cent]) {
		int to=adj[cent][i]; if(!alive[to]) continue;
		decompose(to);
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&val[i]); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	memset(mp1,-1,sizeof(mp1)); memset(cnt,0,sizeof(cnt)); 
	memset(mp2,-1,sizeof(mp2)); memset(sum,0,sizeof(sum));
	memset(ans,0,sizeof(ans));
	REP(i,n) alive[i]=true;
	decompose(0);
	REPE(i,MAXVAL) if(ans[i]>0) printf("%d %lld\n",i,ans[i]);
}

int main() {
	run();
	return 0;
}