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

void run() {
	ll ret=0; int mnodd=0,cntodd=0;
	int n; scanf("%d",&n); REP(i,n) { int x; scanf("%d",&x); if(x%2==0) ret+=x; else { ++cntodd; if(mnodd==0) mnodd=x; else if(x<mnodd) ret+=mnodd,mnodd=x; else ret+=x; } }
	if(cntodd%2==0) ret+=mnodd;
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}