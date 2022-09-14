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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;
int a[200000];
int b[200000];
int c[200000];

// Ord(p) = p0*(n-1)!+(p1-I(p0<p1))*(n-2)!+...
int ord[200000]; // =sum(ord[i]*(n-i-1)!)

int fval[(1<<18)+1];
void finc(int x) { // increase val at x
	while(x<=(1<<18)) {
		fval[x]++;
		x+=x&-x;
	}
}
int fsum(int x) { // sum of all vals <= x
	int ret=0;
	while(x!=0) {
		ret+=fval[x];
		x-=x&-x;
	}
	return ret;
}
int ffind(int n) { // find nth zero (0-based)
	int idx=1<<18;
	while(true) {
		for(int step=(idx&-idx)>>1;;step>>=1) {
			if(step==0) { assert(n==0); return idx; }
			if(n<step-fval[idx-step]) { idx=idx-step; break; } else { n-=step-fval[idx-step]; }
		}
	}
}



void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);

	REP(i,n) ord[i]=0;
	memset(fval,0,sizeof(fval));
	REP(i,n) { ord[i]+=a[i]-fsum(a[i]+1); finc(a[i]+1); }
	memset(fval,0,sizeof(fval));
	REP(i,n) { ord[i]+=b[i]-fsum(b[i]+1); finc(b[i]+1); }
	for(int i=n-1;i>=0;--i) if(ord[i]>=n-i) { int c=ord[i]/(n-i); ord[i]-=c*(n-i); if(i-1>=0) ord[i-1]+=c; }

	memset(fval,0,sizeof(fval));
	REP(i,n) { c[i]=ffind(ord[i])-1; finc(c[i]+1); }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",c[i]); } puts("");
}

int main() {
	run();
	return 0;
}