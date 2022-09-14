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

int a,b,c,d;

void run() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int g=gcd(a,c),p=a/g*c;
	int i=0,j=0;
	while(true) {
		int x=b+i*a,y=d+j*c;
		if(x==y) { printf("%d\n",x); return; }
		if(max(x,y)>=max(b,d)+p) break;
		if(x<y) ++i; else ++j;
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}