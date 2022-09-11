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


int a,b;

int solve() {
	if(a==b) return 0;
	int d=abs(b-a);
	vector<int> gopt;
	for(int i=1;(ll)i*i<=d;++i) if(d%i==0) { gopt.PB(i); if(i*i!=d) gopt.PB(d/i); }
	ll res=(ll)a*b; int ret=0;
	REPSZ(i,gopt) {
		int g=gopt[i];
		int k=(-a%g+g)%g;
		ll cur=(ll)(a+k)/g*(b+k);
		if(cur<res||cur==res&&k<ret) res=cur,ret=k;
	}
	return ret;
}

void run() {
	scanf("%d%d",&a,&b);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}