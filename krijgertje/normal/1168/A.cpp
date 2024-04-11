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

const int MAXN=300000;

int n,mod;
int a[MAXN];

bool can(int lim) {
	int prv=0;
	REP(i,n) {
		int cur=a[i];
		if(cur<=prv) {
			int diff=prv-cur;
			if(lim<diff) return false;
		} else {
			if(cur+lim>=mod+prv) {
				// ok
			} else {
				prv=cur;
			}
		}
	}
	return true;
}

int solve() {
	int l=-1,h=mod;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	return h;
}

void run() {
	scanf("%d%d",&n,&mod);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}