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

int n,oh;
double ret[MAXN-1];

void run() {
	scanf("%d%d",&n,&oh);
	double h=oh,b=1;
	REP(i,n-1) {
		double have=.5*h*b,want=have/(n-i);
		double x=sqrt(1.0-2*want/h/b); ret[n-i-2]=x*h;
		h*=x; b*=x;
	}
	REP(i,n-1) { if(i!=0) printf(" "); printf("%.9lf",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}