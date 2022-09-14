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

int nsquare,nship,shiplen,nmove;
int calc(int n) { if(n<shiplen) return 0; return 1+(n-shiplen)/(shiplen+1); }

set<int> blocked;

void run() {
	scanf("%d%d%d%d",&nsquare,&nship,&shiplen,&nmove);

	int maxship=calc(nsquare);
	blocked.clear(); blocked.insert(0); blocked.insert(nsquare+1);

	int ret=-1;
	REP(i,nmove) {
		int x; scanf("%d",&x);
		set<int>::iterator after=blocked.upper_bound(x);
		set<int>::iterator before=after; --before;
		maxship=maxship-calc(*after-*before-1)+calc(x-*before-1)+calc(*after-x-1);
		blocked.insert(x);
		if(ret==-1&&maxship<nship) ret=i+1;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}