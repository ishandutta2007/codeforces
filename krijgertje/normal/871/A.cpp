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

int solve(int n) {
	int ret=0;
	if(n%2==1) {
		if(n<9) return -1;
		++ret,n-=9;
	}
	if(n==2) return -1;
	if(n%4==2) ++ret,n-=6;
	//printf("%d %d\n",ret,n);
	return ret+n/4;
}

void run() {
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int n; scanf("%d",&n);
		printf("%d\n",solve(n));
	}
}

int main() {
	run();
	return 0;
}