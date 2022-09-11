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
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }

int n,nalph;
int a[MAXN],b[MAXN];

void run() {
	scanf("%d%d",&n,&nalph); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);
	int ret=0,peq=1,pone=inv(nalph);
	REP(i,n) {
		if(a[i]!=0&&b[i]!=0) {
			if(a[i]>b[i]) ret=(ret+peq)%MOD;
			if(a[i]!=b[i]) break;
		} else if(a[i]!=0) {
			peq=(ll)peq*pone%MOD;
			ret=(ret+(ll)(a[i]-1)*peq)%MOD;
		} else if(b[i]!=0) {
			peq=(ll)peq*pone%MOD;
			ret=(ret+(ll)(nalph-b[i])*peq)%MOD;
		} else {
			ret=(ret+(ll)peq*((MOD+1)/2)%MOD*(MOD+1-pone))%MOD;
			peq=(ll)peq*pone%MOD;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}