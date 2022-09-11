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

const int MAXN=500;

int n;
char g[MAXN][MAXN+1];

bool a[MAXN][MAXN];

int solve() {
	int ret=0;
	REP(i,n) REP(j,n) a[i][j]=g[i][j]=='X';
	FORE(i,1,n-2) FORE(j,1,n-2) if(a[i][j]&&a[i-1][j-1]&&a[i+1][j+1]&&a[i-1][j+1]&&a[i+1][j-1]) ++ret;
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(x,n) scanf("%s",g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}