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

const int MAXN=300000;
const int NBIT=62;

int n;
ll val[MAXN],mask[MAXN];

int cnt[MAXN];

ll solve() {
	ll sum=0; REP(i,n) sum+=val[i];
	assert(sum!=0);
	if(sum<0) { sum=-sum; REP(i,n) val[i]=-val[i]; }

	ll ret=0;
	REP(i,n) cnt[i]=0;
	REP(bit,NBIT) {
		ll with=0,without=0;
		REP(i,n) if((mask[i]&(1LL<<bit))!=0&&(mask[i]-(1LL<<bit))<(1LL<<bit)) {
			if(cnt[i]%2==0) with+=val[i]; else without+=val[i];
		}
		if(with>without) {
			ret|=1LL<<bit;
			REP(i,n) if((mask[i]&(1LL<<bit))!=0) ++cnt[i];
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld%lld",&val[i],&mask[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}