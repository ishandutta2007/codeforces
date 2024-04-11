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

const int MAXN=100;

int n;
char g[MAXN][MAXN];
int guess[MAXN];
int have[MAXN];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf(" %c",&g[i][j]);
	REP(i,n) scanf("%d",&guess[i]);
	REP(i,n) have[i]=0;
	nret=0;
	while(true) {
		int idx=-1; REP(i,n) if(have[i]==guess[i]) { idx=i; break; } if(idx==-1) break;
		ret[nret++]=idx;
		REP(j,n) if(g[idx][j]=='1') ++have[j];
	}
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}


int main() {
	run();
	return 0;
}