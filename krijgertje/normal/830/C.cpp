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

const int MAXN=100;


int n; ll limit;
int a[MAXN];

void run() {
	scanf("%d%lld",&n,&limit); REP(i,n) scanf("%d",&a[i]);

	ll ret=-1;
	ll d=1;
	while(true) {
		//printf("d=%lld\n",d);
		ll nd=LLONG_MAX;
		ll have=0,sum=0;
		REP(i,n) {
			ll x=(a[i]+d-1)/d;
			have+=(ll)x*d-a[i]; sum+=x;
			if(x==1) continue;
			ll cur=(a[i]+x-2)/(x-1);
			nd=min(nd,cur);
		}
		if(nd==d) nd=d+1;
		if(have<=limit) {
			ll slack=limit-have;
			ll times=slack/sum;
			ll cur=min(d+times,(ll)nd-1);
			if(cur>ret) ret=cur;
		}
		if(nd==LLONG_MAX) break;
		d=nd;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}