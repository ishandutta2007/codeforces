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

const int MAXK=50;
const int MAXN=35000;

int n,K;
int a[MAXN];

int dp[MAXK+1][MAXN+1]; // dp[k][i] = maximum score for at most k boxes for [0..i)

typedef struct Counter {
	int l,r,ans; //[l,r)
	int cnt[MAXN+1];

	Counter() { l=r=ans=0; memset(cnt,0,sizeof(cnt)); }
	void add(int idx) { if(++cnt[a[idx]]==1) ++ans; }
	void rem(int idx) { if(--cnt[a[idx]]==0) --ans; }
	int calc(int ql,int qr) {
		assert(ql<=qr);
		while(ql<l) add(--l);
		while(qr>r) add(r++);
		while(ql>l) rem(l++);
		while(qr<r) rem(--r);
		//printf("[%d..%d)=%d\n",ql,qr,ans);
		return ans;
	}
} Counter;
Counter counter;


void solve(int l,int r,int pl,int pr,int k) {
	int m=l+(r-l)/2;
	int res=-1,popt=-1,cpr=min(pr,m); FORE(p,pl,cpr) { int cur=dp[k-1][p]+counter.calc(p,m); if(cur>res) res=cur,popt=p; } dp[k][m]=res;
	//printf("%d: solve(%d..%d,%d..%d): %d->%d (%d)\n",k,l,r,pl,pr,m,res,popt);
	if(l<m) solve(l,m-1,pl,popt,k);
	if(m<r) solve(m+1,r,popt,pr,k);
}


void run() {
	scanf("%d%d",&n,&K); REP(i,n) scanf("%d",&a[i]);
	REPE(i,n) dp[0][i]=0;
	FORE(k,1,K) solve(0,n,0,n,k);
	printf("%d\n",dp[K][n]);
}

int main() {
	run();
	return 0;
}