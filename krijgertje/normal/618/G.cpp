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

const int MAXN=1000;
const int MAXVAL=60;
const int C=MAXVAL+1;
typedef double Mat[MAXVAL+2][MAXVAL+2];

int N; double p; int pp;

double E[MAXVAL+1][MAXVAL+3]; // E[n][x] = expected extra value with n empty spaces, last has value x, and the one before last is lower than x (x>=2)
double F[MAXVAL+1][MAXVAL+2]; // F[n][x] = expected extra value with n empty spaces, given the next value will become at most x, and the last value is greater than x
double pgeq[MAXVAL+1][MAXVAL+3]; // pgeq[n][x] = probability the next value will become at least x when we have n empty spaces
double peq[MAXVAL+1][MAXVAL+2]; // peq[n][x] = probability the next value will become exactly x when we have n empty spaces

Mat A;
Mat B;
void mmult(Mat &A,Mat &B) {
	static Mat C;
	REPE(i,MAXVAL+1) REPE(j,MAXVAL+1) { double cur=0; REPE(k,MAXVAL+1) cur+=A[i][k]*B[k][j]; C[i][j]=cur; }
	REPE(i,MAXVAL+1) REPE(j,MAXVAL+1) A[i][j]=C[i][j];
}
void mpow(Mat &B,Mat &A,int n) {
	REPE(i,MAXVAL+1) REPE(j,MAXVAL+1) B[i][j]=i==j?1:0;
	while(n>0) {
		if(n&1) mmult(B,A);
		mmult(A,A); n/=2;
	}
}


double EC[MAXVAL+1][MAXVAL+2];
double FC[MAXVAL][MAXVAL][MAXVAL+2];

void addto(double* dst,double mlt,double *src,int shift) {
	FORE(i,shift,MAXVAL) dst[i]+=mlt*src[i-shift]; FORE(i,1,shift) assert(src[MAXVAL-shift+i]==0);
	dst[C]+=mlt*src[C];
}

void run() {
	scanf("%d%d",&N,&pp); p=0.000000001*pp;
	if(N==1) { printf("%.9lf\n",p*1+(1-p)*2); return; }

	//E[n][x]=pgeq[n][x]*(1+E[n][x+1])+(1-pgeq[n][x])*F[n][x-1]
	//F[n][x]=peq[n][x]/(1-pgeq[n][x+1])*(x+F[n-1][x-1])+(1-pgeq[n][x])/(1-pgeq[n][x+1])*F[n][x-1]
	//F[0][0]=F[0][1]=0, F[n][0]=2+E[n-1][2], E[0][2]=0
	pgeq[1][1]=1; pgeq[1][2]=1-p; pgeq[1][3]=0;
	FORE(n,2,MAXVAL) {
		pgeq[n][1]=1;
		pgeq[n][2]=(1-p)+p*p;
		FORE(x,3,n+2) pgeq[n][x]=pgeq[n][x-1]*pgeq[n-1][x-1];
	}
	FORE(n,1,MAXVAL) FORE(x,1,n+1) peq[n][x]=pgeq[n][x]-pgeq[n][x+1];

	//FORE(n,1,N) FORE(x,1,n+2) printf("pgeq[%d][%d] = %.9lf\n",n,x,pgeq[n][x]);
	//FORE(n,1,N) FORE(x,1,n+1) printf("peq[%d][%d] = %.9lf\n",n,x,peq[n][x]);

	F[0][0]=F[0][1]=E[0][2]=0;
	FORE(n,1,MAXVAL) {
		F[n][0]=2+E[n-1][2];
		FORE(x,1,n+1) F[n][x]=peq[n][x]/(1-pgeq[n][x+1])*(x+F[n-1][x-1])+(1-pgeq[n][x])/(1-pgeq[n][x+1])*F[n][x-1];
		assert(pgeq[n][n+2]==0); E[n][n+2]=F[n][n+1];
		for(int x=n+1;x>=2;--x) E[n][x]=pgeq[n][x]*(1+E[n][x+1])+(1-pgeq[n][x])*F[n][x-1];
	}

	// E[MAXVAL+z  ][x]=sum(EC   [x][i]*E[MAXVAL+z-i  ][2],i=1..MAXVAL)+EC   [x][C]
	// F[MAXVAL+z-j][x]=sum(FC[j][x][i]*E[MAXVAL+z-i-j][2],i=1..MAXVAL)+FC[j][x][C]
	// pgeq[x+z][x]=pgeq[x][x]
	// peq[x+z+1][x]=peq[x+1][x]
	for(int j=MAXVAL-1;j>=0;--j) {
		FC[j][0][C]+=2; FC[j][0][1]+=1;
		FORE(x,1,MAXVAL-1-j) {
			FC[j][x][C]+=peq[x+1][x]/(1-pgeq[x+1][x+1])*x;
			addto(FC[j][x],peq[x+1][x]/(1-pgeq[x+1][x+1]),FC[j+1][x-1],1);
			addto(FC[j][x],(1-pgeq[x][x])/(1-pgeq[x+1][x+1]),FC[j][x-1],0);
		}
	}
	addto(EC[MAXVAL],1,FC[0][MAXVAL-1],0);
	for(int x=MAXVAL-1;x>=2;--x) {
		EC[x][C]+=pgeq[x][x];
		addto(EC[x],pgeq[x][x],EC[x+1],0);
		addto(EC[x],1-pgeq[x][x],FC[0][x-1],0);
	}
	//FORE(x,2,2) { printf("E[%d+z][%d]= ",MAXVAL,x); FORE(i,1,MAXVAL) printf("%lf*E[%d+z][2] +",EC[x][i],MAXVAL-i); printf(" %lf\n",EC[x][C]); }
	//REPE(j,MAXVAL-1) FORE(x,2,MAXVAL-1-j) { printf("F[%d+z-%d][%d]= ",MAXVAL,j,x); FORE(i,1,MAXVAL) printf("%lf*E[%d+z-%d][2] +",FC[j][x][i],MAXVAL-i,j); printf(" %lf\n",FC[j][x][C]); }
	//FORE(x,1,MAXVAL-1) printf("peq[%d][%d]=%lf pgeq[%d][%d]=%lf\n",x+1,x,peq[x+1][x],x,x,pgeq[x][x]);

	REP(i,MAXVAL) A[i+1][i]=1;
	REP(i,MAXVAL) A[MAXVAL-i][MAXVAL]=EC[2][i+1]; A[C][MAXVAL]=EC[2][C];
	A[C][C]=1;

	//REPE(i,MAXVAL+1) { REPE(j,MAXVAL+1) printf("%.3lf ",A[i][j]); puts(""); }
	mpow(B,A,N-2);
	//puts(""); REPE(i,MAXVAL+1) { REPE(j,MAXVAL+1) printf("%.3lf ",B[i][j]); puts(""); }

	

	//FORE(n,1,N) FORE(x,2,n+2) printf("E[%d][%d] = %.9lf\n",n,x,E[n][x]);


	double EN1=B[C][1]; REPE(i,MAXVAL) EN1+=B[i][1]*E[i][2];
	double EN2=B[C][0]; REPE(i,MAXVAL) EN2+=B[i][0]*E[i][2];
	double ret=(1-p+p*p)*(2+EN1)+p*(1-p)*(3+EN2);
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}