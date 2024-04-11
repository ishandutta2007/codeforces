#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int h,w,need;

void run() {
	scanf("%d%d%d",&h,&w,&need);
	int x=1,y=1;
	REP(i,need) {
		int len=h*w/need+(i<h*w%need?1:0);
		printf("%d",len);
		REP(j,len) {
			printf(" %d %d",x,y);
			if(x%2==1) {
				if(y==w) ++x; else ++y;
			} else {
				if(y==1) ++x; else --y;
			}
		}
		puts("");
	}
}

int main() {
	run();
	return 0;
}