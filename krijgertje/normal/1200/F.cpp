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
#include <tuple>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;
const int MOD=2520;
const int MAXQ=100000;

int n;
int delta[MAXN];
vector<int> out[MAXN];
int nq;
int qx[MAXQ],qval[MAXQ],qans[MAXQ];

pair<int,int> nxt[MAXN][MOD];
int state[MAXN][MOD];
int ans[MAXN][MOD];

int lst[MAXN],nlst;
bool seen[MAXN];

void solve() {
	REP(i,n) delta[i]=(delta[i]%MOD+MOD)%MOD;
	REP(i,nq) qval[i]=(qval[i]%MOD+MOD)%MOD;

	REP(i,n) REP(j,MOD) { int nj=(j+delta[i])%MOD,ni=out[i][nj%SZ(out[i])]; nxt[i][j]=MP(ni,nj); }
	REP(i,n) REP(j,MOD) state[i][j]=0;
	nlst=0; REP(i,n) seen[i]=false;
	REP(i,n) REP(j,MOD) if(state[i][j]==0) {
		int x=i,y=j;
		while(state[x][y]==0) { state[x][y]=1; tie(x,y)=nxt[x][y]; }
		if(state[x][y]==1) {
			while(state[x][y]==1) { state[x][y]=2; if(!seen[x]) seen[x]=true,lst[nlst++]=x; tie(x,y)=nxt[x][y]; }
			while(state[x][y]==2) { state[x][y]=3; ans[x][y]=nlst; tie(x,y)=nxt[x][y]; }
			REP(k,nlst) seen[lst[k]]=false; nlst=0;
		}
		int cans=ans[x][y]; x=i,y=j;
		while(state[x][y]==1) { state[x][y]=3; ans[x][y]=cans; tie(x,y)=nxt[x][y]; }
	}
	REP(i,nq) qans[i]=ans[qx[i]][qval[i]];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&delta[i]);
	REP(i,n) { int cnt; scanf("%d",&cnt); out[i]=vector<int>(cnt); REP(j,cnt) scanf("%d",&out[i][j]),--out[i][j]; }
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&qx[i],&qval[i]),--qx[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);

}

int main() {
	run();
	return 0;
}