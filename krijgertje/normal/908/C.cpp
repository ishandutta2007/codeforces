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

const int MAXN=1000;

int n,r;
int x[MAXN];
double y[MAXN];

void run() {
	scanf("%d%d",&n,&r); REP(i,n) scanf("%d",&x[i]);
	REP(i,n) {
		y[i]=r;
		REP(j,i) {
			int dx=abs(x[i]-x[j]); if(dx>2*r) continue;
			double dy=sqrt(4.0*r*r-1.0*dx*dx); y[i]=max(y[i],y[j]+dy);
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%.9lf",y[i]); } puts("");

}

int main() {
	run();
	return 0;
}