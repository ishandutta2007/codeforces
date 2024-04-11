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

const int MAXN=100000;

int n;
int a[2*MAXN];

void run() {
	scanf("%d",&n);
	REP(i,2*n) scanf("%d",&a[i]);

	sort(a,a+2*n);
	ll ret=LLONG_MAX;
	REPE(i,n) {
		int dx=a[i+n-1]-a[i];
		int dy=(i==n?a[n-1]:a[2*n-1])-(i==0?a[n]:a[0]);
		ll cur=(ll)dx*dy;
		ret=min(ret,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}