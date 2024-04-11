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
#include <bitset>
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

const int MAXN=200000;

int na,nb; ll ta,tb; int lim;
ll a[MAXN];
ll b[MAXN];

ll solve() {
	ll ret=LLONG_MIN;
	int at=0;
	if(lim>=na) return -1;
	REPE(i,lim) {
		int j=lim-i;
		while(at<nb&&a[i]+ta>b[at]) ++at;
		if(at+j>=nb) return -1;
		ll cur=b[at+j]+tb;
		ret=max(ret,cur);
	}
	return ret;
}


void run() {
	scanf("%d%d%lld%lld%d",&na,&nb,&ta,&tb,&lim);
	REP(i,na) scanf("%lld",&a[i]);
	REP(i,nb) scanf("%lld",&b[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}