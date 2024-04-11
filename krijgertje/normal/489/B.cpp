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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int na,a[100],nb,b[100];

void run() {
	scanf("%d",&na); REP(i,na) scanf("%d",&a[i]); sort(a,a+na);
	scanf("%d",&nb); REP(i,nb) scanf("%d",&b[i]); sort(b,b+nb);
	int ai=0,bi=0,ret=0;
	while(ai<na&&bi<nb) {
		if(abs(a[ai]-b[bi])<=1) { ++ret; ++ai,++bi; continue; }
		if(a[ai]<b[bi]) ++ai; else ++bi;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}