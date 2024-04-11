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

int n;
int ret[5000];

void run() {
	scanf("%d",&n);
	if(n==1) { printf("1\n1\n"); return; }
	if(n==2) { printf("1\n1\n"); return; }
	if(n==3) { printf("2\n1 3\n"); return; }
	int odd=(n-1)/2,evn=odd+1;
	for(int i=n;i>=1;--i) if(i%2==0) ret[evn++]=i;
	for(int i=1;i<=n;++i) if(i%2==1) ret[odd--]=i;
	printf("%d\n",n); REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}