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

const int MAXN=2000;

int n,cnt;
int a[MAXN];

pair<int,int> o[MAXN];

int use[MAXN];
int ans[MAXN];


void run() {
	scanf("%d%d",&n,&cnt); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) o[i]=MP(-a[i],i); sort(o,o+n);
	
	ll sum=0;
	REP(i,cnt) sum+=-o[i].first,use[i]=o[i].second;
	sort(use,use+cnt);
	REP(i,cnt) ans[i]=(i==cnt-1?n:use[i]+1)-(i==0?0:use[i-1]+1);

	printf("%lld\n",sum);
	REP(i,cnt) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}