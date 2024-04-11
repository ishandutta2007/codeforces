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

int n,d,h;

void run() {
	scanf("%d%d%d",&n,&d,&h);
	if(d>2*h||n>2&&d==1) { printf("-1\n"); return; }
	REP(i,h) printf("%d %d\n",1+i,2+i);
	FOR(i,h,d) printf("%d %d\n",i==h?1:1+i,2+i);
	FOR(i,d,n-1) printf("%d %d\n",d!=h?1:2,2+i);
}

int main() {
	run();
	return 0;
}