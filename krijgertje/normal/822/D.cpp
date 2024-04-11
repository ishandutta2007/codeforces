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

const int MAXVAL=5000000;
const int MOD=1000000007;

int dv[MAXVAL+1];
int f[MAXVAL+1];

int calc(int n) { return (ll)n*(n-1)/2%MOD; }

void run() {
	memset(dv,-1,sizeof(dv));
	FORE(i,2,MAXVAL) if(dv[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(dv[j]==-1) dv[j]=i;
	f[1]=0; FORE(i,2,MAXVAL) f[i]=(f[i/dv[i]]+(ll)(i/dv[i])*calc(dv[i]))%MOD;
	int p,l,r; scanf("%d%d%d",&p,&l,&r);
	int ret=0,mlt=1;
	FORE(i,l,r) {
		ret=(ret+(ll)mlt*f[i])%MOD;
		mlt=(ll)mlt*p%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}