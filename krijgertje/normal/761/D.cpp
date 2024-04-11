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

int n,l,r;
int a[MAXN];
int p[MAXN];
int q[MAXN];
int b[MAXN];

void run() {
	scanf("%d%d%d",&n,&l,&r); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&p[i]),--p[i]; REP(i,n) q[p[i]]=i;
	b[q[0]]=l; ll lst=l-a[q[0]];
	FOR(i,1,n) {
		ll cur=lst+a[q[i]]+1;
		if(cur<l) cur=l; if(cur>r) { printf("-1\n"); return; }
		b[q[i]]=cur; lst=cur-a[q[i]];
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
}

int main() {
	run();
	return 0;
}