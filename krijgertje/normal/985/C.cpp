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

const int MAXN=100000;

int nbarr,neach,mxdiff,n;
int a[MAXN];

ll solve() {
	sort(a,a+n);
	int idx=0; while(idx+1<n&&a[idx+1]<=a[0]+mxdiff) ++idx;
	if(idx-0+1<nbarr) return 0;
	ll ret=0;
	int spare=n-idx-1;
	for(int i=idx;i>=0;--i) {
		if(spare>=neach-1) { ret+=a[i]; spare-=neach-1; } else ++spare;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&nbarr,&neach,&mxdiff); n=nbarr*neach; REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}