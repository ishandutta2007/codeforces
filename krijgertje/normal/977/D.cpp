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
struct Z { ll val; int n2,n3; };
bool operator<(const Z &a,const Z &b) {
	if(a.n3!=b.n3) return a.n3>b.n3;
	if(a.n2!=b.n2) return a.n2<b.n2;
	return false;
}

int n;
ll a[MAXN];

Z z[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]);

	ll rem=-1;
	REP(i,n) {
		z[i].val=a[i],z[i].n2=z[i].n3=0;
		ll x=a[i]; while(x%2==0) ++z[i].n2,x/=2; while(x%3==0) ++z[i].n3,x/=3; if(rem==-1) rem=x; else assert(x==rem);
	}
	sort(z,z+n);
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",z[i].val); } puts("");
}

int main() {
	run();
	return 0;
}