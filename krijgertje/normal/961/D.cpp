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
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

int n;
P p[MAXN];

bool done[MAXN];

bool online(const P &a,const P &b,const P &c) {
	return ((b-a)^(c-a))==0;
}

bool solve(const P &a,const P &b) {
	REP(i,n) done[i]=online(a,b,p[i]);
	int ci=-1,di=-1;
	REP(i,n) if(!done[i]) if(ci==-1) ci=i; else if(di==-1) di=i;
	P c=p[ci],d=p[di];
	REP(i,n) if(!done[i]&&!online(c,d,p[i])) return false;
	return true;
}

bool solve() {
	if(n<3) return true;
	REP(i,3) FOR(j,i+1,3) { // i and j on same line
		if(solve(p[i],p[j])) return true;
	}
	return false;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}