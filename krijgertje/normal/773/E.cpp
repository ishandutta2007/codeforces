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

const int MAXN=500000;

int n;
int q[MAXN];
int qidx[MAXN];
pair<int,int> o[MAXN];
int x[MAXN];
int ret[MAXN];
int val[MAXN];

int slazy[4*MAXN];
int sloweridx[4*MAXN],slowerval[4*MAXN]; // if our range becomes slowerval[x] lower, then sloweridx[x] would make it higher again
int shigheridx[4*MAXN],shigherval[4*MAXN]; // if our range becomes shigherval[x] higher, then shigheridx[x] would make it lower again

void sapply(int x,int delta) {
	//printf("sapply(%d,%d)\n",x,delta);
	slazy[x]+=delta;
	if(slowerval[x]!=INT_MAX) slowerval[x]+=delta; assert(slowerval[x]>0);
	if(shigherval[x]!=INT_MAX) shigherval[x]-=delta; assert(shigherval[x]>0);
}

void spush(int x) {
	if(slazy[x]==0) return;
	//printf("spush(%d)\n",x);
	sapply(2*x+1,slazy[x]);
	sapply(2*x+2,slazy[x]);
	slazy[x]=0;
}

void scalc(int x) {
	assert(slazy[x]==0);
	slowerval[x]=slowerval[2*x+1],sloweridx[x]=sloweridx[2*x+1]; if(slowerval[2*x+2]<slowerval[x]) slowerval[x]=slowerval[2*x+2],sloweridx[x]=sloweridx[2*x+2];
	shigherval[x]=shigherval[2*x+1],shigheridx[x]=shigheridx[2*x+1]; if(shigherval[2*x+2]<shigherval[x]) shigherval[x]=shigherval[2*x+2],shigheridx[x]=shigheridx[2*x+2];
}

void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		sloweridx[x]=-1; slowerval[x]=INT_MAX;
		shigheridx[x]=-1; shigherval[x]=INT_MAX;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		scalc(x);
	}
}

int sget(int x,int l,int r,int IDX) {
	//printf("sget(%d,%d,%d,%d) [lazy=%d]\n",x,l,r,IDX,slazy[x]);
	if(l==r) {
		return slazy[x];
	} else {
		spush(x);
		int m=l+(r-l)/2;
		int ret=IDX<=m?sget(2*x+1,l,m,IDX):sget(2*x+2,m+1,r,IDX);
		return ret;
	}
}

int sfirstlower(int x,int l,int r,int IDX) {
	if(l>r||IDX>r) return -1;
	if(l>=IDX) {
		return slowerval[x]==1?sloweridx[x]:-1;
	} else {
		spush(x);
		int m=l+(r-l)/2;
		int ret=-1;
		if(ret==-1&&IDX<=m) ret=sfirstlower(2*x+1,l,m,IDX);
		if(ret==-1) ret=sfirstlower(2*x+2,m+1,r,IDX);
		return ret;
	}
}

int sfirsthigher(int x,int l,int r,int IDX) {
	//printf("sfirsthigher(%d,%d..%d,%d)\n",x,l,r,IDX);
	if(l>r||IDX>r) return -1;
	if(shigherval[x]!=INT_MAX) assert(shigheridx[x]>=l&&shigheridx[x]<=r);
	if(l>=IDX) {
		return shigherval[x]==1?shigheridx[x]:-1;
	} else {
		spush(x);
		int m=l+(r-l)/2;
		int ret=-1;
		if(ret==-1&&IDX<=m) ret=sfirsthigher(2*x+1,l,m,IDX);
		if(ret==-1) ret=sfirsthigher(2*x+2,m+1,r,IDX);
		return ret;
	}
}

void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		scalc(x);
	}
}

void ssetlower(int x,int l,int r,int IDX,int VAL) {
	if(l==r) {
		sloweridx[x]=l; slowerval[x]=VAL;
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(IDX<=m) ssetlower(2*x+1,l,m,IDX,VAL); else ssetlower(2*x+2,m+1,r,IDX,VAL);
		scalc(x);
	}
}

void ssethigher(int x,int l,int r,int IDX,int VAL) {
	if(l==r) {
		shigheridx[x]=VAL==INT_MAX?-1:l; shigherval[x]=VAL;
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(IDX<=m) ssethigher(2*x+1,l,m,IDX,VAL); else ssethigher(2*x+2,m+1,r,IDX,VAL);
		scalc(x);
	}
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&q[i]);
	REP(i,n) o[i]=MP(q[i],i); sort(o,o+n);
	REP(i,n) x[i]=o[i].first,qidx[o[i].second]=i;

	sinit(0,0,n-1);
	REP(i,n) val[i]=0;

	REP(i,n) {
		int idx=qidx[i];
		int cur=sget(0,0,n-1,idx);
		//printf("inserting %d. current value=%d\n",x[idx],cur);
		if(cur==x[idx]) {
			ssetlower(0,0,n-1,idx,1);
			ssethigher(0,0,n-1,idx,1);
		}
		if(cur>x[idx]) {
			int nxt=sfirstlower(0,0,n-1,idx+1);
			//printf("decrease of range is cancelled at %d",nxt); if(nxt!=-1) printf(" (value=%d)",x[nxt]); puts("");
			if(nxt==-1) {
				smod(0,0,n-1,idx,n-1,-1);
			} else {
				smod(0,0,n-1,idx,nxt-1,-1);
				val[nxt]++;
				ssethigher(0,0,n-1,nxt,1);
				if(val[nxt]==1) ssetlower(0,0,n-1,nxt,INT_MAX);
			}
			val[idx]=-1;
			ssetlower(0,0,n-1,idx,cur-x[idx]);
		}
		if(cur<x[idx]) {
			int nxt=sfirsthigher(0,0,n-1,idx+1);
			//printf("increase of range is cancelled at %d",nxt); if(nxt!=-1) printf(" (value=%d)",x[nxt]); puts("");
			if(nxt==-1) {
				smod(0,0,n-1,idx,n-1,+1);
			} else {
				smod(0,0,n-1,idx,nxt-1,+1);
				val[nxt]--;
				ssetlower(0,0,n-1,nxt,1);
				if(val[nxt]==-1) ssethigher(0,0,n-1,nxt,INT_MAX);
			}
			val[idx]=+1;
			ssethigher(0,0,n-1,idx,x[idx]-cur);
		}
		ret[i]=sget(0,0,n-1,n-1);
		//puts("");
	}
	REP(i,n) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}