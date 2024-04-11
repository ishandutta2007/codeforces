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

int n;
int a[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); sort(a,a+n);
	ll ret=0;
	for(ll want=1;want<=2*a[n-1];want*=2) {
		int l=0,r=n-1;
		while(l<r) {
			if(a[l]+a[r]>want) { --r; continue; }
			if(a[l]+a[r]<want) { ++l; continue; }
			if(a[l]==a[r]) { int cnt=r-l+1; ret+=(ll)cnt*(cnt-1)/2; break; }
			int nl=1,nr=1; while(a[l+1]==a[l]) ++l,++nl; while(a[r-1]==a[r]) --r,++nr; ++l,--r; ret+=(ll)nl*nr;
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}