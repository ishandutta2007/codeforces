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

const int MAXN=1000;

int n,dst;
int a[MAXN];
int b[MAXN];

bool solve() {
	if(a[0]==0) return false;
	if(a[dst]==1) return true;
	if(b[dst]==0) return false;
	FOR(i,dst+1,n) if(a[i]==1&&b[i]==1) return true;
	return false;
}

void run() {
	scanf("%d%d",&n,&dst),--dst;
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}