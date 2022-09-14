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

ll ts,tf,dt;
int n;
ll t[MAXN];

void run() {
	scanf("%lld%lld%lld",&ts,&tf,&dt); assert(tf-ts>=dt);
	scanf("%d",&n); REP(i,n) scanf("%lld",&t[i]);
	ll mn=LLONG_MAX,ret=-1;
	ll now=ts;
	REPE(i,n) {
		if(now>tf-dt) break;
		if(i==n||t[i]>now) {
			ll cur=0; if(cur<mn) mn=cur,ret=now;
			if(i==n) break; else now=t[i];
		}
		if(i==0||i!=t[i-1]) {
			ll cur=now-(t[i]-1); if(cur<mn) mn=cur,ret=t[i]-1;
		}
		now+=dt;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}