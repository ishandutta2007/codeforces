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

int n;

int query(int a,int b,int c) {
	vector<int> x; x.PB(a);
	vector<int> y; FORE(i,b,c) if(i!=a) y.PB(i);
	printf("%d %d",SZ(x),SZ(y)); REPSZ(i,x) printf(" %d",x[i]+1); REPSZ(i,y) printf(" %d",y[i]+1); puts(""); fflush(stdout);
	int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret;
}

int solve() {
	int want=query(0,1,n-1);
	int lo=1,hi=n;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		int have=query(0,1,mi-1);
		if(have==want) hi=mi; else lo=mi;
	}
	return query(lo,0,n-1);
}

void run() {
	scanf("%d",&n); if(n==-1) exit(0);
	int ans=solve();
	printf("-1 %d\n",ans); fflush(stdout);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run();
	return 0;
}