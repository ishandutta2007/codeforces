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

const int MAXN=22;

int a[MAXN],na;
int b[MAXN],nb;
int c[MAXN];

void run() {
	scanf("%d",&na); REP(i,na) scanf("%d",&a[i]);
	nb=0; REP(i,na) b[nb++]=a[i]; sort(b,b+nb); nb=unique(b,b+nb)-b; REP(i,na) a[i]=lower_bound(b,b+nb,a[i])-b;
	if(nb!=na) { printf("-1\n"); return; }
	REP(i,na) c[i]=b[(a[i]+1)%na];
	REP(i,na) { if(i!=0) printf(" "); printf("%d",c[i]); } puts("");
}

int main() {
	run();
	return 0;
}