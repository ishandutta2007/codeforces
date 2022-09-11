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

const int MAXVAL=1000000;

int g[MAXVAL+1];
int cnt[MAXVAL+1][10];

void precalc() {
	FORE(i,1,MAXVAL) {
		if(i<10) { g[i]=i; continue; }
		int j=1,k=i; while(k>0) { int d=k%10; if(d!=0) j*=d; k/=10; }
		assert(j<i); g[i]=g[j];
	}
	memset(cnt,0,sizeof(cnt));
	FORE(i,1,MAXVAL) ++cnt[i][g[i]];
	FORE(i,1,MAXVAL) REP(j,10) cnt[i][j]+=cnt[i-1][j];
}

void run() {
	precalc();
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		int ans=cnt[r][k]-cnt[l-1][k]; printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}