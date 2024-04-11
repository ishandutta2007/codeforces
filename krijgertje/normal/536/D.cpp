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

const int MAXN=2000;
const int MAXM=100000;

int n,m;
int val[MAXN];
int fst[MAXN],nxt[2*MAXM],to[2*MAXM],len[MAXM];

priority_queue<pair<ll,int> > q;
void dijkstra(int s,ll d[MAXN]) {
	REP(i,n) d[i]=LLONG_MAX;
	d[s]=0; q.push(MP(-d[s],s));
	while(!q.empty()) {
		ll val=-q.top().first; int at=q.top().second; q.pop();
		if(val>d[at]) continue;
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			ll nval=val+len[x/2];
			if(nval<d[to[x]]) { d[to[x]]=nval; q.push(MP(-d[to[x]],to[x])); }
		}
	}
}
void norm(ll d[MAXN],ll alld[MAXN],int &nd) {
	REP(i,n) alld[i]=d[i];
	sort(alld,alld+n);
	nd=0; REP(i,n) if(nd==0||alld[i]!=alld[nd-1]) alld[nd++]=alld[i];
}
int find(ll d[MAXN],int nd,ll key) {
	int l=-1,r=nd;
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(d[m]>=key) r=m; else l=m;
	}
	assert(r<nd&&d[r]==key); return r;
}


int s; ll ds[MAXN]; ll allds[MAXN]; int nds;
int t; ll dt[MAXN]; ll alldt[MAXN]; int ndt;

ll sum[MAXN+1][MAXN+1];
int cnt[MAXN+1][MAXN+1];


// dp[i][j][k] = maximum value player k can get if only cities with ds[x]>=allds[i] and dt[x]>=alldt[j] remain
// dp[i][j][0] = sum[i][j]-min(dp[ni][j][1]:ni>i&&cnt[ni][j]<cnt[i][j])
// dp[i][j][1] = sum[i][j]-min(dp[i][nj][0]:nj>j&&cnt[i][nj]<cnt[i][j])
// idx[i][j][0] = minidx(dp[ni][j][1]:ni>i) (maximum idx if multiple)
// idx[i][j][1] = minidx(dp[i][nj][0]:nj>j) (maximum idx if multiple)
ll dp[MAXN+1][MAXN+1][2]; 
int idx[MAXN+1][MAXN+1][2];

void run() {
	scanf("%d%d%d%d",&n,&m,&s,&t); --s,--t;
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	dijkstra(s,ds); norm(ds,allds,nds);
	dijkstra(t,dt); norm(dt,alldt,ndt);
	//printf("s %d:",nds); REP(i,nds) printf(" %lld",allds[i]); puts(""); printf("t %d:",ndt); REP(i,ndt) printf(" %lld",alldt[i]); puts("");

	memset(sum,0,sizeof(sum)); memset(cnt,0,sizeof(cnt));
	REP(i,n) {
		int x=find(allds,nds,ds[i]),y=find(alldt,ndt,dt[i]);
		sum[x][y]+=val[i]; cnt[x][y]++;
	}
	//REP(x,nds) { REP(y,ndt) printf("%d ",cnt[x][y]); puts(""); } REP(x,nds) { REP(y,ndt) printf("%3lld ",sum[x][y]); puts(""); }
	for(int x=nds-1;x>=0;--x) for(int y=ndt-1;y>=0;--y) {
		sum[x][y]+=sum[x+1][y]+sum[x][y+1]-sum[x+1][y+1];
		cnt[x][y]+=cnt[x+1][y]+cnt[x][y+1]-cnt[x+1][y+1];
	}
	//REP(x,nds) { REP(y,ndt) printf("%d ",cnt[x][y]); puts(""); } REP(x,nds) { REP(y,ndt) printf("%3lld ",sum[x][y]); puts(""); }

	REPE(i,nds) dp[i][ndt][0]=dp[i][ndt][1]=0; REPE(j,ndt) dp[nds][j][0]=dp[nds][j][1]=0;
	for(int i=nds-1;i>=0;--i) for(int j=ndt-1;j>=0;--j) {
		if(i==nds-1) idx[i][j][0]=nds; else idx[i][j][0]=idx[i+1][j][0]==-1||dp[i+1][j][1]<dp[idx[i+1][j][0]][j][1]?i+1:idx[i+1][j][0];
		if(j==ndt-1) idx[i][j][1]=ndt; else idx[i][j][1]=idx[i][j+1][1]==-1||dp[i][j+1][0]<dp[i][idx[i][j+1][1]][0]?j+1:idx[i][j+1][1];
		if(cnt[i][j]==0) dp[i][j][0]=0; else dp[i][j][0]=sum[i][j]-dp[cnt[i][j]>cnt[idx[i][j][0]][j]?idx[i][j][0]:idx[idx[i][j][0]][j][0]][j][1];
		if(cnt[i][j]==0) dp[i][j][1]=0; else dp[i][j][1]=sum[i][j]-dp[i][cnt[i][j]>cnt[i][idx[i][j][1]]?idx[i][j][1]:idx[i][idx[i][j][1]][1]][0];
	}
	//REP(k,2) { printf("%s\n",k==0?"me":"opp"); REP(x,nds) { REP(y,ndt) printf("%d ",idx[x][y][k]); puts(""); } REP(x,nds) { REP(y,ndt) printf("%3lld ",dp[x][y][k]); puts(""); } }

	ll allsum=0; REP(i,n) allsum+=val[i];
	ll me=dp[0][0][0],opp=allsum-me;
	printf("%s\n",me>opp?"Break a heart":me<opp?"Cry":"Flowers");
}

int main() {
	run();
	return 0;
}