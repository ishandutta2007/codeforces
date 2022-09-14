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

const int MAXN=200000;
const int MINVAL=-10000;
const int MAXVAL=+10000;

int n;
int a[MAXN];

double calc(double x) {
	double mn=0,mx=0,ret=0;
	REP(i,n) {
		double cur=a[i]-x;
		if((mn+=cur)>0) mn=0; else if(-mn>ret) ret=-mn;
		if((mx+=cur)<0) mx=0; else if(+mx>ret) ret=+mx;
	}
	//printf("%lf -> %lf\n",x,ret);
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	
	double l=MINVAL,h=MAXVAL;
	REP(i,100) {
		double m1=l+1*(h-l)/3;
		double m2=l+2*(h-l)/3;
		if(calc(m1)<calc(m2)) h=m2; else l=m1;
	}
	printf("%.9lf\n",calc(l+(h-l)/2));
}

int main() {
	run();
	return 0;
}