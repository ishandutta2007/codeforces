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

const int MAXN=100000;
const int MAXQ=100000;

int n;
ll off[MAXN];
int nq;
ll ql[MAXQ],qr[MAXQ],qans[MAXQ];

ll lim[MAXN];
ll sum[MAXN];

void solve() {
	sort(off,off+n);
	REP(i,n) lim[i]=i+1<n?off[i+1]-off[i]:LLONG_MAX;
	sort(lim,lim+n);
	sum[0]=0; REP(i,n-1) sum[i+1]=sum[i]+lim[i];

	REP(i,nq) {
		ll len=qr[i]-ql[i]+1;
		int lo=-1,hi=n-1;
		while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(lim[mi]>len) hi=mi; else lo=mi; }
		int at=hi;
		qans[i]=sum[at]+(n-at)*len;
	}
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&off[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%lld%lld",&ql[i],&qr[i]);
	solve();
	REP(i,nq) { if(i!=0) printf(" "); printf("%lld",qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}