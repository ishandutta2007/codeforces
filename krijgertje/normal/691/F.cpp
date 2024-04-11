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
const int MAXVAL=3000000;

int a[MAXN],na;
int b[MAXN],bcnt[MAXN],nb;


ll ret[MAXVAL+1];



void run() {
	scanf("%d",&na); REP(i,na) scanf("%d",&a[i]);

	sort(a,a+na);
	nb=0; for(int at=0,to=at;at<na;at=to) { while(to<na&&a[at]==a[to]) ++to; b[nb]=a[at],bcnt[nb]=to-at,++nb; }
	memset(ret,0,sizeof(ret));
	REP(i,nb) {
		if((ll)b[i]*b[i]<MAXVAL) ret[b[i]*b[i]]+=(ll)bcnt[i]*(bcnt[i]-1); else ret[MAXVAL]+=(ll)bcnt[i]*(bcnt[i]-1);
		int j=i+1; while(j<nb&&(ll)b[i]*b[j]<MAXVAL) ret[b[i]*b[j]]+=2LL*bcnt[i]*bcnt[j],++j;
		while(j<nb) ret[MAXVAL]+=2LL*bcnt[i]*bcnt[j],++j;
	}
	for(int i=MAXVAL;i>0;--i) ret[i-1]+=ret[i];

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int q; scanf("%d",&q);
		//ll ret=0; REP(i,na) FOR(j,i+1,na) if((ll)a[i]*a[j]>=q) ret+=2;
		printf("%lld\n",ret[q]);
	}
}

int main() {
	run();
	return 0;
}