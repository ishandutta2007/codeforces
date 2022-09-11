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

const int MAXN=200000;

int n;
int a[MAXN];

vector<int> stop[MAXN];

int bit[MAXN+1];
int bget(int idx) {
	++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret;
}
void bmod(int idx,int by) {
	++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; }
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) if(a[i]<n&&i<a[i]) stop[a[i]].PB(i);
	
	ll ret=0;
	REP(i,n) {
		REPSZ(j,stop[i]) bmod(stop[i][j],-1);
		int lim=min(n-1,a[i]-1);
		ret+=bget(lim);
		if(i<a[i]) bmod(i,+1);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}