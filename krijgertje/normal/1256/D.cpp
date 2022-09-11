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

const int MAXN=1000000;

int n; ll nmove;
char s[MAXN+1];
char ans[MAXN+1];

void solve() {
	REPE(i,n) ans[i]=s[i];
	int at=0;
	ll rem=nmove;
	REP(i,n) if(ans[i]=='0') {
		int cur=min(rem,(ll)i-at);
		swap(ans[i],ans[i-cur]);
		if(i-cur==at) ++at;
		rem-=cur;
	}
}

void run() {
	scanf("%d%lld",&n,&nmove);
	scanf("%s",s); assert(strlen(s)==n);
	solve();
	printf("%s\n",ans);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}