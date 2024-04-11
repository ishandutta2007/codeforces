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

const int MAXN=200000;

int n,lim;
int a[MAXN];

ll solve() {
	sort(a,a+n); reverse(a,a+n);
	ll sum=0; ll ret=0;
	REP(i,n-1) {
		sum+=a[i];
		while(sum-(ll)(i+1)*a[i+1]>lim) {
			ll x=(sum-lim+i)/(i+1);
			++ret; sum=(i+1)*x;
		}
	}
	if(sum>(ll)(n-1)*a[n-1]) ++ret;
	return ret;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}