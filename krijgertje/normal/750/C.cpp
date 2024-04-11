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

const int MAXN=200000;

int n;

void run() {
	scanf("%d",&n);
	int mn=INT_MIN,mx=INT_MAX;
	REP(i,n) {
		int dv,delta; scanf("%d%d",&delta,&dv);
		if(dv==2) mx=min(mx,1899); if(dv==1) mn=max(mn,1900);
		if(mn!=INT_MIN) mn+=delta; if(mx!=INT_MAX) mx+=delta;
	}
	if(mx==INT_MAX) printf("Infinity\n"); else if(mx<mn) printf("Impossible\n"); else printf("%d\n",mx);
}

int main() {
	run();
	return 0;
}