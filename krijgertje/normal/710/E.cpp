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


int n,x,y;

ll solve(int n) {
	ll ret=(ll)n*x;
	if(n%2==0&&n>0) ret=min(ret,y+solve(n/2));
	if(n%2==1&&n>1) ret=min(ret,x+y+solve((n-1)/2));
	if(n%2==1&&n>1) ret=min(ret,x+y+solve((n+1)/2));
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&x,&y);
	ll ret=solve(n); printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}