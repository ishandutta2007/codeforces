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

int x,y,p,q;

void run() {
	scanf("%d%d%d%d",&x,&y,&p,&q);
	int g=gcd(p,q); p/=g,q/=g;
	if(p==0) { printf("%d\n",x==0?0:-1); return; }
	if(p==q) { printf("%d\n",x==y?0:-1); return; }
	// ?*q>=y
	// ?*p>=x
	// ?*(q-p)>=(y-x)
	int a=(y+q-1)/q;
	int b=(p+x-1)/p;
	int c=(y-x+q-p-1)/(q-p);
	int t=max(a,max(b,c));
	printf("%lld\n",(ll)t*q-y);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}