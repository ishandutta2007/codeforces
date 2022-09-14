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
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

const int MOD=1000000007;

// first*a+second*b=gcd(a,b)
pair<ll,ll> egcd(ll a,ll b) {
	if(b==0) return MP(1LL,0LL);
	pair<ll,ll> res=egcd(b,a%b);
	return MP(res.second,res.first-a/b*res.second);
}

// x*ret+?*MOD=1
ll inverse(ll x) {
	ll ret=egcd(x,MOD).first%MOD; if(ret<0) ret+=MOD; /*printf("inverse(%lld)=%lld\n",x,ret);*/ return ret;
}

void run() {
	int n; scanf("%d",&n);
	//(2n-1 choose n-1)*2-n
	ll num=1,den=1;
	REP(i,n-1) { num=num*(2*n-1-i)%MOD; den=den*(i+1)%MOD; }
	ll ret=num*inverse(den)%MOD;
	ret=(2*ret+MOD-n)%MOD;
	cout<<ret<<endl;
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}