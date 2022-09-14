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

int a,b,h,w,n;
int x[MAXN];

int rec(int at,int c,int d,int skipc) {
	if(c==1&&d==1) return at;
	if(at>=n) return INT_MAX;
	int ret=INT_MAX;
	if(c>1&&x[at]!=skipc) ret=min(ret,rec(at+1,(c+x[at]-1)/x[at],d,-1));
	if(d>1) ret=min(ret,rec(at+1,c,(d+x[at]-1)/x[at],x[at]));
	return ret;
}

int solve(int x,int y) {
	int c=(x+h-1)/h,d=(y+w-1)/w;
	//printf("c=%d d=%d\n",c,d);
	return rec(0,c,d,-1);
}

void run() {
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n); REP(i,n) scanf("%d",&x[i]); sort(x,x+n); reverse(x,x+n);
	int p=solve(a,b);
	int q=solve(b,a);
	int ret=min(p,q);
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}