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

const int MAXN=100000;

int na,nb;
int a[MAXN],b[MAXN];

ll asum[MAXN+1],bsum[MAXN+1];

void run() {
	scanf("%d%d",&na,&nb); REP(i,na) scanf("%d",&a[i]); REP(i,nb) scanf("%d",&b[i]);

	asum[0]=0; REP(i,na) asum[i+1]=asum[i]+a[i];
	bsum[0]=0; REP(i,nb) bsum[i+1]=bsum[i]+b[i];

	int ai=0,bi=0,nsame=0;
	while(ai<=na&&bi<=nb) {
		ll cur=min(asum[ai],bsum[bi]);
		if(asum[ai]==cur&&bsum[bi]==cur) ++nsame;
		if(asum[ai]==cur) ++ai;
		if(bsum[bi]==cur) ++bi;
	}
	printf("%d\n",nsame-1);
}

int main() {
	run();
	return 0;
}