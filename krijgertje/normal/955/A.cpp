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

int hh,mm,st;
int slevel,dlevel,bcost,bgain;

double solve(int t) {
	int dt=t-st;
	int clevel=slevel+dlevel*dt;
	int cneed=(clevel+bgain-1)/bgain;
	double ccost=(t>=20*60?0.8:1.0)*bcost;
	return ccost*cneed;
}

void run() {
	scanf("%d%d%d%d%d%d",&hh,&mm,&slevel,&dlevel,&bcost,&bgain); st=hh*60+mm;
	double ret=solve(st);
	if(st<20*60) ret=min(ret,solve(20*60));
	printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}