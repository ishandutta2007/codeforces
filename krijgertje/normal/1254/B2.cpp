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

int n;
int a[MAXN];

int b[MAXN];
int c[MAXN];

vector<ll> getprimes(ll x) {
	vector<ll> ret;
	for(int i=2;(ll)i*i<=x;++i) if(x%i==0) { ret.PB(i); while(x%i==0) x/=i; }
	if(x>1) ret.PB(x);
	return ret;
}

ll calc(int l,int r,ll sz) {
	ll sum=0; FORE(i,l,r) sum+=c[i]; assert(sum==sz);
	ll before=0,on=0,after=sz;
	//printf("c:"); FORE(i,l,r) printf(" %d",c[i]); puts("");
	FORE(i,l,r) {
		before+=on,on=c[i],after-=c[i];
		//printf("before=%lld on=%lld after=%lld\n",before,on,after);
		if(2*before<=sz&&2*after<=sz) {
			ll ret=0;
			FORE(j,l,r) ret+=(ll)c[j]*abs(i-j);
			return ret;
		}
	}
	assert(false); return -1;
}

ll calc(ll sz) {
	//printf("calc(%lld)\n",sz);
	REP(i,n) b[i]=a[i]%sz;
	ll ret=0;
	for(int l=0,r=l;l<n;l=r) {
		ll sum=0;
		while(r<n&&sum<sz) sum+=b[r++];
		if(sum==0) break;
		assert(sum>=sz);
		ll excess=sum-=sz;
		FOR(i,l,r) c[i]=b[i];
		c[r-1]-=excess;
		ret+=calc(l,r-1,sz);
		b[r-1]=excess;
		if(excess>0) --r;
	}
	return ret;
}

ll solve() {
	ll sum=0; REP(i,n) sum+=a[i]; assert(sum>0);
	vector<ll> p=getprimes(sum);
	ll ret=LLONG_MAX;
	REPSZ(i,p) {
		ll cur=calc(p[i]);
		ret=min(ret,cur);
	}
	return ret==LLONG_MAX?-1:ret;
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