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

int solve() {
	if(n<=2) return 0;
	int ret=INT_MAX;
	FORE(d0,-1,+1) FORE(d1,-1,+1) {
		int a0=a[0]+d0,a1=a[1]+d1,diff=a1-a0;
		int cnt=(d0!=0?1:0)+(d1!=0?1:0); bool ok=true;
		FOR(i,2,n) { int have=a[i]; ll want=a0+(ll)i*diff; if(abs(have-want)>1) ok=false; else if(have!=want) ++cnt; }
		//printf("%d %d -> %d -> %d (%s)\n",d0,d1,diff,cnt,ok?"yes":"no");
		if(ok) ret=min(ret,cnt);
	}
	return ret==INT_MAX?-1:ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}