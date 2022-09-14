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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

const int MOD=1000000007;

int fac[200001];
int facinv[200001];

int mypow(int n,int k) {
	int ret=1,cur=n;
	for(int i=0;(1<<i)<=k;++i) {
		if((k&(1<<i))!=0) ret=(ll)ret*cur%MOD;
		cur=(ll)cur*cur%MOD;
	}
//	printf("%d ^ %d = %d\n",n,k,ret);
	return ret;
}

int choose(int n,int k) {
//	printf("%d choose %d = %d [%d*%d*%d]\n",n,k,(int)((ll)fac[n]*facinv[k]%MOD*facinv[n-k]%MOD),fac[n],facinv[k],facinv[n-k]);
	return (ll)fac[n]*facinv[k]%MOD*facinv[n-k]%MOD;
}

int go(int n0,int n1,int res) {
	int ret=0;
	if(res==0) {
		// 0 / 1x / 01
		if(n0==1&&n1==0) ++ret;
		if(n1>=1&&n0+n1>=2) ret+=choose(n0+n1-1,n0);
		if(n0>=1&&n0+n1>=2) ret+=go(n0-1,n1,1);
	} else {
		// 1 / 00
		if(n1==1&&n0==0) ++ret;
		if(n0>=1&&n0+n1>=2) ret+=go(n0-1,n1,0);
	}
	if(ret>=MOD) ret-=MOD; if(ret>=MOD) ret-=MOD;
	return ret;
}

int n0,n1,res;

void run(int casenr) {
	scanf("%d%d%d",&n0,&n1,&res);

	fac[0]=1; FORE(i,1,n0+n1) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,n0+n1) facinv[i]=mypow(fac[i],MOD-2);

//	int ret=go(n0,n1,res);
	int ret=0;
	while(n0+n1>=2) {
		if(res==0) {
			if(n1>=1) { ret+=choose(n0+n1-1,n0); if(ret>=MOD) ret-=MOD; }
			if(n0==0) break; else --n0,res=1-res;
		} else {
			if(n0==0) break; else --n0,res=1-res;
		}
	}
	if(n0+n1==1&&res==n1) { ++ret; if(ret>=MOD) ret-=MOD; }

	printf("%d\n",ret);

}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}