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

const int MAXN=200000;

int n;
int a[MAXN];

ll pref[MAXN+1];
ll suff[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	pref[0]=0; REP(i,n) pref[i+1]=pref[i]+a[i];
	suff[0]=0; REP(i,n) suff[i+1]=suff[i]+a[n-i-1];
	
	ll sum=pref[n],ret=0; int pi=0,si=0;
	while(pi<=n&&si<=n) {
		if(pref[pi]<suff[si]) { ++pi; continue; }
		if(suff[si]<pref[pi]) { ++si; continue; }
		ll cur=pref[pi]; ++pi,++si;
		if(2*cur<=sum) ret=max(ret,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}