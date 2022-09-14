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

const int MAXN=9;

int n;
char g[1<<MAXN][1<<MAXN];

void run() {
	scanf("%d",&n);
	g[0][0]='+';
	REP(i,n) REP(x,1<<i) REP(y,1<<i) {
		g[x+(1<<i)][y]=g[x][y+(1<<i)]=g[x][y];
		g[x+(1<<i)][y+(1<<i)]=g[x][y]=='+'?'*':'+';
	}
	REP(x,1<<n) { REP(y,1<<n) printf("%c",g[x][y]); puts(""); }
}

int main() {
	run();
	return 0;
}