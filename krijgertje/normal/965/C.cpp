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

ll ncandy,npers,xlim; int roundlim;

ll calcleq(ll num,ll den1,ll den2,ll cden) { // x<=num/(den1*den2+cden)
	return num<cden||(num-cden)/den2<den1?0:num/(den1*den2+cden);
}

ll calcgeq(ll num,ll den1,ll den2) { // x>=num/(den1*den2)
	return num/den2<den1?1:(num+den1*den2-1)/(den1*den2);
}

void run() {
	scanf("%lld%lld%lld%d",&ncandy,&npers,&xlim,&roundlim);

	ll ret=-1;
	ll x=xlim;
	while(x>0) {
		// nrounds*x*npers>=ncandy -> nrounds>=ncandy/(x*npers)
		ll nrounds=calcgeq(ncandy,x,npers);
		if(nrounds>roundlim) break;
		ll rem=ncandy-(nrounds-1)*x*npers;
		ll cur=(nrounds-1)*x+(rem>=x?x:0);
		//printf("x=%lld nrounds=%lld rem=%lld cur=%lld\n",x,nrounds,rem,cur);
		ret=max(ret,cur);
		ll nx;
		if(rem>=x) {
			//nx*npers*nrounds<ncandy -> nx<=(ncandy-1)/(npers*nrounds)
			nx=calcleq(ncandy-1,npers,nrounds,0);
		} else {
			// nrem=rem+dx*npers*nrounds,nx=x-dx,nrem<=nx -> dx<=(x-rem)/(npers*nrounds+1)
			ll dx=calcleq(x-rem,npers,nrounds,1);
			nx=x-max(1LL,dx);
		}
		x=nx;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}