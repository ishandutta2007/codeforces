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

ll a1,b1,a2,b2,L,R;

ll egcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) { x=1,y=0; return a; }
	ll g=egcd(b,a%b,x,y);
	swap(x,y); y-=x*(a/b); return g;
}

ll calc(ll lim,ll off,ll per) { if(off>lim) return 0; return (lim-off)/per+1; }
ll solve() {
	ll x,y;
	ll g=egcd(a1,a2,x,y); // x*a1+y*a2=g
	ll db=b2-b1;
	if(db%g!=0) return 0;
	ll t=db/g;
	ll k=x*t,l=-y*t;
	if(k<0) { ll z=(-k+a2/g-1)/(a2/g); k+=z*(a2/g); l+=z*(a1/g); }
	if(l<0) { ll z=(-l+a1/g-1)/(a1/g); k+=z*(a2/g); l+=z*(a1/g); }
	{ ll z=min(k/(a2/g),l/(a1/g)); k-=z*(a2/g); l-=z*(a1/g); }
	ll off=a1*k+b1,per=a1*(a2/g);
	return calc(R,off,per)-calc(L-1,off,per);
}

void run() {
	scanf("%lld%lld%lld%lld%lld%lld",&a1,&b1,&a2,&b2,&L,&R);
	printf("%lld\n",solve());
	



}

int main() {
	run();
	return 0;
}