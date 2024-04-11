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

const int MAXQ=500000;
const int N=500000;
const int BSZ=500;

int nq;
int qkind[MAXQ],qx[MAXQ],qy[MAXQ]; ll qans[MAXQ];

int a[N+1];
ll sum[BSZ+1][BSZ];

void solve() {
	memset(a,0,sizeof(a));
	memset(sum,0,sizeof(sum));
	REP(i,nq) {
		if(qkind[i]==1) {
			int idx=qx[i],delta=qy[i];
			a[idx]+=delta;
			FORE(j,1,BSZ) sum[j][idx%j]+=delta;
		}
		if(qkind[i]==2) {
			int mod=qx[i],off=qy[i];
			if(mod<=BSZ) {
				qans[i]=sum[mod][off];
			} else {
				qans[i]=0; for(int j=off;j<=N;j+=mod) qans[i]+=a[j];
			}
		}
	}
}

void run() {
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d",&qkind[i],&qx[i],&qy[i]);
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}