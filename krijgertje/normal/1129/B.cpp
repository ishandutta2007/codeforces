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

const int MAXN=2000;
const int MINVAL=-1000000;
const int MAXVAL=+1000000;

ll want;
int ans[MAXN],nans;

bool solve() {
	FORE(k,1,MAXN-2) {
		// (x-k)*(k+1)-x>=want -> x>=(want+kk+k)/k
		ll x=(want+k*k+k+k-1)/k;
		ll diff=(x-k)*(k+1)-x-want;
		//if(k<100) printf("k=%d -> x=%lld diff=%lld (%lld vs %lld)\n",k,x,diff,(x-k)*(k+1)-x,want);
		ll a=-1-diff,b=x+diff;
		if(a>=MINVAL&&b<=MAXVAL) {
			nans=0; ans[nans++]=a; REP(i,k-1) ans[nans++]=-1; ans[nans++]=b;
			return true;
		}
	}
	return false;
}

void verify() {
	ll sum=0; REP(i,nans) sum+=ans[i];
	ll all=(ll)sum*nans;
	ll res=0,cur=0; int k=-1; REP(i,nans) { cur+=ans[i]; if(cur<0) cur=0,k=i; res=max(res,(i-k)*cur); }
	ll have=abs(all-res);
	assert(have==want);
}

void run() {
	scanf("%lld",&want);
	if(!solve()) { printf("-1\n"); return; }
	//verify();
	printf("%d\n",nans);
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}