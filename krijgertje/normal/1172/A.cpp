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

const int MAXN=200000;

int n;
int a[MAXN];
int b[MAXN];

int bound[MAXN];
int mxbound[MAXN+1];


int solve() {
	REP(i,n) bound[i]=-1;
	REP(i,n) if(a[i]!=-1) bound[a[i]]=n-a[i];
	REP(i,n) if(b[i]!=-1) bound[b[i]]=i+1-b[i]+n;
	mxbound[n]=0; for(int i=n-1;i>=0;--i) mxbound[i]=max(mxbound[i+1],bound[i]);

	int zeroidx=-1; REP(i,n) if(b[i]==0) zeroidx=i;
	int nok=0; if(zeroidx!=-1) { nok=n; REP(i,n) if(a[i]!=-1) nok=min(nok,a[i]); REP(i,n) if(b[i]!=-1&&i!=zeroidx+b[i]) nok=min(nok,b[i]); }

	//printf("bound:"); REP(i,n) printf(" %d",bound[i]); puts("");
	//printf("zeroidx=%d nok=%d\n",zeroidx,nok);

	int ret=mxbound[0];
	FORE(nkeep,1,nok) {
		int cbound=mxbound[nkeep];
		if(zeroidx<cbound) continue; else cbound=zeroidx;
		ret=min(ret,cbound);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	REP(i,n) scanf("%d",&b[i]),--b[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}