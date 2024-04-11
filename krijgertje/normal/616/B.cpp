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

const int MAXH=100;
const int MAXW=100;

int h,w;
int c[MAXH][MAXW+1];


void run() {
	scanf("%d%d",&h,&w); REP(x,h) REP(y,w) scanf("%d",&c[x][y]);
	int ret=INT_MIN;
	REP(x,h) {
		int cur=INT_MAX;
		REP(y,w) {
			if(c[x][y]<cur) cur=c[x][y];
		}
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}