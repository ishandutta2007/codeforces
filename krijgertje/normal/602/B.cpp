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

const int MAXN=100000;

int n;
int x[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	int ret=1;
	// start,val1,val2
	int s=0,ss=0,a=x[0],b=x[1];
	FOR(i,1,n) {
		if(abs(x[i]-a)>1||abs(x[i]-b)>1) s=ss,a=b=x[ss];
		if(abs(x[i]-x[i-1])>1) s=ss=i,a=b=x[i]; else if(abs(x[i]-x[i-1])>0) a=x[ss],b=x[i],ss=i;
		int cur=i-s+1;
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}