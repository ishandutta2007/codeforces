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

void run() {
	scanf("%d",&n);
	REP(i,2*n) {
		if(i!=0) printf(" ");
		int x=i;
		if(x<n/2) { printf("%d",1+2*x+n%2); continue; } else x-=n/2*2;
		if(x<0) { printf("%d",-1-2*x+n%2); continue; }
		if(x<(n-1)/2) { printf("%d",2*x+2-n%2); continue; } else x-=(n-1)/2*2;
		if(x==-(n-1)/2) { printf("%d",n); continue; } else --x;
		if(x<0) { printf("%d",-2*x-n%2); continue; }
		printf("%d",n);
	}
	puts("");
}

int main() {
	run();
	return 0;
}