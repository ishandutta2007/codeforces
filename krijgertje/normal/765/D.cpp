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

const int MAXN=100000;
const int MAXM=MAXN;

int n;
int f[MAXN+1];

int m;
int g[MAXN+1];
int h[MAXM+1];


bool solve() {
	m=0;
	FORE(i,1,n) if(f[i]==i) {
		++m;
		g[i]=m; h[m]=i;
	}
	FORE(i,1,n) {
		if(f[i]==i) continue;
		if(f[f[i]]==f[i]) { g[i]=g[f[i]]; continue; }
		return false;
	}
	return true;
}

void run() {
	scanf("%d",&n); FORE(i,1,n) scanf("%d",&f[i]);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",m); FORE(i,1,n) { if(i!=1) printf(" "); printf("%d",g[i]); } puts(""); FORE(i,1,m) { if(i!=1) printf(" "); printf("%d",h[i]); } puts(""); 
}

int main() {
	run();
	return 0;
}