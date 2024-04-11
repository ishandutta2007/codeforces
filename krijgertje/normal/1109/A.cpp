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

int n;
int a[MAXN];

int asum[MAXN+1];

int b[MAXN+1];

ll solve() {
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]^a[i];
	//printf("asum:"); REPE(i,n) printf(" %d",asum[i]); puts("");

	REPE(i,n) b[i]=2*asum[i]+i%2;
	sort(b,b+n+1);
	ll ret=0;
	for(int l=0,r=l;l<=n;l=r) {
		while(r<=n&&b[l]==b[r]) ++r;
		int cnt=r-l;
		ret+=(ll)cnt*(cnt-1)/2;
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