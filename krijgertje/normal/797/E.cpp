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
const int MAXQ=100000;
typedef struct Q { int id,s,k; } Q;
bool operator<(const Q &a,const Q &b) { if(a.k!=b.k) return a.k<b.k; return a.id<b.id; }

int n,nq;
int a[MAXN];
Q q[MAXQ];
int ret[MAXQ];

int stupid(int at,int k) {
	int ret=0;
	while(at<n) {
		++ret;
		at+=a[at]+k;
	}
	return ret;
}

int dp[MAXN];
void precalc(int k) {
	for(int i=n-1;i>=0;--i) { int ni=i+a[i]+k; dp[i]=1+(ni>=n?0:dp[ni]); }
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq); REP(i,nq) scanf("%d%d",&q[i].s,&q[i].k),--q[i].s,q[i].id=i; sort(q,q+nq);

	for(int at=0,to=at;at<nq;at=to) {
		int k=q[at].k;
		while(to<nq&&q[to].k==k) ++to;
		if(k<=400) {
			precalc(k);
			FOR(i,at,to) ret[q[i].id]=dp[q[i].s];
		} else {
			FOR(i,at,to) ret[q[i].id]=stupid(q[i].s,k);
		}
	}

	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}