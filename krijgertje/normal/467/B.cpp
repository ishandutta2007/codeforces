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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int ntype,nothers,maxdiff;
int x[1000];
int xme;

int calc(int a,int b) { int ret=0; REP(i,ntype) if(((a>>i)&1)!=((b>>i)&1)) ++ret; return ret; }

void run() {
	scanf("%d%d%d",&ntype,&nothers,&maxdiff);
	REP(i,nothers) scanf("%d",&x[i]);
	scanf("%d",&xme);
	int ret=0; REP(i,nothers) if(calc(xme,x[i])<=maxdiff) ++ret;
	//REP(i,nothers) printf("%x %x -> %d\n",xme,x[i],calc(xme,x[i]));
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}