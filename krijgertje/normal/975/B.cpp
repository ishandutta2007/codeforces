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

const int N=14;

int x[N];

void run() {
	REP(i,N) scanf("%d",&x[i]);
	ll ret=0;
	REP(i,N) if(x[i]>0) {
		ll cur=0;
		REP(j,N) {
			int idx=(i+1+j)%N;
			int cnt=x[i]/N+(j<x[i]%N?1:0);
			ll nx=(ll)(idx==i?0:x[idx])+cnt;
			//printf("pick up %d: %d to %d gives %lld\n",i,cnt,idx,nx);
			if(nx%2==0) cur+=nx;
		}
		ret=max(ret,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}