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

const int MAXN=1000;

int n;
int a[MAXN+1];

int d[MAXN];
int ret[MAXN],nret;

void solve() {
	REP(i,n) d[i]=a[i+1]-a[i];
	nret=0;
	FORE(per,1,n) {
		bool ok=true; for(int i=per;i<n;++i) if(d[i]!=d[i-per]) { ok=false; break; } if(ok) ret[nret++]=per;
	}
}

void run() {
	scanf("%d",&n);
	a[0]=0; FORE(i,1,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}