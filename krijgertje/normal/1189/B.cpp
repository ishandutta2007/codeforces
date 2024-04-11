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
#include <bitset>
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

const int MAXN=100000;

int n;
int a[MAXN];

bool solve() {
	sort(a,a+n);
	swap(a[n-2],a[n-1]);
	return a[n-2]<a[n-3]+a[n-1];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
}

int main() {
	run();
	return 0;
}