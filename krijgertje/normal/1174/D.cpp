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

const int MAXN=18;

int n,forbidden;
int ans[1<<MAXN],nans;

int pref[1<<MAXN],npref;

void solve() {
	vector<int> use;
	REP(i,1<<n) if(i<(i^forbidden)) use.PB(i);
	assert(SZ(use)>=1&&use[0]==0);
	REPSZ(i,use) pref[i]=use[i];
	nans=SZ(use)-1; REP(i,nans) ans[i]=pref[i+1]^pref[i];
}

void run() {
	scanf("%d%d",&n,&forbidden);
	solve();
	printf("%d\n",nans);
	if(nans>0) { REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts(""); }
}

int main() {
	run();
	return 0;
}