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

int q,n;

void run() {
	scanf("%d%d",&q,&n); --q;

	int l=1,h=100000;
	REP(i,n) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		//floor(a/x)=b -> a/(b+1)<x<=a/b
		//printf("floor(%d/x)=%d -> (%d/%d,%d/%d]\n",a,b,a,b+1,a,b);
		l=max(l,a/(b+1)+1);
		if(b!=0) h=min(h,a/b);
	}
	int lq=q/h,hq=q/l;
	//printf("[%d,%d] -> [%d,%d]\n",l,h,lq,hq);
	printf("%d\n",lq==hq?lq+1:-1);
}

int main() {
	run();
	return 0;
}