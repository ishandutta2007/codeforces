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

const int MAXN=100000;

int n,power;
int use[MAXN],have[MAXN];

bool can(double t) {
	double left=t;
	REP(i,n) {
		double need=use[i]*t-have[i];
		if(need>0) left-=need/power;
	}
	return left>=0;
}

void run() {
	scanf("%d%d",&n,&power);
	REP(i,n) scanf("%d%d",&use[i],&have[i]);
	ll sumuse=0; REP(i,n) sumuse+=use[i];
	if(power>=sumuse) { printf("-1\n"); return; }
	double l=0,h=1; while(can(h)) l=h,h+=h;
	REP(i,100) {
		double m=l+(h-l)/2;
		if(can(m)) l=m; else h=m;
	}
	double ret=l+(h-l)/2;
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}