#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n;
int a[MAXN];
char b[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); scanf("%s",b);
	int lmn=-1000000000,lmx=+1000000000,rmn=-1000000000,rmx=+1000000000;
	REP(i,4) assert(b[i]=='0');
	FOR(i,4,n) {
		int mx=INT_MIN; REP(j,5) mx=max(mx,a[i-j]);
		int mn=INT_MAX; REP(j,5) mn=min(mn,a[i-j]);
		if(b[i]==b[i-1]) {
			if(b[i]=='0') {
				bool ok=false; FOR(j,1,5) if(b[i-j]!='0') ok=true; if(ok) continue;
				lmx=min(lmx,mx);
			} else {
				bool ok=false; FOR(j,1,5) if(b[i-j]!='1') ok=true; if(ok) continue;
				rmn=max(rmn,mn);
			}
		} else {
			if(b[i]=='0') {
				bool err=false; FOR(j,1,5) if(b[i-j]!='1') err=true; assert(!err);
				rmx=min(rmx,mn-1);
			} else {
				bool err=false; FOR(j,1,5) if(b[i-j]!='0') err=true; assert(!err);
				lmn=max(lmn,mx+1);
			}
		}
	}
	assert(rmn<=rmx&&lmn<=lmx&&lmn<=rmx);
	printf("%d %d\n",lmn,rmx);
}

int main() {
	run();
	return 0;
}