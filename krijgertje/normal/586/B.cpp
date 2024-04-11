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

const int MAXN=50;

int n;
int a[2][MAXN-1];
int b[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,2) REP(j,n-1) scanf("%d",&a[i][j]);
	REP(j,n) scanf("%d",&b[j]);

	int ret=INT_MAX;
	REP(x,n) FOR(y,x+1,n) {
		int cur=b[x]+b[y];
		REP(j,x) cur+=a[0][j]; FOR(j,x,n-1) cur+=a[1][j];
		REP(j,y) cur+=a[0][j]; FOR(j,y,n-1) cur+=a[1][j];
		if(cur<ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}