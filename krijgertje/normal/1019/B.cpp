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

int query(int x) {
	printf("? %d\n",x+1); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}

int solve() {
	if(n%4==2) return -1;
	int a=0,b=n/2,diff=query(b)-query(a),va=+diff,vb=-diff;
	if(diff==0) return a;
	if(va<0) swap(a,b),swap(va,vb);
	while(true) {
		int c=(a+b)/2; assert(c!=a&&c!=b); int vc=query((c+n/2)%n)-query(c);
		if(vc==0) return c;
		if(vc>0) a=c,va=vc; else b=c,vb=vc;
	}
}

void run() {
	scanf("%d",&n);
	int ans=solve();
	printf("! %d\n",ans==-1?-1:ans+1); fflush(stdout);
}

int main() {
	run();
	return 0;
}