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
const int MAXVAL=1000000000;
const int MAXS=4*MAXN;

int n,nq;
int a[MAXN];

int smx[MAXS];
ll ssum[MAXS];

void sinit(int x,int l,int r) {
	if(l==r) {
		smx[x]=ssum[x]=a[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		smx[x]=max(smx[2*x+1],smx[2*x+2]);
		ssum[x]=ssum[2*x+1]+ssum[2*x+2];
	}
}
void supd(int x,int l,int r,int IDX) {
	if(l==r) {
		smx[x]=ssum[x]=a[IDX];
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) supd(2*x+1,l,m,IDX);
		if(m+1<=IDX) supd(2*x+2,m+1,r,IDX);
		smx[x]=max(smx[2*x+1],smx[2*x+2]);
		ssum[x]=ssum[2*x+1]+ssum[2*x+2];
	}
}
int sgetfirst(int x,int l,int r,int L,int R,int LIM) {
	if(smx[x]<LIM) return -1;
	if(l==r) return l;
	int m=l+(r-l)/2;
	if(L<=m) { int cur=sgetfirst(2*x+1,l,m,L,R,LIM); if(cur!=-1) return cur; }
	if(m+1<=R) { int cur=sgetfirst(2*x+2,m+1,r,L,R,LIM); if(cur!=-1) return cur; }
	return -1;
}
ll sgetsum(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return ssum[x];
	int m=l+(r-l)/2;
	ll ret=0;
	if(L<=m) ret+=sgetsum(2*x+1,l,m,L,R);
	if(m+1<=R) ret+=sgetsum(2*x+2,m+1,r,L,R);
	return ret;
}

int solve() {
	if(a[0]==0) return 1;
	int at=0;
	ll sum=a[0];
	while(sum<=MAXVAL&&at+1<n) {
		at=sgetfirst(0,0,n-1,at+1,n-1,sum);
		if(at==-1) return -1;
		sum=sgetsum(0,0,n-1,0,at);
		if(sum==2*a[at]) return at+1;
	}
	return -1;
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]);

	sinit(0,0,n-1);
	REP(i,nq) {
		int idx,val; scanf("%d%d",&idx,&val); --idx;
		a[idx]=val; supd(0,0,n-1,idx);
		int ans=solve();
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}