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

const int MAXN=1000000;

int n;
int w[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&w[i]);
	sort(w,w+n);
	int ret=0;
	int at=0,cw=0,ccnt=0;
	while(at<n||ccnt!=0) {
		if(ccnt==0) cw=w[at];
		int to=at; while(to<n&&w[to]==cw) ++to;
		ccnt+=to-at;
		if(ccnt%2!=0) ++ret;
		ccnt/=2; ++cw;
		at=to;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}