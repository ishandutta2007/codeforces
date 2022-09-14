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

int n;
int p[MAXN],t[MAXN],v[MAXN];

int res[MAXN];
int slazy[4*MAXN];
int smn[4*MAXN];
int smx[4*MAXN];

void sadd(int x,int VAL) {
	if(smn[x]!=INT_MAX) smn[x]+=VAL;
	if(smx[x]!=INT_MIN) smx[x]+=VAL;
	slazy[x]+=VAL;
}
void spush(int x) {
	if(slazy[x]==0) return;
	sadd(2*x+1,slazy[x]); sadd(2*x+2,slazy[x]); slazy[x]=0;
}
void srecalc(int x) {
	smn[x]=min(smn[2*x+1],smn[2*x+2]);
	smx[x]=max(smx[2*x+1],smx[2*x+2]);
	int tmp=slazy[x]; slazy[x]=0; sadd(x,tmp);
}
void smod(int x,int l,int r,int L,int R,int VAL) {
	if(L<=l&&r<=R) {
		sadd(x,VAL);
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,VAL);
		srecalc(x);
	}
	//printf("smod(%d..%d) with %d..%d by %d -> smn=%d smx=%d slazy=%d\n",l,r,L,R,VAL,smn[x],smx[x],slazy[x]);
}
void sinc(int x,int l,int r,int IDX) {
	if(l==r) {
		smn[x]=smx[x]=slazy[x];
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(IDX<=m) sinc(2*x+1,l,m,IDX);
		if(m+1<=IDX) sinc(2*x+2,m+1,r,IDX);
		srecalc(x);
	}
	//printf("sinc(%d..%d) with %d -> smn=%d smx=%d slazy=%d\n",l,r,IDX,smn[x],smx[x],slazy[x]);
}
int sget(int x,int l,int r,int VAL) {
	if(VAL<smn[x]||VAL>smx[x]) return -1;
	if(l==r) return res[l];
	spush(x);
	int m=l+(r-l)/2;
	if(smn[2*x+2]<=VAL&&VAL<=smx[2*x+2]) return sget(2*x+2,m+1,r,VAL); else return sget(2*x+1,l,m,VAL);
}
void sinit(int x,int l,int r) {
	if(l==r) {
		smn[x]=INT_MAX; smx[x]=INT_MIN; slazy[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r); srecalc(x);
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d%d",&p[i],&t[i]); --p[i]; if(t[i]==1) scanf("%d",&v[i]); }

	sinit(0,0,n-1);
	int sum=0;
	REP(i,n) {
		if(t[i]==1) res[p[i]]=v[i];
		smod(0,0,n-1,p[i],n-1,t[i]==1?+1:-1);
		sum+=t[i]==1?+1:-1;
		if(t[i]==1) sinc(0,0,n-1,p[i]);
		int ret=sget(0,0,n-1,sum);
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}