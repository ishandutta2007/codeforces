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

const int MAXN=10000;
typedef struct P { int x,y; } P;

int n,dy,vbus,vme;
P p[MAXN];

void run() {
	scanf("%d%d%d%d",&n,&dy,&vbus,&vme);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);

	ll mn,mx;
	REP(i,n) {
		ll cur=(ll)p[i].x*vme-(ll)p[i].y*vbus;
		//printf("%d: %lf\n",i,1.0*cur/(vme*vbus));
		if(i==0||cur<mn) mn=cur;
		if(i==0||cur>mx) mx=cur;
	}
	printf("%.9lf\n",(mn>=0||mx<=0?0.0:1.0*mx/(vme*vbus))+1.0*dy/vme);
}

int main() {
	run();
	return 0;
}