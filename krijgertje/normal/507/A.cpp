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

typedef struct X { int need,idx; } X;
bool operator<(const X &p,const X &q) { return p.need<q.need; }

int n,have;
X x[100];

void run() {
	scanf("%d%d",&n,&have); REP(i,n) x[i].idx=i,scanf("%d",&x[i].need); sort(x,x+n);
	int ret=0;
	while(ret<n&&have>=x[ret].need) have-=x[ret++].need;
	printf("%d\n",ret);
	REP(i,ret) { if(i!=0) printf(" "); printf("%d",x[i].idx+1); } puts("");
}

int main() {
	run();
	return 0;
}