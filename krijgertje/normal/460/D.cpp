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

ll l,r; int k;

ll cur[4]; int ncur;
ll ret[4]; int nret; ll retval;

void testcur() {
	//printf("testing"); REP(i,ncur) printf(" %I64d",cur[i]); puts("");
	if(ncur<1||ncur>k) return;
	REP(i,ncur) if(cur[i]<l||cur[i]>r) return;
	sort(cur,cur+ncur);
	FOR(i,1,ncur) if(cur[i-1]==cur[i]) return;
	ll curval=0; REP(i,ncur) curval^=cur[i];
	if(curval<retval) { retval=curval; nret=ncur; REP(i,ncur) ret[i]=cur[i]; }
}

void calc() {
	if(r-l+1<=4) {
		int len=(int)(r-l+1);
		FOR(i,1,1<<len) {
			ncur=0; REP(j,len) if(i&(1<<j)) cur[ncur++]=l+j;
			testcur();
		}
	} else if(k>=4) {
		ll nl=l; if(nl%2!=0) ++nl;
		ncur=0; REP(i,4) cur[ncur++]=nl+i;
		testcur();
	} else if(k==1) {
		ncur=0; cur[ncur++]=l;
		testcur();
	} else if(k==2) {
		ll nl=l; if(nl%2!=0) ++nl;
		ncur=0; REP(i,2) cur[ncur++]=nl+i;
		testcur();
	} else {
		ll nl=l; if(nl%2!=0) ++nl;
		ncur=0; REP(i,2) cur[ncur++]=nl+i;
		testcur();
		for(int i=1;(1LL<<i)<=r;++i) {
			ncur=0;
			cur[ncur++]=(1LL<<(i-1+1))-1;
			cur[ncur++]=(1LL<<i)+(1LL<<(i-1))-1;
			cur[ncur++]=(1LL<<i)+(1LL<<(i-1));
			testcur();
		}
	}
}


void run() {
	scanf("%I64d%I64d%d",&l,&r,&k);
	retval=LLONG_MAX;
	calc();
	printf("%I64d\n%d\n",retval,nret); REP(i,nret) { if(i!=0) printf(" "); printf("%I64d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}