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

const int MAXN=50000;
const int MAXM=50000;
const int MAXSEG=1<<18;
typedef int Mat[2][2];

ll want; int MOD;
int n,m;
int s[MAXN];
pair<ll,int> sdiff[MAXM];

int indent=0;
void mmult(Mat &C,Mat &B) {
	Mat A; REP(i,2) REP(j,2) A[i][j]=C[i][j];
	REP(i,2) REP(j,2) { ll cur=0; REP(k,2) cur+=(ll)A[i][k]*B[k][j]; C[i][j]=cur%MOD; }
	//REP(i,indent) printf("  "); printf("[%d %d; %d %d] * [%d %d; %d %d] = [%d %d; %d %d]\n",A[0][0],A[0][1],A[1][0],A[1][1],B[0][0],B[0][1],B[1][0],B[1][1],C[0][0],C[0][1],C[1][0],C[1][1]);
}
void mpow(Mat &C,ll k) {
	Mat A,B; REP(i,2) REP(j,2) A[i][j]=C[i][j];
	C[0][0]=C[1][1]=1; C[0][1]=C[1][0]=0;
	while(k>0) {
		if(k&1) mmult(C,A);
		REP(i,2) REP(j,2) B[i][j]=A[i][j];
		mmult(A,B); k>>=1;
	}
}

Mat val[MAXSEG];
void init(int x,int l,int h) {
	if(l==h) {
		val[x][0][0]=0,val[x][1][0]=1,val[x][0][1]=s[l==0?n-1:l-1],val[x][1][1]=s[l];
	} else {
		int m=l+(h-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,h);
		REP(i,2) REP(j,2) val[x][i][j]=val[2*x+1][i][j];
		mmult(val[x],val[2*x+2]);
	}
}
void range(int x,int l,int h,int L,int H,Mat &C) {
	if(L<=l&&h<=H) {
		mmult(C,val[x]);
	} else {
		int m=l+(h-l)/2;
		if(L<=m) range(2*x+1,l,m,L,H,C);
		if(m+1<=H) range(2*x+2,m+1,h,L,H,C);
	}
}
void range(Mat &C,int L,int H) {
	//printf("calcrange(%d..%d)\n",L,H); ++indent;
	C[0][0]=C[1][1]=1; C[0][1]=C[1][0]=0;
	range(0,0,n-1,L,H,C);
	//--indent;
}


void run() {
	cin>>want>>MOD;
	cin>>n; REP(i,n) cin>>s[i];
	cin>>m; REP(i,m) cin>>sdiff[i].first>>sdiff[i].second;
	sort(sdiff,sdiff+m);
	init(0,0,n-1);

	Mat A,B; A[0][0]=A[1][1]=1,A[0][1]=A[1][0]=0; ll k=0; int at=0;
	while(k<want) {
		//printf("at %lld\n",k);
		if(at<m&&sdiff[at].first==k+1) { B[0][0]=0,B[1][0]=1,B[0][1]=s[k%n],B[1][1]=sdiff[at].second; mmult(A,B); ++k; continue; }
		if(at<m&&sdiff[at].first==k) { B[0][0]=0,B[1][0]=1,B[0][1]=sdiff[at].second,B[1][1]=at+1<m&&sdiff[at+1].first==k+1?sdiff[at+1].second:s[(k+1)%n]; mmult(A,B); ++k; ++at; continue; }
		ll nk=want; if(at<m&&sdiff[at].first-1<nk) nk=sdiff[at].first-1;
		ll kp=k/n,nkp=nk/n; int kq=k%n,nkq=nk%n;
		if(kp<nkp&&kq!=n-1) { range(B,kq+1,n-1); mmult(A,B); kp,kq=n-1; }
		if(nkp-kp>1) { range(B,0,n-1); mpow(B,nkp-kp-1); mmult(A,B); kp=nkp-1; }
		{ range(B,(kq+1)%n,nkq); mmult(A,B); kq=nkq; }
		k=nk;
	}
	printf("%d\n",A[1][0]);	
}

int main() {
	run();
	return 0;
}