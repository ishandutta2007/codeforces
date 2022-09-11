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
int x[MAXN/2],nx;

void run() {
	scanf("%d",&n); nx=n/2; REP(i,nx) scanf("%d",&x[i]);

	sort(x,x+nx);
	int ret=INT_MAX;
	REP(par,2) {
		int cur=0;
		REP(i,nx) { int a=x[i],b=2*i+1+par; cur+=abs(a-b); }
		//printf("%d: %d\n",par,cur);
		ret=min(ret,cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}