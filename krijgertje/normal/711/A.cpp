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

const int MAXN=1000;

int n;
char g[MAXN][6];

bool solve() { REP(i,n) REP(j,2) if(g[i][3*j+0]=='O'&&g[i][3*j+1]=='O') { g[i][3*j+0]=g[i][3*j+1]='+'; return true; } return false; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",g[i]);
	bool ret=solve();
	printf("%s\n",ret?"YES":"NO");
	if(ret) REP(i,n) printf("%s\n",g[i]);
}

int main() {
	run();
	return 0;
}