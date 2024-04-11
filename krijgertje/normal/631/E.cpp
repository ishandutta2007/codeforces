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

// ax+b
typedef struct CHull {
	int a[MAXN]; ll b[MAXN]; int n; // a is decreasing
	void init() { n=0; }
	void add(int aa,ll bb) {
		//printf("\tadding %d*x + %lld\n",aa,bb);
		while(n>=2&&(bb-b[n-1])*(a[n-2]-a[n-1])>=(b[n-1]-b[n-2])*(a[n-1]-aa)) --n;
		a[n]=aa,b[n]=bb,++n;
	}
	ll get(ll x) {
		int l=0,h=n; // [l,h)
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(x*(a[m-1]-a[m])>=(b[m]-b[m-1])) h=m; else l=m;
		}
		ll ret=a[l]*x+b[l];
		//printf("\t%lld: %d*x + %lld=%lld\n",x,a[l],b[l],ret);
		return ret;
	}
} CHull;


int n;
int x[MAXN];
ll xsum[MAXN+1];

CHull h;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);
	xsum[0]=0; REP(i,n) xsum[i+1]=xsum[i]+x[i];
	// i->j: i<=j: -i*x[i]+j*x[i]-(x[i+1]+...+x[j]) = -i*x[i]+xsum[i+1] +j*x[i]-xsum[j+1]
	// i->j: i>=j: -i*x[i]+j*x[i]+(x[j]+...+x[i-1]) = -i*x[i]+xsum[i]   -j*-x[i]-xsum[j]
	// j->i: j>=i: -j*x[j]+i*x[j]+(x[i]+...+x[j-1]) = -j*x[j]+xsum[j]   +i*x[j]-xsum[i]

	ll ret=0;
	h.init();
	for(int i=n-1;i>=0;--i) {
		h.add(i+1,-xsum[i+1]);
		ll cur=xsum[i+1]-(ll)(i+1)*x[i]+h.get(x[i]);
		if(cur>ret) ret=cur;
		//printf("%d: %lld\n",i,cur);
	}
	h.init();
	REP(i,n) {
		h.add(-(i+1),-xsum[i]);
		ll cur=xsum[i]-(ll)(i+1)*x[i]+h.get(-x[i]);
		if(cur>ret) ret=cur;
		//printf("%d: %lld\n",i,cur);
	}

	REP(i,n) ret+=(ll)(i+1)*x[i];
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}