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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n;
int a[MAXN];

int b[MAXN],nb;

int solve() {
	sort(a,a+n);
	nb=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&a[r]==a[l]) ++r; b[nb++]=r-l; }
	sort(b,b+nb); reverse(b,b+nb);
	int last=INT_MAX; int ret=0;
	REP(i,nb) { int cur=max(0,min(last-1,b[i])); ret+=cur; last=cur; }
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run();
	return 0;
}