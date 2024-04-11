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

const int MAXN=100000;

int n;
pair<int,int> o[MAXN];

int p[MAXN];
bool done[MAXN];
vector<vector<int> > ans;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&o[i].first),o[i].second=i;
	sort(o,o+n);
	REP(i,n) p[o[i].second]=i;
	ans.clear();
	REP(i,n) done[i]=false;
	REP(i,n) if(!done[i]) {
		ans.PB(vector<int>());
		int at=i;
		while(!done[at]) { ans.back().PB(at); done[at]=true; at=p[at]; }
	}
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { printf("%d",SZ(ans[i])); REPSZ(j,ans[i]) printf(" %d",ans[i][j]+1); puts(""); }
}

int main() {
	run();
	return 0;
}