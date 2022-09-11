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

const int MAXN=1000;

int n,r;
int a[MAXN];

bool ok[MAXN];

int solve() {
	int ret=0;
	REP(i,n) ok[i]=false;
	REP(i,n) if(!ok[i]) {
		for(int j=n-1;j>=0;--j) if(a[j]==1) {
			if(j<=i-r||j>=i+r) continue;
			++ret;
			//printf("%d->%d\n",j,i);
			FORE(k,j-r+1,j+r-1) if(0<=k&&k<n) ok[k]=true;
			break;
		}
		if(!ok[i]) return -1;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&r);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}