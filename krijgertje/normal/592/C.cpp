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


void run() {
	ll t,w,b; scanf("%I64d%I64d%I64d",&t,&w,&b);
	ll g=gcd(w,b),ycnt=min(w,b);
	ll num=0,den=t;
	if(w/g>t/b) {
		num+=min(t+1,ycnt);
	} else {
		ll lcm=w/g*b; 
		ll times=t/lcm;
		num+=ycnt*times;
		num+=min(t-lcm*times+1,ycnt);
	}
	--num; ll gg=gcd(num,den);
	printf("%I64d/%I64d\n",num/gg,den/gg);
}

int main() {
	run();
	return 0;
}