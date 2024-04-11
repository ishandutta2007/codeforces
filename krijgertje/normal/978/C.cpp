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

const int MAXN=200000;

int n,nq;
ll a[MAXN];
ll asum[MAXN+1];

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%lld",&a[i]);
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	REP(i,nq) {
		ll x; scanf("%lld",&x); --x; assert(x<asum[n]);
		int idx=upper_bound(asum,asum+n+1,x)-asum-1; assert(idx>=0&&idx<n&&asum[idx]<=x&&asum[idx+1]>x);
		printf("%d %lld\n",idx+1,x-asum[idx]+1);
	}

}

int main() {
	run();
	return 0;
}