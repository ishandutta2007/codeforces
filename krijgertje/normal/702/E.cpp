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
const int MAXLOGSTEP=33;

int n; ll steps;
int  f[MAXLOGSTEP+1][MAXN]; ll s[MAXLOGSTEP+1][MAXN]; int m[MAXLOGSTEP+1][MAXN];


void run() {
	scanf("%d%lld",&n,&steps);
	REP(i,n) scanf("%d",&f[0][i]);
	REP(i,n) scanf("%lld",&s[0][i]);
	REP(i,n) m[0][i]=s[0][i];
	REP(i,MAXLOGSTEP) REP(j,n) f[i+1][j]=f[i][f[i][j]],s[i+1][j]=s[i][j]+s[i][f[i][j]],m[i+1][j]=min(m[i][j],m[i][f[i][j]]);
	REP(i,n) {
		ll cs=0; int cm=INT_MAX; int at=i;
		for(int i=MAXLOGSTEP;i>=0;--i) if(steps&(1LL<<i)) {
			cs+=s[i][at]; cm=min(cm,m[i][at]); at=f[i][at];
		}
		printf("%lld %d\n",cs,cm);
	}
}

int main() {
	run();
	return 0;
}