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

const int MAXN = 200000;

int n;
vector<int> sal[MAXN];
int mxsal[MAXN];

ll solve() {
	REP(i, n) { mxsal[i] = sal[i][0]; FORSZ(j, 1, sal[i]) mxsal[i] = max(mxsal[i], sal[i][j]); }
	int globmx = mxsal[0]; FOR(i, 1, n) globmx = max(globmx, mxsal[i]);
	ll ret = 0; REP(i, n) ret += (ll)(globmx - mxsal[i])*SZ(sal[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int cnt; scanf("%d", &cnt); sal[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &sal[i][j]); }
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}