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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 50;

int a[MAXN], na;
int b[MAXN], nb;

void run() {
	scanf("%d%d", &na, &nb); REP(i, na) scanf("%d", &a[i]); REP(i, nb) scanf("%d", &b[i]); sort(a, a + na); sort(b, b + nb);
	ll ret = LLONG_MAX;
	REP(i, na) {
		int mna = a[i == 0 ? 1 : 0], mxa = a[i == na - 1 ? na - 2 : na - 1];
		int mnb = b[0], mxb = b[nb - 1];
		ll cur = LLONG_MIN;
		cur = max(cur, (ll)mxa*mxb);
		cur = max(cur, (ll)mna*mnb);
		cur = max(cur, (ll)mxa*mnb);
		cur = max(cur, (ll)mna*mxb);
		ret = min(ret, cur);
	}
	printf("%lld\n", ret);
}

int main() {
	run();
	return 0;
}