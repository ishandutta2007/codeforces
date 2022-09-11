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

const int MAXSWITCH=2000;
const int MAXLAMP=2000;

int nswitch,nlamp;
char a[MAXSWITCH][MAXLAMP+1];

int cnt[MAXLAMP];

bool solve() {
	REP(j,nlamp) cnt[j]=0;
	REP(i,nswitch) REP(j,nlamp) if(a[i][j]=='1') ++cnt[j];
	REP(i,nswitch) { bool ok=true; REP(j,nlamp) if(a[i][j]=='1'&&cnt[j]==1) ok=false; if(ok) return true; }
	return false;
}

void run() {
	scanf("%d%d",&nswitch,&nlamp); REP(i,nswitch) scanf("%s",a[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}