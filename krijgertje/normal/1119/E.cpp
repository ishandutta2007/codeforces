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

int n;
int a[MAXN];

ll sum[MAXN+1];

ll solve() {
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+a[i];
	ll ret=0,need=0;
	for(int i=n-1;i>=0;--i) {
		ll cur=a[i]/2,rem=a[i]-2*cur;
		if(need+cur>rem+sum[i]) {
			//printf("ret=%lld need=%lld sum=%lld a[i]=%d -> cur=%lld rem=%lld [%lld vs %lld]\n",ret,need,sum[i],a[i],cur,rem,need+cur,rem+sum[i]);
			ll lhs=need+cur,rhs=rem+sum[i];
			ll x=(lhs-rhs+2)/3;
			cur-=x,rem+=2*x;
		}
		assert(need+cur<=rem+sum[i]);
		need+=cur; need=max(0LL,need-rem); ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}