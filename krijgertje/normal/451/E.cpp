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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

const int MOD=1000000007;

int n;
ll want;
ll cap[20];

ll inv[20];

ll C(ll n,int k) {
	n%=MOD;
	ll ret=1;
	REP(i,k) ret=ret*(n-i)%MOD*inv[i+1]%MOD;
	return ret;
}
ll mypow(ll x,ll n) { if(n==0) return 1; if(n%2==1) return x*mypow(x,n-1)%MOD; return mypow(x*x%MOD,n/2); }

void run() {
	REP(i,20) inv[i]=mypow(i,MOD-2);

	cin>>n>>want;
	REP(i,n) cin>>cap[i];

	ll ret=0;
	REP(i,1<<n) {
		int cnt=0; ll need=0;
		REP(j,n) if(i&(1<<j)) { ++cnt; need+=cap[j]+1; }
		if(need>want) continue;
		ll cur=C(want-need+n-1,n-1);
		//printf("%x -> %lld (%d)\n",i,cur,cnt);
		if(cnt%2==0) ret+=cur; else ret-=cur;
	}
	ret%=MOD; if(ret<0) ret+=MOD;
	cout<<ret<<endl;
}


int main() {
	run();
	return 0;
}