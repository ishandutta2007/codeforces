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

const int MAXN=10000;

int n;
int a[MAXN],b[MAXN];

int calc(int ca,int cb,int na,int nb) {
	int ret=0;
	if(ca<cb) swap(ca,cb),swap(na,nb);
	if(ca>cb) {
		cb=min(nb,ca-1);
		if(cb==nb) return ret;
		++cb,++ret;
	}
	assert(ca==cb);
	if(na<nb) swap(na,nb);
	return ret+nb-cb;
}

int solve() {
	int ca=0,cb=0,ret=1;
	REP(i,n) { ret+=calc(ca,cb,a[i],b[i]); ca=a[i],cb=b[i]; }
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}