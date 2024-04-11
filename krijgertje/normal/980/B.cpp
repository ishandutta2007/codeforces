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

const int MAXW=99;

int w,need;

char g[4][MAXW+1];

void run() {
	scanf("%d%d",&w,&need);
	REP(x,4) { REP(y,w) g[x][y]='.'; g[x][w]='\0'; }
	int rem=need;
	FORE(x,1,2) FORE(y,1,(w-3)/2) if(rem>=2) { g[x][y]=g[x][w-y-1]='#'; rem-=2; }
	if(rem>0) g[1][(w-1)/2]='#',--rem;
	if(rem>0) g[2][(w-1)/2]='#',--rem;
	assert(rem==0);
	printf("YES\n"); REP(x,4) printf("%s\n",g[x]);
}

int main() {
	run();
	return 0;
}