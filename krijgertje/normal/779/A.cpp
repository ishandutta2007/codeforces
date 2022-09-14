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

int n;
int cnt[2][5];

void run() {
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	REP(i,2) REP(j,n) { int x; scanf("%d",&x); --x; ++cnt[i][x]; }
	int ret=0;
	REP(x,5) { int diff=abs(cnt[0][x]-cnt[1][x]); if(diff%2==1) { printf("-1\n"); return; } ret+=diff/2; }
	assert(ret%2==0); printf("%d\n",ret/2);
}

int main() {
	run();
	return 0;
}