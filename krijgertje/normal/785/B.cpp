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

const int MAXN=200000;

typedef struct X { int l,r; } X;

int na,nb;
X a[MAXN],b[MAXN];

void run() {
	scanf("%d",&na); REP(i,na) scanf("%d%d",&a[i].l,&a[i].r);
	scanf("%d",&nb); REP(i,nb) scanf("%d%d",&b[i].l,&b[i].r);
	int ret=0;
	int al=0; FOR(i,1,na) if(a[i].l>a[al].l) al=i;
	int ar=0; FOR(i,1,na) if(a[i].r<a[ar].r) ar=i;
	int bl=0; FOR(i,1,nb) if(b[i].l>b[bl].l) bl=i;
	int br=0; FOR(i,1,nb) if(b[i].r<b[br].r) br=i;
	if(a[ar].r<=b[bl].l) ret=max(ret,b[bl].l-a[ar].r);
	if(b[br].r<=a[al].l) ret=max(ret,a[al].l-b[br].r);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}