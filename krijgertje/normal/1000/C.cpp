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
ll la[MAXN],ra[MAXN];
ll a[2*MAXN]; int na;

int lb[MAXN],rb[MAXN];

int sum[2*MAXN];
ll cnt[MAXN+1];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld%lld",&la[i],&ra[i]);

	na=0; REP(i,n) a[na++]=la[i],a[na++]=ra[i]+1;
	sort(a,a+na); na=unique(a,a+na)-a;
	REP(i,n) lb[i]=lower_bound(a,a+na,la[i])-a,rb[i]=lower_bound(a,a+na,ra[i]+1)-a;

	REP(i,na) sum[i]=0;
	REP(i,n) ++sum[lb[i]],--sum[rb[i]];
	REP(i,na-1) sum[i+1]+=sum[i];

	REPE(i,n) cnt[i]=0;
	REP(i,na-1) cnt[sum[i]]+=a[i+1]-a[i];
	FORE(i,1,n) { if(i!=1) printf(" "); printf("%lld",cnt[i]); } puts("");
}

int main() {
	run();
	return 0;
}