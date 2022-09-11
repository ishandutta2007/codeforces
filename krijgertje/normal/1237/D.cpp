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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n;
int a[3*MAXN];
int ans[MAXN];

int stck[3*MAXN],nstck;
int b[3*MAXN];

void solve() {
	REP(i,n) a[n+i]=a[n+n+i]=a[i];
	
	nstck=0;
	for(int i=3*n-1;i>=0;--i) {
		int lo=-1,hi=nstck; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(2*a[stck[mi]]<a[i]) lo=mi; else hi=mi; }
		b[i]=lo==-1?INT_MAX:stck[lo];
		while(nstck>=1&&a[stck[nstck-1]]>=a[i]) --nstck;
		stck[nstck++]=i;
	}
	//printf("b:"); REP(i,3*n) printf(" %d",b[i]); puts("");

	int cur=INT_MAX;
	for(int i=3*n-1;i>=0;--i) {
		cur=min(cur,b[i]);
		if(i<n) ans[i]=cur==INT_MAX?-1:cur-i;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}