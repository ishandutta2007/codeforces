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

const int MAXQ=100;
const int MAXN=100;

int n,nq;
int q[MAXQ];

int a[MAXN];
int cnt[MAXN+1];

bool solve() {
	memset(a,-1,sizeof(a));
	REP(i,nq-1) {
		int d=(q[i+1]-q[i]+n)%n; if(d==0) d=n;
		if(a[q[i]]!=-1&&a[q[i]]!=d) return false; else a[q[i]]=d;
	}
	memset(cnt,0,sizeof(cnt));
	REP(i,n) if(a[i]!=-1) ++cnt[a[i]];
	if(cnt[0]!=0) return false; FORE(i,1,n) if(cnt[i]>=2) return false;
	int at=1;
	REP(i,n) if(a[i]==-1) {
		while(at<=n&&cnt[at]!=0) ++at; assert(at<=n); a[i]=at++;
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,nq) scanf("%d",&q[i]),--q[i];
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
}

int main() {
	run();
	return 0;
}