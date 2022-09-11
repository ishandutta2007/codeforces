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

int len,cap,x,need;

int solve() {
	int at=0,have=cap,left=need,dir=+1,ret=0;
	if(have<x) return -1; else have-=x,at=x;
	while(true) {
		int end=dir==+1?len-x:x;
		if(left==1) {
			if(have>=end) return ret;
			have=cap,++ret;
			if(have>=end) return ret;
		} else {
			if(have>=2*end) { have-=2*end,--left,dir=-dir; continue; }
			have=cap,++ret;
			if(have>=2*end) { have-=2*end,--left,dir=-dir; continue; }
		}
		return -1;
	}
}

void run() {
	scanf("%d%d%d%d",&len,&cap,&x,&need);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}