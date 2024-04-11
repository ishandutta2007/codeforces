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

const int MAXN=500000;
const int MAXVAL=1000000;

int n,delcost,addcost;
int a[MAXN];

int cnt[MAXVAL+1]; // cnt[i] is #numbers <=i
ll sum[MAXVAL+1]; // sum[i] is sum of numbers <=i

void run() {
	scanf("%d%d%d",&n,&delcost,&addcost); REP(i,n) scanf("%d",&a[i]);
	REPE(i,MAXVAL) cnt[i]=sum[i]=0; REP(i,n) ++cnt[a[i]],sum[a[i]]+=a[i]; FORE(i,1,MAXVAL) cnt[i]+=cnt[i-1],sum[i]+=sum[i-1];
	ll ret=LLONG_MAX;
	int mxadd=delcost/addcost;
	for(int g=2;g<=MAXVAL;++g) {
		ll cur=0;
		for(int i=1;i<=MAXVAL;i+=g) { // [i..i+g-1)
			int a=i,b=max(a,min(MAXVAL+1,i+g-1-mxadd)),c=min(MAXVAL+1,i+g); // del [a..b) add [b..c)
			ll now=(ll)(cnt[b-1]-cnt[a-1])*delcost+((ll)(cnt[c-1]-cnt[b-1])*(i+g-1)-(sum[c-1]-sum[b-1]))*addcost;
			cur+=now;
		}
		if(cur<ret) ret=cur;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}