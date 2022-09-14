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

const int MAXM=127;
typedef double Mat[MAXM+1][MAXM+1];

int n,m;
double p[MAXM+1];

void mmult(Mat &A,Mat &B) {
	Mat C; REPE(i,MAXM) REPE(j,MAXM) { double cur=0; REPE(k,MAXM) cur+=A[i][k]*B[k][j]; C[i][j]=cur; } REPE(i,MAXM) REPE(j,MAXM) A[i][j]=C[i][j];
}
void mpow(Mat &A,int n) {
	Mat B; REPE(i,MAXM) REPE(j,MAXM) B[i][j]=A[i][j],A[i][j]=i==j?1:0;
	while(true) {
		if(n&1) mmult(A,B);
		if((n>>=1)==0) break;
		mmult(B,B);
	}
}

Mat A;

void run() {
	scanf("%d%d",&n,&m); REPE(i,m) scanf("%lf",&p[i]);
	memset(A,0,sizeof(A));
	REPE(i,MAXM) REPE(j,m) A[i][i^j]=p[j];
	mpow(A,n);
	printf("%.9lf\n",1-A[0][0]);
	//double sum=0; REPE(i,MAXM) if(A[0][i]!=0) printf("\t%d:%.9lf\n",i,A[0][i]),sum+=A[0][i]; printf("=%.9lf\n",sum);
}

int main() {
	run();
	return 0;
}