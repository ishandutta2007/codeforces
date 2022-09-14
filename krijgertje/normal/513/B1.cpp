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

int n; ll k;

int ret[50];

void run() {
	cin>>n>>k; --k;
	int a=0,b=n-1;
	REP(i,n-1) {
		ll cur=1LL<<(n-i-2);
		if(k<cur) ret[a++]=i+1; else k-=cur,ret[b--]=i+1;
	}
	assert(a==b); ret[a]=n;
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}