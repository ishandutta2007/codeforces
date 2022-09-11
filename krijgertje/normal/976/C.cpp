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

const int MAXN=300000;
struct Z { int l,r,id; };
bool operator<(const Z &a,const Z &b) {
	if(a.l!=b.l) return a.l<b.l;
	if(a.r!=b.r) return a.r>b.r;
	return a.id<b.id;
}

int n;
Z z[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&z[i].l,&z[i].r),z[i].id=i;

	sort(z,z+n);
	int idx=-1;
	REP(i,n) {
		if(idx!=-1&&z[i].r<=z[idx].r) { printf("%d %d\n",z[i].id+1,z[idx].id+1); return; }
		if(z[i].r>z[idx].r) idx=i;
	}
	printf("-1 -1\n");
}

int main() {
	run();
	return 0;
}