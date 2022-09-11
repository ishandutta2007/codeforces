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

const int MAXBROKEN=100000;

int nbroken,len,lim;
int x[MAXBROKEN];

int gap[MAXBROKEN-1],ngap;

int solve() {
	int ret=x[nbroken-1]-x[0]+1;
	ngap=0; REP(i,nbroken-1) gap[ngap++]=x[i+1]-x[i]-1;
	sort(gap,gap+ngap); reverse(gap,gap+ngap);
	int nuse=min(lim-1,ngap); REP(i,nuse) ret-=gap[i];
	return ret;
}

void run() {
	scanf("%d%d%d",&nbroken,&len,&lim);
	REP(i,nbroken) scanf("%d",&x[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}