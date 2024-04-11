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

int want;
// f(n)=min(n/5+n/25+n/125+...,n/2+n/4+n/8+...)=n/5+n/25+n/125=5*f(n/5)
int f(int n) {
	int ret=0;
	for(;n>=5;n/=5) ret+=n/5;
	return ret;
}

void run() {
	scanf("%d",&want);
	int a=1; while(f(a)<want) ++a; int b=a; while(f(b)<=want) ++b; printf("%d\n",b-a);
	FOR(i,a,b) { if(i!=a) printf(" "); printf("%d",i); } puts("");
}

int main() {
	run();
	return 0;
}