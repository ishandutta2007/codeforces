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

int n,sz;
int a[MAXN];

pair<int,int> b[MAXN]; int nb;
int ret[MAXN],nret;
int cur[MAXN],ncur;

bool can(int cnt) {
	ncur=0;
	REP(i,nb) { int freq=b[i].second/cnt; while(freq>0&&ncur<sz) cur[ncur++]=b[i].first,--freq; }
	return ncur>=sz;
}

void solve() {
	sort(a,a+n);
	nb=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&a[l]==a[r]) ++r; b[nb++]=MP(a[l],r-l); }
	int l=0,r=n/sz+1;
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(can(m)) { l=m; nret=ncur; REP(i,ncur) ret[i]=cur[i]; } else r=m;
	}
}

void run() {
	scanf("%d%d",&n,&sz);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}