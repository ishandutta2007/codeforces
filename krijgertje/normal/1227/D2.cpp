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
#include <chrono>
#include <chrono>
#include <random>
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
const int MAXQ=200000;
const int MAXS=4*MAXN;

int n;
int a[MAXN];
int nq;
int qk[MAXQ],qidx[MAXQ],qans[MAXQ];

pair<int,int> o[MAXN];
vector<int> byk[MAXN+1];

int sval[MAXS];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=sval[2*x+1]+sval[2*x+2];
	}
}
void smod(int x,int l,int r,int IDX) {
	if(l==r) {
		++sval[x];
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*x+1,l,m,IDX); else smod(2*x+2,m+1,r,IDX);
		sval[x]=sval[2*x+1]+sval[2*x+2];
	}
}
int sget(int x,int l,int r,int OFF) {
	assert(OFF<sval[x]);
	if(l==r) {
		return l;
	} else {
		int m=l+(r-l)/2;
		if(OFF<sval[2*x+1]) return sget(2*x+1,l,m,OFF); else return sget(2*x+2,m+1,r,OFF-sval[2*x+1]);
	}
}

void solve() {
	REP(i,n) o[i]=MP(-a[i],i);
	sort(o,o+n);
	REPE(i,n) byk[i].clear();
	REP(i,nq) byk[qk[i]].PB(i);
	sinit(0,0,n-1);
	REP(i,n) {
		smod(0,0,n-1,o[i].second);
		REPSZ(j,byk[i+1]) {
			int id=byk[i+1][j];
			int idx=sget(0,0,n-1,qidx[id]);
			qans[id]=a[idx];
		}
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&qk[i],&qidx[i]),--qidx[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}