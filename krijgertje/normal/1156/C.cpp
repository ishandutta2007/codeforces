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

int n,lim;
int x[MAXN];

bool can(int k) {
	if(2*k>n) return false;
	REP(i,k) if(x[n-k+i]-x[i]<lim) return false;
	return true;
}

int solve() {
	sort(x,x+n);
	int lo=0,hi=n+1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(can(mi)) lo=mi; else hi=mi; }
	return lo;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d",&x[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}