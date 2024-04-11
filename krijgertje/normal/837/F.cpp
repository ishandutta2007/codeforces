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

int na; ll want;
int a[MAXN];

int b[MAXN],nb;

bool ok(ll x) {
	//printf("testing %lld\n",x);
	if(x==0) { int mx=a[0]; FOR(i,1,na) if(a[i]>mx) mx=a[i]; return mx>=want; }
	ll rem=want;
	int pd=0; ll cur=1;
	REP(i,nb) {
		int d=na-b[i]-1,times=a[b[i]]; // times*C(x-1+d,d)
		while(pd<d) {
			++pd;
			ll num=x+pd-1,den=pd,g=gcd(num,den);
			//printf("C(%lld,%d)=%lld * %lld/%lld -> C(%lld,%d)\n",x-1+pd-1,pd-1,cur,num,den,x-1+pd,pd);
			num/=g,den/=g;
			assert(cur%den==0); cur/=den;
			if(cur>=(rem+num-1)/num) {
				//printf("C(%lld,%d) = %lld*%lld is at least %lld\n",x-1+pd,pd,cur,num,rem);
				return true;
			} else cur*=num;
		}
		if(cur>=(rem+times-1)/times) {
			//printf("%d*C(%lld,%d) is at least %lld\n",times,x-1+pd,pd,rem);
			return true;
		}
		//printf("%d*(%lld,%d) = %d*%lld\n",times,x-1+pd,pd,cur);
		rem-=cur*times;
	}
	//printf("->%lld\n",rem);
	return rem<=0;
}


void run() {
	scanf("%d%lld",&na,&want); REP(i,na) scanf("%d",&a[i]);
	nb=0; for(int i=na-1;i>=0;--i) if(a[i]!=0) b[nb++]=i;

	ll l=-1,h=want;
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	printf("%lld\n",h);
}

int main() {
	run();
	return 0;
}