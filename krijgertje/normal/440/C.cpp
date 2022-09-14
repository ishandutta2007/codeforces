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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

ll n;
ll x[20];

int go(ll have,int a) {
	if(have==0) return 0;
	assert(a>=0);
	if(have<x[a]) return go(have,a-1);
//	printf("have=%lld, x[a]=%lld\n",have,x[a]);
	int cnt1=have/x[a];
	int ret1=cnt1*(a+1)+go(have-cnt1*x[a],a-1);
	int cnt2=(x[a+1]-have)/x[a];
	int ret2=(a+2)+cnt2*(a+1)+go(x[a+1]-have-cnt2*x[a],a-1);
	return min(ret1,ret2);
}

void run() {
	cin>>n;
	x[0]=1; FOR(i,1,20) x[i]=10*x[i-1]+1;
	
	int ret=go(n,17);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}