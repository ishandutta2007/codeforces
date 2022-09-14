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

typedef struct T { int i,x; } T;
bool operator<(const T &a,const T &b) { if(a.x!=b.x) return a.x<b.x; return a.i<b.i; }

int n;
T t[2000];

void run() {
	scanf("%d",&n); REP(i,n) { t[i].i=i+1; scanf("%d",&t[i].x); } sort(t,t+n);
	int a=-1,b=-1;
	FOR(i,1,n) if(t[i].x==t[i-1].x) { if(a==-1) a=i; else if(b==-1) b=i; }
	if(a==-1||b==-1) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",t[i].i); } puts("");
	swap(t[a-1],t[a]);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",t[i].i); } puts("");
	swap(t[b-1],t[b]);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",t[i].i); } puts("");
}

int main() {
	run();
	return 0;
}