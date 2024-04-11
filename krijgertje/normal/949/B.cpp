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


ll solve(ll n,ll idx) { // numbers 0..n-1, what will be position idx
	if(idx%2==0) return idx/2;
	ll n1=(n+1)/2,n2=n-n1;
	return n1+solve(n2,n1==n2?(idx-1)/2:idx==1?n2-1:(idx-3)/2);
}

ll n; int nq;

void run() {
	scanf("%lld%d",&n,&nq);
	REP(qi,nq) {
		ll idx; scanf("%lld",&idx); --idx;
		ll ans=1+solve(n,idx);
		printf("%lld\n",ans);
	}
}

int main() {
	run();
	return 0;
}