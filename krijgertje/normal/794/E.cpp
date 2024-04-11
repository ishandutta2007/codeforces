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

const int MAXN=300000;

int nx;
int x[MAXN];
int res[MAXN];

void solve(int s) {
	assert(s<=nx&&(nx-s)%2==0);
	int b=(nx-s)/2;
	int ret=x[b]; FOR(i,1,s) ret=max(ret,x[b+i]); res[s]=ret;
	while(s+2<=nx) {
		s+=2,--b;
		ret=max(ret,max(x[b],x[nx-b-1]));
		res[s]=ret;
	}
}

int n;
int a[MAXN];
int ret[MAXN];

void solve() {
	if(n==1) { ret[0]=a[0]; return; }
	if(n==2) { ret[0]=ret[1]=max(a[0],a[1]); return; }
	if(n%2==0) {
		nx=n; REP(i,nx) x[i]=a[i]; solve(2); for(int i=2;i<=nx;i+=2) ret[i-2]=res[i];
		nx=n-1; REP(i,nx) x[i]=min(a[i],a[i+1]); solve(3); for(int i=3;i<=nx;i+=2) ret[i-2]=res[i];
	} else {
		nx=n; REP(i,nx) x[i]=a[i]; solve(3); for(int i=3;i<=nx;i+=2) ret[i-2]=res[i];
		nx=n-1; REP(i,nx) x[i]=min(a[i],a[i+1]); solve(2); for(int i=2;i<=nx;i+=2) ret[i-2]=res[i];
	}
	ret[n-1]=ret[n-2];
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}