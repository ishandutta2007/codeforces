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
int v[MAXN],t[MAXN];
ll ans[MAXN];

multiset<ll> have; ll tsum;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&v[i]); REP(i,n) scanf("%d",&t[i]);

	tsum=0; have.clear();
	REP(i,n) {
		have.insert(tsum+v[i]);
		ans[i]=0;
		while(SZ(have)>0&&*have.begin()<tsum+t[i]) ans[i]+=*have.begin()-tsum,have.erase(have.begin());
		ans[i]+=(ll)SZ(have)*t[i]; tsum+=t[i];
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}