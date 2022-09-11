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

int wantblack,wantwhite;
vector<pair<int,int>> ans;

bool solve() {
	int wanta=max(wantblack,wantwhite),wantb=min(wantblack,wantwhite);
	int sx=1,sy=wantblack>=wantwhite?2:3;
	if(wanta>3*wantb+1) return false;
	ans.clear();
	int havea=0,haveb=0;
	REP(i,wantb) ans.PB(MP(sx+1+2*i,sy)),++haveb;
	REP(i,wantb+1) if(havea<wanta) ans.PB(MP(sx+2*i,sy)),++havea;
	REP(i,wantb) if(havea<wanta) ans.PB(MP(sx+1+2*i,sy-1)),++havea;
	REP(i,wantb) if(havea<wanta) ans.PB(MP(sx+1+2*i,sy+1)),++havea;
	assert(havea==wanta&&haveb==wantb);
	return true;
}

void run() {
	scanf("%d%d",&wantblack,&wantwhite);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i,ans) printf("%d %d\n",ans[i].first,ans[i].second);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}