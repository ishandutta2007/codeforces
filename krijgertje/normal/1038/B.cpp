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
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=45000;

int n;

int a[MAXN],na;
int b[MAXN],nb;

bool solve() {
	if(n==1||n==2) return false;
	int x=n%2==0?n/2:(n+1)/2;
	na=nb=0; a[na++]=x; FORE(i,1,n) if(i!=x) b[nb++]=i;
	return true;
}

void run() {
	scanf("%d",&n);
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	printf("%d",na); REP(i,na) printf(" %d",a[i]); puts("");
	printf("%d",nb); REP(i,nb) printf(" %d",b[i]); puts("");
}

int main() {
	run();
	return 0;
}