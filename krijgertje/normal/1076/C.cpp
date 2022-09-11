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
#include <bitset>
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

// a+b=d, a*b=d
// b=d-a -> a*a-a*d+d=0 -> A=1,B=-d,C=d -> D=d*d-4*d=d*(d-4) -> a=(+-sqrt(d*(d-4))+d)/2

int d;
double a,b;

bool solve() {
	ll A=1,B=-d,C=d,D=(ll)B*B-(ll)4*A*C; if(D<0) return false;
	a=(sqrt(1.0*D)-B)/(2*A),b=d-a; return true;
}

void run() {
	scanf("%d",&d);
	if(!solve()) { printf("N\n"); return; }
	printf("Y %.15lf %.15lf\n",a,b);

}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}