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

const int MAXN=100;
const int CIRCLE=1;
const int TRIANGLE=2;
const int SQUARE=3;

int n;
int a[MAXN];

int solve() {
	REP(i,n-1) if(a[i]==TRIANGLE&&a[i+1]==SQUARE||a[i]==SQUARE&&a[i+1]==TRIANGLE) return INT_MAX;
	int ret=0;
	FOR(i,1,n) {
		if(a[i]==CIRCLE) {
			if(a[i-1]==SQUARE) ret+=4;
			else if(a[i-1]==TRIANGLE) ret+=3;
			else assert(false);
		} else if(a[i]==SQUARE) {
			assert(a[i-1]==CIRCLE);
			ret+=4;
		} else if(a[i]==TRIANGLE) {
			assert(a[i-1]==CIRCLE);
			if(i==1) ret+=3;
			else if(a[i-2]==SQUARE) ret+=2;
			else if(a[i-2]==TRIANGLE) ret+=3;
			else assert(false);
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	int ans=solve();
	if(ans==INT_MAX) { printf("Infinite\n"); return; }
	printf("Finite\n%d\n",ans);
}

int main() {
	run();
	return 0;
}