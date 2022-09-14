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

int n,a,b;

void run() {
	scanf("%d%d%d",&n,&a,&b); int aa=1,bb=1;
	if(n>a*b) { printf("%d\n",-1); return; }
	REP(i,a) { REP(j,b) { if(j!=0) printf(" "); if(i%2==j%2&&2*aa-1<=n) printf("%d",2*aa-1),aa++; else if(i%2!=j%2&&2*bb<=n) printf("%d",2*bb),bb++; else printf("0"); } puts(""); }
}

int main() {
	run();
	return 0;
}