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

const int MAXN=16;

int p[MAXN]; int n;
ll idx;


int p1[MAXN/2],p2[MAXN/2],n1,n2;

ll lim=1000000000*1000000000LL;
vector<ll> v1;
vector<ll> v2;

void go(int at,ll val) {
	if(at>=n) { if(p[0]==p1[0]&&n==n1) v1.PB(val); else v2.PB(val); return; }
	while(true) {
		go(at+1,val);
		if(val>lim/p[at]) break;
		val*=p[at];
	}
}

ll calc(ll val) {
	ll ret=0;
	int j=SZ(v2)-1;
	REPSZ(i,v1) {
		while(j>=0&&v2[j]>val/v1[i]) --j;
		ret+=j+1;
	}
	//printf("calc(%lld)=%lld\n",val,ret);
	return ret;
}



void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]);
	scanf("%lld",&idx);
	
	sort(p,p+n);
	n1=n2=0; REP(i,n) if(i%4==0||i%4==3) p1[n1++]=p[i]; else p2[n2++]=p[i];

	n=n1; REP(i,n1) p[i]=p1[i]; go(0,1); sort(v1.begin(),v1.end());
	n=n2; REP(i,n2) p[i]=p2[i]; go(0,1); sort(v2.begin(),v2.end());
	//printf("v1:"); REPSZ(i,v1) printf(" %lld",v1[i]); puts("");
	//printf("v2:"); REPSZ(i,v2) printf(" %lld",v2[i]); puts("");


	ll l=0,h=lim;
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(calc(m)<idx) l=m; else h=m;
	}
	printf("%lld\n",h);
}

int main() {
	run();
	return 0;
}