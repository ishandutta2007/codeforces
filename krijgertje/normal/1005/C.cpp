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

const int MAXN=120000;

int n;
int a[MAXN];

bool ok[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	
	sort(a,a+n);
	REP(i,n) {
		ok[i]=false;
		for(ll want=2;want<=a[i]+1000000000;want*=2) if(want>a[i]) {
			int idx=lower_bound(a,a+n,(int)(want-a[i]))-a;
			if(idx>=n||a[idx]!=want-a[i]) continue;
			if(idx==i&&(idx+1>=n||a[idx+1]!=a[i])) continue;
			ok[i]=true; break;
		}
	}
	int ret=0; REP(i,n) if(!ok[i]) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}