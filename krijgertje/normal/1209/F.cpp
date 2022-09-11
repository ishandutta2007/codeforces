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

const int MAXCITY=100000;
const int MAXROAD=100000;
const int MOD=1000000007;
const int MAXN=MAXCITY+5*2*MAXCITY;

int ncity,nroad;
int e[MAXROAD][2];
int ans[MAXCITY];

int n;
int id[MAXCITY];
vector<int> adj[MAXN][10];

int dist[MAXN];
queue<vector<int>> q;

void solve() {
	n=0;
	REP(i,ncity) id[i]=n++;
	REP(i,nroad) REP(j,2) { 
		int a=e[i][j],b=e[i][1-j];
		int x=i+1; vector<int> d; while(x>0) { d.PB(x%10); x/=10; } reverse(d.begin(),d.end());
		int at=id[a]; REPSZ(k,d) { int to; if(k==SZ(d)-1) to=id[b]; else to=n++; adj[at][d[k]].PB(to); at=to; }
	}
	//REP(at,n) { printf("%d:",at); REP(d,10) REPSZ(i,adj[at][d]) printf(" %d=%d",d,adj[at][d][i]); puts(""); }

	REP(i,n) dist[i]=-1;
	q=queue<vector<int>>();
	dist[id[0]]=0; q.push(vector<int>(1,id[0]));
	while(!q.empty()) {
		vector<int> lst=q.front(); q.pop();
		REP(d,10) {
			vector<int> nlst;
			REPSZ(idx,lst) {
				int at=lst[idx];
				REPSZ(i,adj[at][d]) {
					int to=adj[at][d][i];
					if(dist[to]==-1) dist[to]=((ll)dist[at]*10+d)%MOD,nlst.PB(to);
				}
			}
			if(SZ(nlst)!=0) q.push(nlst);
		}
	}
	REP(i,ncity) ans[i]=dist[id[i]];
}


void run() {
	scanf("%d%d",&ncity,&nroad);
	REP(i,nroad) REP(j,2) scanf("%d",&e[i][j]),--e[i][j];
	solve();
	FOR(i,1,ncity) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}