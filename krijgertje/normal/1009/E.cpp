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

const int MAXN=1000000;
const int MOD=998244353;

int n;
int a[MAXN+1];

int f[MAXN+1];

void run() {
	scanf("%d",&n); FORE(i,1,n) scanf("%d",&a[i]);

	int fsum=0,asum=0;
	FORE(i,1,n) {
		asum=((ll)2*asum+a[i])%MOD;
		f[i]=(fsum+asum)%MOD;
		fsum=(fsum+f[i])%MOD;
	}
	printf("%d\n",f[n]);
}

int main() {
	run();
	return 0;
}