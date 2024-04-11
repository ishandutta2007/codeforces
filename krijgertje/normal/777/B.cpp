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

const int MAXN=1000;

int n;
char a[MAXN+1];
char b[MAXN+1];

int calcbmin() {
	int ai=0,ret=0;
	REP(bi,n) {
		if(ai<n&&a[ai]<=b[bi]) ++ai; else ++ret;
	}
	return ret;
}

int calcamax() {
	int bi=n-1,ret=0;
	for(int ai=n-1;ai>=0;--ai) {
		if(bi>=0&&b[bi]>a[ai]) --bi,++ret;
	}
	return ret;
}

void run() {
	scanf("%d%s%s",&n,a,b);
	sort(a,a+n); sort(b,b+n);
	printf("%d\n%d\n",calcbmin(),calcamax());
}

int main() {
	run();
	return 0;
}