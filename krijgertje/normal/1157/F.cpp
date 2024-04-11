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
int nans;
int ans[MAXN];

int b[MAXN],bcnt[MAXN],nb;

int c[MAXN],nc;

void solve() {
	sort(a,a+n);
	nb=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&a[r]==a[l]) ++r; b[nb]=a[l],bcnt[nb]=r-l,++nb; }
	//printf("b:"); REP(i,nb) printf(" %d*%d",bcnt[i],b[i]); puts("");

	nans=0;
	for(int l=0,r=l;l<n;l=r) {
		++r; while(r<n&&b[r]==b[r-1]+1&&bcnt[r]>=2) ++r;
		nc=0; FOR(i,l,r) REP(j,bcnt[i]) c[nc++]=b[i];
		if(r<n&&b[r]==b[r-1]+1) c[nc++]=b[r];
		//printf("c:"); REP(i,nc) printf(" %d",c[i]); puts("");
		if(nc>nans) { nans=0; REP(i,nc) if(i%2==0) ans[nans++]=c[i]; for(int i=nc-1;i>=0;--i) if(i%2==1) ans[nans++]=c[i]; }
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nans);
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}