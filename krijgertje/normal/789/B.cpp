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
#include <random>
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

const int MAXBAD=100000;

int b1,q,lim,nbad;

int bad[MAXBAD];

void run() {
	scanf("%d%d%d%d",&b1,&q,&lim,&nbad); REP(i,nbad) scanf("%d",&bad[i]); sort(bad,bad+nbad);
	set<int> been;
	int ret=0;
	ll at=b1; ll prv=lim+1;
	while(abs(at)<=lim) {
		int idx=lower_bound(bad,bad+nbad,(int)at)-bad;
		bool curok=idx==nbad||bad[idx]!=at;
		if(curok) ++ret;
		if(been.count(at)) { if(curok||at!=prv&&ret>0) printf("inf\n"); else printf("%d\n",ret); return; } else been.insert(at);
		prv=at; at*=q;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}