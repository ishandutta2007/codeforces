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
const int MAXM=MAXN-1;

int n,m;
int fst[MAXN],nxt[MAXM],to[MAXM];
int val[MAXN];

ll best[MAXN][2];
#define UPDATE(a,b,c) if((b)!=-1&&(c)!=-1&&(a==-1||(b)+(c)>a)) a=(b)+(c);
void calc(int at) {
	best[at][0]=0; best[at][1]=-1;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		calc(to[x]);
		ll cur[2]={-1,-1};
		REP(i,2) REP(j,2) UPDATE(cur[i^j],best[at][i],best[to[x]][j]);
		REP(i,2) best[at][i]=cur[i];
	}
	UPDATE(best[at][1],best[at][0],val[at]);
}



void run() {
	scanf("%d",&n); m=0;
	REP(i,n) fst[i]=-1;
	REP(i,n) { int par; scanf("%d%d",&par,&val[i]); if(par!=-1) { --par; nxt[m]=fst[par]; fst[par]=m; to[m]=i; ++m; } }
	calc(0);
	ll ret=-1; REP(i,2) UPDATE(ret,best[0][i],0);
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}