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

int a,b;

void run() {
	scanf("%d%d",&a,&b);

	if(b>a) { printf("-1\n"); return; }
	
	int k=(a-b)/(2*b);
	double x=1.0*(a+b)/(2*k+2);
	printf("%.9lf\n",x);
	// (2kx+x,x)..(2kx+2x,0) -> f(z)=2kx+2x-z -> f(a)=2kx+2x-a=b -> x=(a+b)/(2k+2)
}

int main() {
	run();
	return 0;
}