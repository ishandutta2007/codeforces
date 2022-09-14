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
#include <list>  
#include <cassert>
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

const int MOD=1000000007;

ll mpow(ll x,int n) { ll ret=1; while(n>0) { if(n%2==1) ret=ret*x%MOD; x=x*x%MOD; n/=2; } return ret; }
ll inverse(ll x) { return mpow(x,MOD-2); }

ll fact[1000001];
ll go(int sum,int a,int b,int n) {
	if(sum>n*b) return 0;
	ll ret=0;
	if(sum>0&&(n*b-sum)%(b-a)==0) {
		// i*a+(n-i)*b=sum -> i=(n*b-sum)/(b-a)
		int i=(n*b-sum)/(b-a);
		if(i<=n) ret+=fact[n]*inverse(fact[i])%MOD*inverse(fact[n-i])%MOD;
	}
	ret+=go(sum*10+a,a,b,n);
	ret+=go(sum*10+b,a,b,n);
	return ret;
}

void run() {
	int a,b,n; scanf("%d%d%d",&a,&b,&n); if(a>b) swap(a,b);
	fact[0]=1; FORE(i,1,n) fact[i]=fact[i-1]*i%MOD;
	ll ret=go(0,a,b,n)%MOD;
	printf("%d\n",(int)ret);
}

int main() {
	run();
	return 0;
}