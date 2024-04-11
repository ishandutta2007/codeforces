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

const int MAXN=200000;

int n,ncol;
int col[MAXN][2];

bool solve() {
	ll lim=(ll)ncol*(ncol-1); if(n>lim) return false;
	int at=0;
	FORE(d,1,ncol-1) REP(i,ncol) { int a=i,b=(i+d)%ncol; col[at][0]=a,col[at][1]=b; ++at; if(at>=n) return true; }
	assert(false); return false;
}

void run() {
	scanf("%d%d",&n,&ncol);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) printf("%d %d\n",col[i][0]+1,col[i][1]+1);
}

int main() {
	run();
	return 0;
}