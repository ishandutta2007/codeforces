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
int x[MAXN];
ll xsum[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	xsum[0]=0; REP(i,n) xsum[i+1]=xsum[i]+x[i];

	ll rnum=0,rden=1; int ri=0,rk=0;
	REP(i,n) {
		// max((x{i-k}+...+x{i-1}+x{i}+x{n-k}+...+x{n-1})/(2k+1)-x{i}) st k<=min(i,n-i-1)
		int l=0,h=min(i+1,n-i);
		while(l+1<h) {
			int m=l+(h-l)/2;
			if((ll)(x[i-m]+x[n-m])*(2*m+1)>=2*(x[i]+xsum[i]-xsum[i-m]+xsum[n]-xsum[n-m])) l=m; else h=m;
		}
		ll cnum=x[i]+xsum[i]-xsum[i-l]+xsum[n]-xsum[n-l]-(ll)(2*l+1)*x[i],cden=2*l+1;
		//printf("%d: %d..%d,%d,%d..%d = %lld/%lld = %lf\n",i,i-l,i-1,i,n-l,n-1,cnum,cden,1.0*cnum/cden);
		if(cnum*rden>rnum*cden) rnum=cnum,rden=cden,ri=i,rk=l;
	}
	printf("%d\n",2*rk+1);
	REP(i,rk) printf("%d ",x[ri-i-1]); printf("%d",x[ri]); REP(i,rk) printf(" %d",x[n-i-1]); puts("");
}

int main() {
	run();
	return 0;
}