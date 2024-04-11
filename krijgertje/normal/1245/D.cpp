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
#include <chrono>
#include <chrono>
#include <random>
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

int n;
int x[MAXN],y[MAXN];
int stationcost[MAXN];
int roadcost[MAXN];

bool done[MAXN];
int best[MAXN],act[MAXN];

ll anscost;
vector<int> ansstation;
vector<pair<int,int>> ansroad;

void solve() {
	REP(i,n) done[i]=false,best[i]=stationcost[i],act[i]=-1;
	anscost=0; ansstation.clear(),ansroad.clear();
	REP(rep,n) {
		int at=-1; REP(i,n) if(!done[i]&&(at==-1||best[i]<best[at])) at=i; assert(at!=-1);
		done[at]=true;
		anscost+=best[at];
		if(act[at]==-1) ansstation.PB(at); else ansroad.PB(MP(act[at],at));
		REP(to,n) { ll z=(ll)(roadcost[at]+roadcost[to])*(abs(x[at]-x[to])+abs(y[at]-y[to])); if(z<best[to]) best[to]=z,act[to]=at; }
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,n) scanf("%d",&stationcost[i]);
	REP(i,n) scanf("%d",&roadcost[i]);
	solve();
	printf("%lld\n",anscost);
	printf("%d\n",SZ(ansstation)); REPSZ(i,ansstation) { if(i!=0) printf(" "); printf("%d",ansstation[i]+1); } puts("");
	printf("%d\n",SZ(ansroad)); REPSZ(i,ansroad) { printf("%d %d\n",ansroad[i].first+1,ansroad[i].second+1); }
}

int main() {
	run();
	return 0;
}