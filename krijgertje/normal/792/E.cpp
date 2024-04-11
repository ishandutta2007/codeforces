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

const int MAXN=500;

int n;
int a[MAXN];
ll ret;

void test(int sz) {
	ll cur=0;
	REP(i,n) {
		// x*sz<=a[i] x*(sz+1)>=a[i]
		// x<=a[i]/sz x>=a[i]/(sz+1)
		ll xmn=(a[i]+sz)/(sz+1),xmx=a[i]/sz;
		if(xmn>xmx) return;
		cur+=xmn;
	}
	if(cur<ret) ret=cur;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	int amx=a[0]; FOR(i,1,n) if(a[i]>amx) amx=a[i];
	ret=LLONG_MAX;
	for(int cnt=1;cnt<=amx;) {
		//printf("cnt=%d sz=%d\n",cnt,amx/cnt);
		int sz=amx/cnt; test(sz); if(sz>=2&&amx%cnt==0) test(sz-1);
		cnt=amx/sz+1;
	}
	printf("%lld\n",ret);
}


int main() {
	run();
	return 0;
}