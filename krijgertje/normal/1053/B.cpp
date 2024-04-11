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

int n;
ll a[MAXN];

int cnt[MAXN];
int sum[MAXN+1];




ll solve() {
	REP(i,n) { cnt[i]=0; for(ll x=a[i];x!=0;x/=2) cnt[i]+=x&1; }
	//printf("cnt:"); REP(i,n) printf(" %d",cnt[i]); puts("");

	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+cnt[i];
	int gmx=0; REP(i,n) gmx=max(gmx,cnt[i]);

	ll even=0,odd=0,ret=0;
	REPE(i,n) {
		if(sum[i]%2==0) {
			ret+=even; ++even;
		} else {
			ret+=odd; ++odd;
		}
		for(int j=i-1,cmx=0;j>=0&&sum[i]-sum[j]<=2*gmx;--j) { cmx=max(cmx,cnt[j]); if((sum[i]-sum[j])%2==0&&2*cmx>sum[i]-sum[j]) --ret; }
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}