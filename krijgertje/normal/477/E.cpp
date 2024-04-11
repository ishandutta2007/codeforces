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

int n;
int a[400000];

int val[3][1<<20];

void init(int x,int l,int r) {
	if(l==r) { val[0][x]=val[1][x]=val[2][x]=l; return; }
	int m=l+(r-l)/2;
	init(2*x+1,l,m); init(2*x+2,m+1,r);
	{ int p=val[0][2*x+1],q=val[0][2*x+2]; val[0][x]=a[p]<=a[q]?p:q; }
	{ int p=val[1][2*x+1],q=val[1][2*x+2]; val[1][x]=a[p]-2*p<=a[q]-2*q?p:q; }
	{ int p=val[2][2*x+1],q=val[2][2*x+2]; val[2][x]=a[p]+2*p<=a[q]+2*q?p:q; }
//	printf("%d..%d %d %d %d\n",l,r,val[0][x],val[1][x],val[2][x]);
}

int findmin(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return val[0][x];
	int m=l+(r-l)/2;
	if(R<=m) return findmin(2*x+1,l,m,L,R);
	if(m+1<=L) return findmin(2*x+2,m+1,r,L,R);
	int p=findmin(2*x+1,l,m,L,R),q=findmin(2*x+2,m+1,r,L,R);
	return a[p]<=a[q]?p:q;
}

int findminsub2(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return val[1][x];
	int m=l+(r-l)/2;
	if(R<=m) return findminsub2(2*x+1,l,m,L,R);
	if(m+1<=L) return findminsub2(2*x+2,m+1,r,L,R);
	int p=findminsub2(2*x+1,l,m,L,R),q=findminsub2(2*x+2,m+1,r,L,R);
	return a[p]-2*p<=a[q]-2*q?p:q;
}

int findminadd2(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return val[2][x];
	int m=l+(r-l)/2;
	if(R<=m) return findminadd2(2*x+1,l,m,L,R);
	if(m+1<=L) return findminadd2(2*x+2,m+1,r,L,R);
	int p=findminadd2(2*x+1,l,m,L,R),q=findminadd2(2*x+2,m+1,r,L,R);
	return a[p]+2*p<=a[q]+2*q?p:q;
}

int findlast(int x,int l,int r,int L,int R,int LIM) {
//	printf("\t\tfindlast(%d,%d,%d,%d,%d,%d)\n",x,l,r,L,R,LIM);
	if(L<=l&&r<=R&&a[val[0][x]]>LIM) return -1;
	if(l==r) return val[0][x];
	int m=l+(r-l)/2,ret=-1;
	if(m+1<=R) { ret=findlast(2*x+2,m+1,r,L,R,LIM); if(ret!=-1) return ret; }
	if(L<=m) { ret=findlast(2*x+1,l,m,L,R,LIM); if(ret!=-1) return ret; }
	return -1;
}

int findfirst(int x,int l,int r,int L,int R,int LIM) {
	if(L<=l&&r<=R&&a[val[0][x]]>LIM) return n;
	if(l==r) return val[0][x];
	int m=l+(r-l)/2,ret=n;
	if(L<=m) { ret=findfirst(2*x+1,l,m,L,R,LIM); if(ret!=n) return ret; }
	if(m+1<=R) { ret=findfirst(2*x+2,m+1,r,L,R,LIM); if(ret!=n) return ret; }
	return n;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	init(0,0,n-1);

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int sr,sc,tr,tc; scanf("%d%d%d%d",&sr,&sc,&tr,&tc); --sr,--tr;
		int base=0;
		int lr=findlast(0,0,n-1,0,tr,tc); // -1 if no such
		int hr=findfirst(0,0,n-1,tr,n-1,tc); // n if no such
//		printf("(%d,%d)->(%d,%d) : %d..%d\n",sr,sc,tr,tc,lr,hr);
		if(sr<lr) { base+=lr-sr; sc=min(sc,a[findmin(0,0,n-1,sr,lr)]); sr=lr; }
		if(sr>hr) { base+=sr-hr; sc=min(sc,a[findmin(0,0,n-1,hr,sr)]); sr=hr; }
		int best=base+abs(tr-sr)+abs(tc-sc);
//		printf("\tdirect %d\n",best);
		{
			int cur=base+1+abs(tr-sr)+tc;
			if(cur<best) best=cur;
//			printf("\thome %d\n",cur);
		}
		if(lr>=0) {
			int cur=base+(sr-lr)+(tr-lr)+(sc<a[lr]?1:0)+(tc-a[lr]);
			if(cur<best) best=cur;
//			printf("\tupper %d\n",cur);
		}
		if(hr<n) {
			int cur=base+(hr-sr)+(hr-tr)+(sc<a[hr]?1:0)+(tc-a[hr]);
			if(cur<best) best=cur;
//			printf("\tlower %d\n",cur);
		}
		// base+abs(sr-xr)+(sc<a[xr]?1:0)+abs(xr-tr)+(a[xr]-tc)
		if(sr<tr&&sr==lr) { ++base; ++sr; }
		if(sr>tr&&sr==hr) { ++base; --sr; }
		{
			int xr=findmin(0,0,n-1,min(sr,tr),max(sr,tr)); // a[xr]
			int cur=base+abs(sr-xr)+(sc<a[xr]?1:0)+abs(xr-tr)+(a[xr]-tc);
			if(cur<best) best=cur;
//			printf("\tpath %d\n",cur);
		}
		if(lr+1<=min(sr,tr)) {
			int xr=findminsub2(0,0,n-1,lr+1,min(sr,tr)); // a[xr]-2xr
			int cur=base+abs(sr-xr)+(sc<a[xr]?1:0)+abs(xr-tr)+(a[xr]-tc);
			if(cur<best) best=cur;
//			printf("\tbefore %d\n",cur);
		}
		if(max(sr,tr)<=hr-1) {
			int xr=findminadd2(0,0,n-1,max(sr,tr),hr-1); // a[xr]+2xr
			int cur=base+abs(sr-xr)+(sc<a[xr]?1:0)+abs(xr-tr)+(a[xr]-tc);
			if(cur<best) best=cur;
//			printf("\tafter %d\n",cur);
		}
		printf("%d\n",best);
	}
}

int main() {
	run();
	return 0;
}