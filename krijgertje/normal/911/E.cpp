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

int n,nhave;
int a[MAXN];

int stck[MAXN],nstck;

bool solve() {
	nstck=0;
	int nxt=1;
	REP(i,nhave) {
		int cur=a[i];
		if(nstck>0&&cur>stck[nstck-1]) return false;
		stck[nstck++]=cur;
		while(nstck>0&&stck[nstck-1]==nxt) ++nxt,--nstck;
	}
	int idx=nhave;
	while(nxt<=n) {
		if(nstck>0&&stck[nstck-1]==nxt) { ++nxt,--nstck; continue; }
		int mx=nstck>0?stck[nstck-1]-1:n; for(int i=mx;i>=nxt;--i) a[idx++]=i; nxt=mx+1;
	}
	return true;	
}

void run() {
	scanf("%d%d",&n,&nhave); REP(i,nhave) scanf("%d",&a[i]);
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
}

int main() {
	run();
	return 0;
}