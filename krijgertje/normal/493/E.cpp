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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

bool ispow(ll b,ll a) {
	ll c=a; assert(a>=2);
	while(c<=b/a) c*=a;
	return c==b;
}

vector<ll> getpol(ll b,ll a) {
	vector<ll> ret;
	while(b!=0) {
		ret.PB(b%a); b/=a;
	}
	//REPSZ(i,ret) printf("%lld ",ret[i]); puts("");
	return ret;
}

bool iseq(vector<ll> c,ll t,ll a) {
	ll b=1;
	REPSZ(i,c) {
		//printf("\t%lld * %lld vs %lld\n",b,c[i],a);
		if(c[i]!=0&&b>a/c[i]) return false;
		a-=b*c[i]; 
		if(i+1<SZ(c)) {
			//printf("\t\t%lld * %lld vs %lld\n",b,t,a);
			if(b>a/t) return false;
			b*=t;
		}
	}
	//printf("-> %lld\n",a);
	return a==0;
}


ll t,a,b;

void run() {
	cin>>t>>a>>b;
	if(t==1) {
		if(a==1) {
			if(b==1) printf("inf\n"); else printf("0\n");
		} else {
			int ret=0;
			{ // some ci=a, other ci=0 -> P(t)=a P(a)=ci*a^i=a^(i+1)=b
				if(ispow(b,a)) ++ret;
			}
			{ // all ci<a -> ci determined bi P(a)=c0+c1*a+c2*a*a+...=b
				vector<ll> c=getpol(b,a);
				if(iseq(c,t,a)) ++ret;
			}
			printf("%d\n",ret);
		}
	} else {
		if(a==1) {
			if(b==1) printf("1\n"); else printf("0\n");
		} else {
			int ret=0;
			{ // c0==a
				if(a==b) ++ret;
			}
			{ // all ci<a -> ci determined bi P(a)=c0+c1*a+c2*a*a+...=b
				vector<ll> c=getpol(b,a);
				if(iseq(c,t,a)) ++ret;
			}
			printf("%d\n",ret);
		}
	}

}

int main() {
	run();
	return 0;
}