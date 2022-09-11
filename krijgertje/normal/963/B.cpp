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

int n;
vector<int> adj[MAXN];


bool mem[MAXN][2];

// res.first indicates whether we can destroy all vertices when there is no parent edge, res.second when there is a parent edge
pair<bool,bool> calc(int at,int par) {
	// do some subtrees with a parent edge, then our node, then remaining without a parent edge
	int nwith=0,nwithout=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		pair<bool,bool> res=calc(to,at);
		if(!res.first&&!res.second) return MP(false,false);
		if(res.first&&res.second) return MP(true,true);
		if(res.first) ++nwithout; else ++nwith;
	}
	pair<bool,bool> res=MP(nwithout%2==0,nwithout%2==1);
	mem[at][0]=res.first; mem[at][1]=res.second;
	return res;
}

void go(int at,int par,int havepar) {
	int nwith=0,nwithout=0,either=-1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		pair<bool,bool> res=MP(mem[to][0],mem[to][1]);
		assert(res.first||res.second);
		if(res.first&&res.second&&either==-1) { either=to; continue; }
		if(res.first) ++nwithout; else ++nwith,go(to,at,1);
	}
	int deg=nwithout+havepar; bool doneeither=false;
	if(either!=-1) { if(deg%2==0) ++nwith,go(either,at,1),doneeither=true; else ++nwithout,++deg; }
	assert(deg%2==0);
	printf("%d\n",at+1);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		pair<bool,bool> res=MP(mem[to][0],mem[to][1]);
		assert(res.first||res.second);
		if(to==either) { if(!doneeither) go(either,at,0),doneeither=true; continue; }
		if(res.first) go(to,at,0);
	}
}

void run() {
	scanf("%d",&n); REP(i,n) { int par; scanf("%d",&par); --par; if(par!=-1) adj[i].PB(par),adj[par].PB(i); }

	pair<bool,bool> res=calc(0,-1);
	if(!res.first) { printf("NO\n"); return; }
	printf("YES\n");
	go(0,-1,0);
	
}

int main() {
	run();
	return 0;
}