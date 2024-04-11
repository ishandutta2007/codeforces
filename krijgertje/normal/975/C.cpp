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
const int MAXQ=200000;

int n,nq;
int a[MAXN];
ll q[MAXQ];

ll asum[MAXN+1];

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]); REP(i,nq) scanf("%lld",&q[i]);

	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	ll qsum=0;
	REP(qi,nq) {
		qsum+=q[qi];
		int idx=upper_bound(asum,asum+n+1,qsum)-asum;
		if(idx>n) { printf("%d\n",n); qsum=0; } else { printf("%d\n",n-idx+1); }
	}
}

int main() {
	run();
	return 0;
}