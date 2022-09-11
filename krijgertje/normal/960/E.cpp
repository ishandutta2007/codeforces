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
const int MOD=1000000007;

int n;
int v[MAXN];
vector<int> adj[MAXN];

int numdn[MAXN][2];
int numup[MAXN][2];

void dfs1(int at,int par) {
	numdn[at][0]=0,numdn[at][1]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs1(to,at);
		numdn[at][0]=(numdn[at][0]+numdn[to][1])%MOD;
		numdn[at][1]=(numdn[at][1]+numdn[to][0])%MOD;
	}
}

void dfs2(int at,int par) {
	numup[at][0]=0,numup[at][1]=1;
	if(par!=-1) {
		numup[at][0]=((ll)numup[at][0]+numup[par][1]+numdn[par][1]+MOD-numdn[at][0]+MOD-1)%MOD;
		numup[at][1]=((ll)numup[at][1]+numup[par][0]+numdn[par][0]+MOD-numdn[at][1])%MOD;
	}
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs2(to,at);
	}
}

int dfs3(int at,int par) {
	int ret=0;
	REP(z,2) {
		int cur=0;
		int numtot=((ll)numdn[at][0]+numdn[at][1]+numup[at][0]+numup[at][1]+MOD-1)%MOD;
		if(z==0) {
			cur=(cur+numtot)%MOD;
		}
		if(par!=-1) {
			int numdiff=((ll)numtot+MOD-numup[at][0]+MOD-numup[at][1]+1)%MOD;
			int ways=z==1?numup[at][1-z]:(numup[at][1-z]+MOD-1)%MOD;
			cur=(cur+(ll)ways*numdiff)%MOD;
		}
		REPSZ(i,adj[at]) {
			int to=adj[at][i]; if(to==par) continue;
			int numdiff=((ll)numtot+MOD-numdn[to][0]+MOD-numdn[to][1])%MOD;
			cur=(cur+(ll)numdn[to][z]*numdiff)%MOD;
		}
		int vz=v[at]; if(z==1) vz=-vz;
		//printf("%d,%d: cur=%d vz=%d numtot=%d\n",at+1,z,cur,vz,numtot);
		ret=(ret+(ll)cur*((vz%MOD)+MOD))%MOD;
	}
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		ret=(ret+dfs3(to,at))%MOD;
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&v[i]); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	dfs1(0,-1);
	dfs2(0,-1);
	//REP(i,n) printf("%d: dn:%d/%d, up:%d/%d\n",i+1,numdn[i][0],numdn[i][1],numup[i][0],numup[i][1]);

	int ans=dfs3(0,-1);
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}