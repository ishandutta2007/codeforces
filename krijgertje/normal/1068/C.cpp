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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;
const int MAXM=1000;

int n,m;
int e[MAXM][2];
vector<pair<int,int>> ans[MAXN];

void solve() {
	REP(i,n) ans[i].clear();
	REP(i,n) ans[i].PB(MP(i,i));
	REP(i,m) REP(j,2) ans[e[i][j]].PB(MP(e[i][j],n+i));
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) REP(j,2) scanf("%d",&e[i][j]),--e[i][j];
	solve();
	REP(i,n) { printf("%d\n",SZ(ans[i])); REPSZ(j,ans[i]) printf("%d %d\n",ans[i][j].first+1,ans[i][j].second+1); }
}

int main() {
	run();
	return 0;
}