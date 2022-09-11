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

int n,lim;
int a[MAXN];
int sum[MAXN+1]; // sum[i] is amount of money on account at the beginning of day i (assuming we don't deposit anything)
int mxonorafter[MAXN]; // mxafter[i] is maximum amount of money on or after day i
int bound[MAXN]; // bound[i] is the maximum amount of money we can deposit on days <= i (assuming we don't deposit anything afterwards)

void run() {
	scanf("%d%d",&n,&lim); REP(i,n) scanf("%d",&a[i]);
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+a[i];
	REPE(i,n) if(sum[i]>lim) { printf("-1\n"); return; }
	mxonorafter[n-1]=max(sum[n-1],sum[n]);
	for(int i=n-2;i>=0;--i) mxonorafter[i]=max(sum[i],mxonorafter[i+1]);
	REP(i,n) bound[i]=lim-mxonorafter[i];
	int ret=0,have=0;
	REP(i,n) if(a[i]==0&&sum[i]+have<0) {
		int now=bound[i]-have; have+=now; ++ret;
		if(sum[i]+have<0) { printf("-1\n"); return; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}