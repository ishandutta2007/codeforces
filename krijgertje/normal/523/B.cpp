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

int n,T; double c;
int a[200000];
int nq;

void run() {
	scanf("%d%d%lf",&n,&T,&c);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	int at=T; double real=0,approx=0; REP(i,T) real+=1.0*a[i]/T,approx=(approx+1.0*a[i]/T)/c;
	REP(qi,nq) {
		int t; scanf("%d",&t);
		while(at<t) {
			real+=1.0*(a[at]-a[at-T])/T;
			approx=(approx+1.0*a[at]/T)/c;
			++at;
		}
		double error=abs(approx-real)/real;
		printf("%.9lf %.9lf %.9lf\n",real,approx,error);
	}
}

int main() {
	run();
	return 0;
}