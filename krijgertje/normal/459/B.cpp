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

int n;
int x[200000];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	int l=INT_MAX,lcnt=0,h=INT_MIN,hcnt=0;
	REP(i,n) {
		if(x[i]<l) l=x[i],lcnt=0; if(x[i]==l) ++lcnt;
		if(x[i]>h) h=x[i],hcnt=0; if(x[i]==h) ++hcnt;
	}
	ll ways=l==h?(ll)n*(n-1)/2:(ll)lcnt*hcnt;
	printf("%d %I64d\n",h-l,ways);
}

int main() {
	run();
	return 0;
}