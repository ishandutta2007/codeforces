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

ll C(int n,int k) {
	ll ret=1;
	int n2=0,n3=0,n5=0;
	n2+=k/2+k/4,n3+=k/3,n5=k/5;
	REP(i,k) {
		ret=ret*(n-i);
		while(n2>0&&ret%2==0) ret/=2,--n2;
		while(n3>0&&ret%3==0) ret/=3,--n3;
		while(n5>0&&ret%5==0) ret/=5,--n5;
	}
	//printf("\tC(%d,%d)=%lld/(2^%d,3^%d,5^%d)\n",n,k,ret,n2,n3,n5);
	return ret;
}

ll mypow(ll x,int n) {
	if(n<0) return 0;
	ll ret=1;
	while(true)  {
		if(n&1) ret=ret*x;
		if((n>>=1)==0) break;
		x=x*x;
	}
	return ret;
}


int n;
void run() {
	scanf("%d",&n);
	printf("%I64d\n",(n-3)*4*3*3*mypow(4,n-4)+2*4*3*mypow(4,n-3));
	
}

int main() {
	run();
	return 0;
}