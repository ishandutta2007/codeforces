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
#include <random>
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

int n,k;
int ret[MAXN][MAXN];

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) REP(j,n) ret[i][j]=0;
	int left=k;
	REP(i,n) REP(j,n) if(ret[i][j]==0&&left>0) {
		if(i==j) { ret[i][j]=1; --left; continue; }
		if(left>=2) { ret[i][j]=ret[j][i]=1; left-=2; continue; }
	}
	if(left!=0) { printf("-1\n"); return; }
	REP(i,n) { REP(j,n) { if(j!=0) printf(" "); printf("%d",ret[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}