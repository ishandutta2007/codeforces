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

const int MAXN=10;

int n[2],b[2],d[2][MAXN];
ll val[2];

void run() {
	REP(i,2) { scanf("%d%d",&n[i],&b[i]); REP(j,n[i]) scanf("%d",&d[i][j]); }
	REP(i,2) { val[i]=0; REP(j,n[i]) val[i]=b[i]*val[i]+d[i][j]; }
	//printf("%lld %lld\n",val[0],val[1]);
	printf("%c",val[0]<val[1]?'<':val[0]>val[1]?'>':'=');
}

int main() {
	run();
	return 0;
}