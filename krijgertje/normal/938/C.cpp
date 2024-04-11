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

bool solve(int x,int &n,int &sz) {
	if(x==0) { n=1; sz=1; return true; }
	for(int a=1;(ll)a*a<x;++a) if(x%a==0) {
		int b=x/a;
		// n-z=a, n+z=b -> a+b=2*n b-a=2*z -> floor(n/sz)=z -> 0<=q<sz (n-q)/z=sz
		if((a+b)%2==1) continue;
		n=(a+b)/2; int z=(b-a)/2; sz=n/z;
		if(n%z>=sz) continue;
		return true;
	}
	return false;
}

void run() {
	int x; scanf("%d",&x);
	int n,sz;
	if(!solve(x,n,sz)) { printf("-1\n"); return; } else printf("%d %d\n",n,sz);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}