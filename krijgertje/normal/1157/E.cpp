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

const int MAXN=200000;

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];

multiset<int> rem;

void solve() {
	rem.clear(); REP(i,n) rem.insert(b[i]);
	REP(i,n) {
		assert(SZ(rem)!=0);
		int want=(n-a[i])%n;
		auto it=rem.lower_bound(want);
		if(it==rem.end()) it=rem.begin();
		c[i]=(a[i]+*it)%n; rem.erase(it);
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",c[i]); } puts("");
}

int main() {
	run();
	return 0;
}