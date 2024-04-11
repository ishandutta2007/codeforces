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

const int MAXN=1000000;
const int MOD=1000000007;

int n;
int a[MAXN+1];

int fac[MAXN+1];

int prod[MAXN+1];
int mxp[MAXN+1];

int eqfree[MAXN+1]; // #free elements in equivalence class
int prodfree[MAXN+1]; // #free places with given product of prime factors

int pmap[MAXN+1];
int pinv[MAXN+1];

void run() {
	scanf("%d",&n);
	FORE(i,1,n) scanf("%d",&a[i]);

	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,n) prod[i]=1,mxp[i]=-1,eqfree[i]=prodfree[i]=0,pmap[i]=pinv[i]=0;

	++eqfree[0],mxp[1]=1;
	FORE(i,2,n) if(mxp[i]==-1) {
		for(int j=i;j<=n;j+=i) prod[j]*=i,mxp[j]=i;
		++eqfree[n/i-1];
	}

	FORE(idx,1,n) {
		int val=a[idx];
		if(val==0) {
			prodfree[prod[idx]]++;
		} else {
			int idxp=mxp[idx],idxeq=idx==1?0:n/idxp-1,idxmult=prod[idx]/idxp;
			int valp=mxp[val],valeq=val==1?0:n/valp-1,valmult=prod[val]/valp;
			//printf("idx=%d (%d,%d,%d), val=%d (%d,%d,%d) [%d,%d]\n",idx,idxp,idxeq,idxmult,val,valp,valeq,valmult,pmap[idx],pinv[val]);
			if(idxeq!=valeq||idxmult!=valmult||pmap[idxp]!=0&&pmap[idxp]!=valp||pinv[valp]!=0&&pinv[valp]!=idxp) { printf("0\n"); return; }
			if(pmap[idxp]==0) pmap[idxp]=valp,--eqfree[idxeq];
			if(pinv[valp]==0) pinv[valp]=idxp;
		}
	}

	//REPE(i,n) if(eqfree[i]>0) printf("eqclass %d: %d\n",i,eqfree[i]);
	//FORE(i,1,n) if(prodfree[i]>0) printf("prod %d: %d\n",i,prodfree[i]);

	int ret=1;
	REPE(i,n) if(eqfree[i]>1) ret=(ll)ret*fac[eqfree[i]]%MOD;
	FORE(i,1,n) if(prodfree[i]>1) ret=(ll)ret*fac[prodfree[i]]%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}