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
const double MYPI=acos(-1);
typedef double Mat[3][3];

int n,nq;
int len[MAXN],ang[MAXN];

void ident(Mat &A) { REP(i,3) REP(j,3) A[i][j]=i==j?1:0; }
void mmult(Mat &A,Mat &B,Mat &C) { static Mat tmp; REP(i,3) REP(j,3) { double cur=0; REP(k,3) cur+=B[i][k]*C[k][j]; tmp[i][j]=cur; } REP(i,3) REP(j,3) A[i][j]=tmp[i][j]; }
void printmat(Mat &A) { printf("\t\t"); REP(j,3) REP(k,3) printf(" %6.3lf",A[j][k]); puts(""); }

Mat sval[2*MAXN];
void supdleaf(int idx) {
	double a=-ang[idx]*MYPI/180,r=len[idx]; idx+=n;
	sval[idx][0][0]=cos(a); sval[idx][0][1]=-sin(a); sval[idx][0][2]=cos(a)*r;
	sval[idx][1][0]=sin(a); sval[idx][1][1]=+cos(a); sval[idx][1][2]=sin(a)*r;
	sval[idx][2][0]=0; sval[idx][2][1]=0; sval[idx][2][2]=1;
}
void sinit() {
	REP(i,n) supdleaf(i);
	for(int idx=n-1;idx>=1;--idx) mmult(sval[idx],sval[idx<<1],sval[idx<<1|1]);
}
void supd(int idx) {
	supdleaf(idx); idx+=n;
	for(idx>>=1;idx>=1;idx>>=1) mmult(sval[idx],sval[idx<<1],sval[idx<<1|1]);
}
void sget(int lidx,int ridx,Mat &A) {
	Mat lft,rgt; ident(lft); ident(rgt);
	for(lidx+=n,ridx+=n;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) mmult(lft,lft,sval[lidx++]);
		if(ridx&1) mmult(rgt,sval[--ridx],rgt);
	}
	ident(A); mmult(A,A,lft); mmult(A,A,rgt);
}
void sprint() { FOR(i,1,2*n) { printf("%d:",i); REP(j,3) REP(k,3) printf(" %6.3lf",sval[i][j][k]); puts(""); } }

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) len[i]=1,ang[i]=0;

	sinit();
	//sprint();
		
	REP(i,nq) {
		int type,idx,by; scanf("%d%d%d",&type,&idx,&by),--idx;
		if(type==1) len[idx]+=by; if(type==2) ang[idx]+=by;
		supd(idx);
		//sprint();
		Mat cur; sget(0,n,cur);
		printf("%.9lf %.9lf\n",cur[0][2],cur[1][2]);
	}
/*
	REP(i,n) printf("len=%d ang=%d\n",len[i],ang[i]);

	double x=0,y=0;
	for(int i=n-1;i>=0;--i) {
		double a=-ang[i]*MYPI/180,nx=cos(a)*(len[i]+x)-sin(a)*y,ny=sin(a)*(len[i]+x)+cos(a)*y;
		x=nx,y=ny;
		printf("\t%lf %lf\n",x,y);
	}
	printf("%.9lf %.9lf\n",x,y); */
}

int main() {
	run();
	return 0;
}