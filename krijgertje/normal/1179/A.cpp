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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXQ=300000;

int n,nq;
int val[MAXN];
ll q[MAXQ]; int qans[MAXQ][2];

int mxidx[MAXN];

int nval[MAXN-1];

void solve() {
	mxidx[0]=0; FOR(i,1,n) if(val[i]>val[mxidx[i-1]]) mxidx[i]=i; else mxidx[i]=mxidx[i-1];
	REP(i,n-1) { int a=val[mxidx[i]],b=val[i+1]; nval[i]=min(a,b); }
	REP(i,nq) {
		ll nbefore=q[i]-1;
		if(nbefore<=n-2) {
			int a=val[mxidx[nbefore]],b=val[nbefore+1];
			qans[i][0]=a,qans[i][1]=b;
		} else {
			ll nrem=nbefore-(n-1);
			nrem%=n-1;
			int idx=nrem;
			qans[i][0]=val[mxidx[n-1]],qans[i][1]=nval[idx];
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,nq) scanf("%lld",&q[i]);
	solve();
	REP(i,nq) printf("%d %d\n",qans[i][0],qans[i][1]);
}

int main() {
	run();
	return 0;
}