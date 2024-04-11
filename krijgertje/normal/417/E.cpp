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

void calc(int n,int* x) {
	if(n==1) { x[0]=1; return; }
	if(n==2) { x[0]=3; x[1]=4; return; }
	x[0]=n-2; FOR(i,1,n) x[i]=2; return;
}

int h,w;
int x[100],y[100];

void run() {
	scanf("%d%d",&h,&w);
	calc(h,x); calc(w,y);
	REP(i,h) { REP(j,w) { if(j!=0) printf(" "); printf("%d",x[i]*y[j]); } puts(""); }
}

int main() {
	run();
	return 0;
}