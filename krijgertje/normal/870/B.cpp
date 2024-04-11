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

int n,k;
int a[MAXN];

void run() {
	scanf("%d%d",&n,&k); REP(i,n) scanf("%d",&a[i]);
	int mx=a[0]; FOR(i,1,n) if(a[i]>mx) mx=a[i];
	int mn=a[0]; FOR(i,1,n) if(a[i]<mn) mn=a[i];
	if(k==1) { printf("%d\n",mn); return; }
	if(k==2) { printf("%d\n",max(a[0],a[n-1])); return; }
	if(k>=3) { printf("%d\n",mx); return; }
}

int main() {
	run();
	return 0;
}