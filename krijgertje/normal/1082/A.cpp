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

int n,x,y,d;

int solve() {
	int ret=INT_MAX;
	if((x-y)%d==0) ret=min(ret,abs(x-y)/d);
	if(y%d==0) ret=min(ret,(x+d-1)/d+y/d);
	if(y%d==(n-1)%d) ret=min(ret,(n-1-x+d-1)/d+(n-1-y)/d);
	return ret==INT_MAX?-1:ret;
}

void run() {
	scanf("%d%d%d%d",&n,&x,&y,&d),--x,--y;
	printf("%d\n",solve());
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}