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

const int MAXN=300000;

int n;
int a[MAXN];
int b[MAXN],nb;

int cnt[MAXN];
int ret[MAXN],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) b[i]=a[i]; nb=n; sort(b,b+nb); nb=unique(b,b+nb)-b;
	REP(i,n) a[i]=lower_bound(b,b+nb,a[i])-b;

	REP(i,nb) cnt[i]=0; nret=0; ret[nret++]=0;
	REP(i,n) {
		if(++cnt[a[i]]==1) continue;
		FORE(j,ret[nret-1],i) --cnt[a[j]];
		ret[nret++]=i+1;
	}
	--nret;
	if(nret==0) { printf("-1\n"); return; }
	printf("%d\n",nret); REP(i,nret) printf("%d %d\n",ret[i]+1,i==nret-1?n:ret[i+1]);
}

int main() {
	run();
	return 0;
}