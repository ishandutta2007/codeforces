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

const int MAXSPECIAL=100000;

ll ntotal; int nspecial; ll pagesize;
ll special[MAXSPECIAL];

int solve() {
	int nremoved=0,at=0,ret=0;
	while(nremoved<nspecial) {
		ll page=(special[at]-nremoved)/pagesize;
		while(at<nspecial&&(special[at]-nremoved)/pagesize==page) ++at;
		++ret,nremoved=at;
	}
	return ret;
}

void run() {
	scanf("%lld%d%lld",&ntotal,&nspecial,&pagesize);
	REP(i,nspecial) scanf("%lld",&special[i]),--special[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}