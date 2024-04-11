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


int n,a,b,c,d;

void run() {
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	int mn=max(max(1,1-b+c),max(1-a-b+c+d,1-a+d));
	int mx=min(min(n,n-b+c),min(n-a-b+c+d,n-a+d));
	printf("%I64d\n",mn<=mx?(ll)(mx-mn+1)*n:0LL);
	// x,y -> ?==b+y-c, ?==a+b+y-c-d, ?==a+y-d
}

int main() {
	run();
	return 0;
}