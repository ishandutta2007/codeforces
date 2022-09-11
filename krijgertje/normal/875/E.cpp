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
const int MAXCOORD=1000000000;

int n,s1,s2;
int x[MAXN];

bool ok(ll range) {
	if(abs(s1-s2)>range) return false;
	if(n==0) return true;
	set<int> opt;
	if(abs(s1-x[0])<=range) opt.insert(s1);
	if(abs(s2-x[0])<=range) opt.insert(s2);
	FOR(i,1,n) if(SZ(opt)>0) {
		ll l=x[i]-range,r=x[i]+range;
		while(true) { auto it=opt.begin(); if(it==opt.end()) break; if(*it<l) opt.erase(it); else break; }
		while(true) { auto it=opt.end(); if(it==opt.begin()) break; --it; if(*it>r) opt.erase(it); else break; }
		if(abs(x[i]-x[i-1])<=range) opt.insert(x[i-1]);
	}
	return SZ(opt)>0;
}

void run() {
	scanf("%d%d%d",&n,&s1,&s2); REP(i,n) scanf("%d",&x[i]);
	int l=-1,r=MAXCOORD;
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(ok(m)) r=m; else l=m;
	}
	printf("%d\n",r);
}

int main() {
	run();
	return 0;
}