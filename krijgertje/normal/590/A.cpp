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

const int MAXN=500000;

int n;
int a[MAXN];
int b[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	int ret=0;
	for(int at=0,to=at+1;at<n;at=to++) {
		while(to<n&&a[to]!=a[to-1]) ++to;
		int len=to-at;
		int cur=(len-1)/2;
		//printf("%d..%d = %d\n",at,to-1,cur);
		if(cur>ret) ret=cur;
		REP(i,cur+1) b[at+i]=a[at],b[to-i-1]=a[to-1];
	}
	printf("%d\n",ret);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
}

int main() {
	run();
	return 0;
}