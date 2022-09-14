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

int n;

void run() {
	scanf("%d",&n);
	if(n<=2) { printf("-1\n"); return; }
	int z=1;
	while(n%2==0) n/=2,z*=2;
	if(n!=1) {
		int p=(n+1)/2,q=p-1;
		//printf("\tn=%d, z=%d, p=%d, q=%d\n",n,z,p,q);
		ll a=(ll)p*p-(ll)q*q,b=(ll)2*p*q,c=(ll)p*p+(ll)q*q;
		a*=z,b*=z,c*=z;
		printf("%lld %lld\n",b,c);
	} else {
		ll a=(ll)z*3/4,b=(ll)z,c=(ll)z*5/4;
		printf("%lld %lld\n",a,c);
	}
}

int main() {
	run();
	return 0;
}