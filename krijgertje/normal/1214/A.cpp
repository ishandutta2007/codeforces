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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int budget,eurcost,dolcost;

int solve() {
	int ret=INT_MAX;
	for(int n5eur=0;n5eur*5*eurcost<=budget;++n5eur) {
		int cur=(budget-n5eur*5*eurcost)%dolcost;
		ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&budget,&dolcost,&eurcost);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}