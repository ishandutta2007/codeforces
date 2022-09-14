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

int nflower,ndays,len;
int x[100000];
int y[100000];

bool ok(int want) {
	int cur=0,ret=0;
	REP(i,nflower) {
		if(i>=len) cur-=y[i-len];
		y[i]=x[i]+cur>=want?0:want-(x[i]+cur);
		if(ret+y[i]>ndays) return false;
		ret+=y[i];
		cur+=y[i];
	}
	return true;
}

void run() {
	scanf("%d%d%d",&nflower,&ndays,&len); REP(i,nflower) scanf("%d",&x[i]);

	int l=INT_MAX; REP(i,nflower) if(x[i]<l) l=x[i];
	int h=l+ndays+1;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(ok(m)) l=m; else h=m;
	}
	printf("%d\n",l);
}

int main() {
	run();
	return 0;
}