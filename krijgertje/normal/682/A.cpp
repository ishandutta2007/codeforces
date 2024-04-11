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

int n,m;

void run() {
	scanf("%d%d",&n,&m);
	ll ret=0;
	// a+b=0 mod 5, a'=a-1,b'=b-1 -> a'+b'=3 mod 5
	REP(i,5) {
		int j=(8-i)%5;
		if(i>=n||j>=m) continue;
		int a=(n-i+4)/5,b=(m-j+4)/5;
		//printf("%d,%d -> %d*%d\n",i,j,a,b);
		ret+=(ll)a*b;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}