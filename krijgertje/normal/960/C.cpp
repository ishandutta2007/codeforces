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

const int MAXRET=10000;

int want,dst;

ll ret[MAXRET]; int nret;

void run() {
	scanf("%d%d",&want,&dst);

	int rem=want; nret=0; ll at=1;
	while(rem>0) {
		int cur=1; while(((2LL<<cur)-1)<=rem) ++cur;
		REP(i,cur) ret[nret++]=at; at+=dst; rem-=((1LL<<cur)-1);
	}
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%lld",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}