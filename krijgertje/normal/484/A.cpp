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

ll calc(ll l,ll r) {
	if(l==r) return l;
	ll x=1; while(2*x<=r) x*=2;
	ll y=x; while(l/y==r/y) y/=2;
	ll z=r/y*y;
	if(r==z+y-1) return r;
	return z-1;
}

void run() {
	int n; cin>>n;
	REP(i,n) {
		ll l,r; cin>>l>>r;
		cout<<calc(l,r)<<endl;
	}
}

int main() {
	run();
	return 0;
}