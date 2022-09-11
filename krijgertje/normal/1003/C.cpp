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

const int MAXN=5000;

int n,sz;
int a[MAXN];

double sum[MAXN+1];


bool can(double want) {
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+a[i]-want;

	double mn=1e200;
	FORE(i,sz,n) {
		mn=min(mn,sum[i-sz]);
		if(sum[i]>=mn) return true;
	}
	return false;
}


void run() {
	scanf("%d%d",&n,&sz); REP(i,n) scanf("%d",&a[i]);

	double l=0,h=5000;
	REP(rep,200) {
		double m=l+(h-l)/2;
		if(can(m)) l=m; else h=m;
	}
	double ret=l+(h-l)/2;
	printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}