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
#include <bitset>
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

const int MAXANS=100000;

int n;

ll ans[MAXANS]; int nans;

vector<int> dv;

void solve() {
	dv.clear(); for(int i=1;(ll)i*i<=n;++i) if(n%i==0) { dv.PB(i); if(i!=n/i) dv.PB(n/i); } sort(dv.begin(),dv.end());
	//printf("dv:"); REPSZ(i,dv) printf(" %d",dv[i]); puts("");

	nans=0;
	REPSZ(i,dv) {
		int d=dv[i],step=n/d;
		ll cur=(ll)d*(d-1)/2; cur*=step; cur+=d; ans[nans++]=cur;
	}

	sort(ans,ans+nans);
}

void run() {
	scanf("%d",&n);
	solve();
	REP(i,nans) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}