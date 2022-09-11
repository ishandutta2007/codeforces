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
#include <functional>
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

const int MAXN=500000;
const int MAXM=500000;

int n,m;
int eto[2*MAXM],el[MAXM],er[MAXM];
vector<int> adj[MAXN];
int adjidx[MAXN][2]; // adjidx[nodeidx][parity]
int d[2*MAXM][2]; // dp[edgeidx][parity]
priority_queue<pair<int,int> > q;


bool elcmp(const int &p,const int &q) { return el[p>>1]<el[q>>1]; }
int nxtwithpar(int t,int p) { return t%2==p?t:t+1; }

void input() {
	scanf("%d%d",&n,&m);
	REP(i,n) adj[i].clear();
	REP(i,m) { int a,b; scanf("%d%d%d%d",&a,&b,&el[i],&er[i]); --a,--b,--er[i]; eto[2*i+0]=b,adj[a].PB(2*i+0); eto[2*i+1]=a,adj[b].PB(2*i+1); }
}

int solve() {
	REP(i,n) { sort(adj[i].begin(),adj[i].end(),elcmp); REP(p,2) adjidx[i][p]=0; }
	//REP(i,n) { printf("%d:",i+1); REPSZ(j,adj[i]) { int x=adj[i][j]; printf(" %d[%d-%d]{%d}",eto[x]+1,el[x>>1],er[x>>1],x); } puts(""); }

	REP(x,2*m) REP(p,2) d[x][p]=INT_MAX; q=priority_queue<pair<int,int> >();
	REPSZ(j,adj[0]) { int x=adj[0][j]; if(el[x>>1]==0) d[x][0]=0,q.push(MP(-d[x][0],2*x+0)); }
	while(!q.empty()) {
		int t=-q.top().first,x=q.top().second/2,p=q.top().second%2; q.pop();
		if(t>d[x][p]) continue;
		int at=eto[x^1],to=eto[x];
		//printf("d[%d->%d{%d}][%d]=%d\n",at+1,to+1,x,p,t);
		{ // use edge
			int nx=x^1,np=1-p,nt=t+1;
			if(t<=er[x>>1]) {
				//printf("\t%d->%d{%d} %d with %d\n",eto[nx^1]+1,eto[nx]+1,nx,np,nt);
				if(nt<d[nx][np]) d[nx][np]=nt,q.push(MP(-d[nx][np],2*nx+np));
			}
		}
		while(adjidx[at][p]<SZ(adj[at])) { // nxt edge at node
			int nx=adj[at][adjidx[at][p]],np=p,nt=max(t,nxtwithpar(el[nx>>1],np));
			if(nt<=er[nx>>1]) {
				if(nt-1<=er[x>>1]) {
					//printf("\t%d->%d{%d} %d with %d\n",eto[nx^1]+1,eto[nx]+1,nx,np,nt);
					if(nt<d[nx][np]) d[nx][np]=nt,q.push(MP(-d[nx][np],2*nx+np));
				}
				if(nt-1>er[x>>1]) break;
			}
			++adjidx[at][p];
		}
	}
	int ret=n==1?0:INT_MAX; REPSZ(j,adj[n-1]) { int x=adj[n-1][j]; REP(p,2) ret=min(ret,d[x][p]); } return ret==INT_MAX?-1:ret;
}

void run() {
	input();
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}