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
#include <chrono>
#include <chrono>
#include <random>
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

int n,c;
int a[MAXN-1];
int b[MAXN-1];
ll ans[MAXN];

ll bsum[MAXN];

void solve() {
	bsum[0]=0; REP(i,n-1) bsum[i+1]=bsum[i]+b[i];
	ans[0]=0;
	ll best=ans[0]-bsum[0];
	FOR(i,1,n) {
		ll stairs=ans[i-1]+a[i-1];
		ll lift=best+c+bsum[i];
		ans[i]=min(stairs,lift);
		best=min(best,ans[i]-bsum[i]);
	}
}

void run() {
	scanf("%d%d",&n,&c);
	REP(i,n-1) scanf("%d",&a[i]);
	REP(i,n-1) scanf("%d",&b[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}