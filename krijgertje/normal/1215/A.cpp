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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n1,k1,n2,k2,nyellow;

int solvelo() {
	int nfree=min(nyellow,n1*(k1-1)+n2*(k2-1));
	int remyellow=nyellow-nfree;
	return remyellow;
}
int solvehi() {
	if(k1>k2) swap(n1,n2),swap(k1,k2);
	int remyellow=nyellow;
	int r1=min(n1,remyellow/k1);
	remyellow-=r1*k1;
	int r2=min(n2,remyellow/k2);
	remyellow-=r2*k2;
	return r1+r2;
}

void run() {
	scanf("%d%d%d%d%d",&n1,&n2,&k1,&k2,&nyellow);
	int lo=solvelo();
	int hi=solvehi();
	printf("%d %d\n",lo,hi);
}

int main() {
	run();
	return 0;
}