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

const int MAXN=100;
const int MAXTRAM=100;

int n;
bool stops[MAXN][MAXTRAM+1];
int ret[MAXTRAM],nret;

bool can[MAXTRAM+1];

void solve() {
	FORE(j,1,MAXTRAM) can[j]=true;
	REP(i,n) FORE(j,1,MAXTRAM) can[j]&=stops[i][j];
	nret=0; FORE(j,1,MAXTRAM) if(can[j]) ret[nret++]=j;
}

void run() {
	scanf("%d",&n);
	REP(i,n) FORE(j,1,MAXTRAM) stops[i][j]=false;
	REP(i,n) { int cnt; scanf("%d",&cnt); REP(j,cnt) { int x; scanf("%d",&x); stops[i][x]=true; } }
	solve();
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}