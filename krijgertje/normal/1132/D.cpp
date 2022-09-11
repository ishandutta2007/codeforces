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
const int MAXLEN=200000;

int n,len;
ll a[MAXN];
int b[MAXN];

int c[MAXLEN];

bool can(ll x) {
	//printf("testing %lld\n",x);
	REP(i,len) c[i]=0;
	int cnt=0;
	REP(i,n) {
		ll have=a[i]; ll t=0;
		while(t<len-1) {
			if(have>=b[i]) { ll full=have/b[i]; have-=full*b[i],t+=full; continue; }
			//printf("\t%d needs charge at %lld (currently %lld)\n",i,t,have);
			c[t]++; have+=x; ++cnt;
			if(cnt>len) return false;
		}
	}
	//printf("c:"); REP(i,len) printf(" %d",c[i]); puts("");
	FOR(i,1,len) c[i]+=c[i-1];
	REP(i,len) if(c[i]>i+1) return false;
	return true;
}

ll solve() {
	ll lo=-1,hi=0; REP(i,n) hi=max(hi,(ll)b[i]*len);
	if(!can(hi)) return -1;
	while(lo+1<hi) { ll mi=lo+(hi-lo)/2; if(can(mi)) hi=mi; else lo=mi; }
	return hi;
}

void run() {
	scanf("%d%d",&n,&len);
	REP(i,n) scanf("%lld",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}