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

const int MAXN=300000;

int n,mod,want;
int a[MAXN];

int b[MAXN];

ll solve() {
	REP(i,n) b[i]=(((ll)a[i]*a[i]%mod*a[i]%mod*a[i]-(ll)want*a[i])%mod+mod)%mod;
	sort(b,b+n);
	ll ret=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&b[r]==b[l]) ++r;
		int cnt=r-l; ret+=(ll)cnt*(cnt-1)/2;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&mod,&want);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}