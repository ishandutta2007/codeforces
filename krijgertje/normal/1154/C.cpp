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

const int KIND[7]={0,1,2,0,2,1,0};

ll na,nb,nc;

ll calc(int offset) {
	vector<ll> rem(3); rem[0]=na,rem[1]=nb,rem[2]=nc;
	ll ret=0;
	int at=offset;
	while(at!=0) {
		int x=KIND[at];
		if(rem[x]==0) return ret;
		--rem[x]; at=(at+1)%7; ++ret;
	}
	vector<int> cnt(3,0); REP(i,7) cnt[KIND[i]]++;
	ll nfull=LLONG_MAX; REP(i,3) nfull=min(nfull,rem[i]/cnt[i]);
	ret+=7*nfull; REP(i,3) rem[i]-=nfull*cnt[i];
	while(true) {
		int x=KIND[at];
		if(rem[x]==0) return ret;
		--rem[x]; at=(at+1)%7; ++ret;
	}
}

ll solve() {
	ll ret=0;
	REP(i,7) {
		ll cur=calc(i);
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%lld%lld%lld",&na,&nb,&nc);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}