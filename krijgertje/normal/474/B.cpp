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

int n,nq;
int cnt[100000];
int cum[100001];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&cnt[i]);
	cum[0]=0; REP(i,n) cum[i+1]=cum[i]+cnt[i];
	scanf("%d",&nq);
	REP(qi,nq) {
		int q; scanf("%d",&q);
		int l=0,h=n; // cum[x]>=q (l,h]
		while(l+1<h) { int m=l+(h-l)/2; if(cum[m]>=q) h=m; else l=m; }
		printf("%d\n",l+1);
	}
}

int main() {
	run();
	return 0;
}