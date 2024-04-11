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
typedef struct R { int have,need,can,fst; } R;
bool operator<(const R &a,const R &b) { return a.can<b.can; }


int n,have;
R r[MAXN];

int solve() {
	sort(r,r+n);
	int left=have; int ret=0; ll inc=0;
	for(int at=0,to=at;at<n;at=to) {
		while(to<n&&r[at].can==r[to].can) ++to;
		if(ret<r[at].can&&inc>left) return ret;
		int diff=r[at].can-ret; if(diff*inc>left) return ret+left/inc; else left-=diff*inc,ret+=diff;
		ll fst=inc; FOR(i,at,to) inc+=r[i].need,fst+=r[i].fst;
		if(fst>left) return ret; else left-=fst,++ret;
	}
	return ret+left/inc;
}


void run() {
	scanf("%d%d",&n,&have); REP(i,n) scanf("%d",&r[i].need); REP(i,n) scanf("%d",&r[i].have); REP(i,n) r[i].can=r[i].have/r[i].need,r[i].fst=r[i].need-r[i].have%r[i].need;
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}