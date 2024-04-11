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

const int MAXH=50;
const int MAXW=50;

int h,w;
int a[MAXH][MAXW];
vector<pair<int,int>> ans;

int b[MAXH][MAXW];

bool solve() {
	REP(x,h) REP(y,w) b[x][y]=0;
	REP(x,h-1) REP(y,w-1) if(a[x][y]==1&&a[x+1][y]==1&&a[x][y+1]==1&&a[x+1][y+1]==1) { ans.PB(MP(x,y)); b[x][y]=b[x+1][y]=b[x][y+1]=b[x+1][y+1]=1; }
	REP(x,h) REP(y,w) if(b[x][y]!=a[x][y]) return false;
	return true;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&a[x][y]);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}