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

const int MAXN=200000;

int n;
int a[MAXN];

int b[MAXN],nb;

ll solve() {
	sort(a,a+n);
	for(int l=0,r=l;l<n;l=r) { while(r<n&&a[l]==a[r]) ++r; b[nb++]=r-l; }
	sort(b,b+n); reverse(b,b+n);
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");
	ll ret=0;
	for(int len=1;(1LL<<(len-1))<=b[0]&&len<=nb;++len) {
		int lim=INT_MAX;
		REP(i,len) {
			int cur=b[i],mlt=1<<(len-i-1);
			lim=min(lim,cur/mlt);
		}
		//printf("%d: lim=%d\n",len,lim);
		ret=max(ret,(ll)lim*((1LL<<len)-1));
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}