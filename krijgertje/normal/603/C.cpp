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

int n,k;
int g(int x) {
	if(k%2==0) {
		if(x==0) return 0;
		if(x==1) return 1;
		if(x==2) return 2;
		if(x%2==1) return 0; else return 1;
	} else {
		if(x==0) return 0;
		if(x==1) return 1;
		if(x==2) return 0;
		if(x==3) return 1;
		int n2=0; while(x%2==0) x/=2,++n2;
		if(n2==0) return 0;
		if(x==3) return n2%2==0?1:2;
		return n2%2==0?2:1;
	}
}

void run() {
	scanf("%d%d",&n,&k);
	int ret=0;
	REP(i,n) { int x; scanf("%d",&x); ret^=g(x); }
	printf("%s\n",ret==0?"Nicky":"Kevin");
}

int main() {
	run();
	return 0;
}