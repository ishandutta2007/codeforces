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

ll n,k;



void run() {
	scanf("%lld%lld",&n,&k);
	if(k==1) { printf("%lld\n",n); return; }
	ll gg=-1;
	for(ll g=1;g*g<=n;++g) if(n%g==0) {
		{
			ll x=g;
			//printf("testing g=%lld 2*%lld/%lld<(%lld+1)*%lld\n",g,n,k,k,g);
			if(2*n/k<(k+1)*x) continue;
			if(gg==-1||x>gg) gg=x;
		}
		{
			ll x=n/g;
			if(2*n/k<(k+1)*x) continue;
			if(gg==-1||x>gg) gg=x;
		}
	}
	if(gg==-1) { printf("-1\n"); return; }
	ll rem=n/gg;
	FORE(i,1,k) {
		if(i!=1) printf(" ");
		ll cur=i==k?rem:i; printf("%lld",cur*gg); rem-=cur;
	}
	puts("");
}

int main() {
	run();
	return 0;
}