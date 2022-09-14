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

const int MAXN=200000;
const int MOD=1000000007;

int n;
int a[MAXN];
int fac[MAXN+1];
int ifac[MAXN+1];
int inv[MAXN+1];

int b[4][4];

int choose(int n,int k) {
	return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

int calc(int len) {
	int op=+1;
	REP(i,len) REP(j,len-i-1) {
		b[i+1][j]=b[i][j]+op*b[i][j+1]; if(b[i+1][j]<0) b[i+1][j]+=MOD; if(b[i+1][j]>=MOD) b[i+1][j]-=MOD;
		op=-op;
	}
	return b[len-1][0];
}

void run() {
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	int nstep=(n-1)/4;
	int len=n-4*nstep;

	int ret=0;
	REP(i,n) {
		int c=i-2*nstep;
		REP(j,len) {
			int d=abs(j-c);
			b[0][j]=d%2==1?0:choose(2*nstep,nstep+d/2);
		}
		//printf("%d:",i); REP(j,len) printf(" %d",b[0][j]); puts("");
		ret=(ret+(ll)a[i]*calc(len))%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}