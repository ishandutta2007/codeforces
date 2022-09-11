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

const int MAXN=1000000;

int n;
int a[MAXN];

int b[MAXN],nb;
int c[MAXN],nc;

int ret[4];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	sort(a,a+n);
	nb=nc=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int cnt=r-l;
		if(cnt>=2) b[nb++]=a[l];
		if(cnt>=4) c[nc++]=a[l];
	}

	if(nc>=1) {
		REP(i,4) ret[i]=c[0];
	} else { 
		assert(nb>=2);
		ll bnum=4*(b[0]+b[1])*(b[0]+b[1]),bden=(ll)b[0]*b[1]; int bi=0;
		//printf("%lld/%lld\n",bnum,bden);
		FOR(i,1,nb-1) {
			ll cnum=4*(b[i]+b[i+1])*(b[i]+b[i+1]),cden=(ll)b[i]*b[i+1];
			//printf("%lld/%lld\n",cnum,cden);
			if(cnum*bden<bnum*cden) bnum=cnum,bden=cden,bi=i;
		}
		ret[0]=ret[1]=b[bi],ret[2]=ret[3]=b[bi+1];
	}
	REP(i,4) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}