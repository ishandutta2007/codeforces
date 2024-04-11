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


ll have,want; int n,MOD;

void mmult(int A[3][3],int B[3][3],int C[3][3]) { 
	REP(i,3) REP(j,3) {
		ll cur=0;
		REP(k,3) cur+=(ll)A[i][k]*B[k][j];
		C[i][j]=cur%MOD;
	}
}




int A[65][3][3];
int B[3][3];
int C[3][3];



void run() {
	cin>>have>>want>>n>>MOD;

	A[0][0][0]=A[0][0][1]=A[0][1][0]=A[0][2][1]=1,A[0][2][2]=2,A[0][0][2]=A[0][1][1]=A[0][1][2]=A[0][2][0]=0;
	REP(j,3) REP(k,3) B[j][k]=j==k?1:0;
	for(int i=0;have>0;++i,have>>=1) {
		if((have&1)!=0) { mmult(A[i],B,C); REP(j,3) REP(k,3) B[j][k]=C[j][k]; }
		mmult(A[i],A[i],A[i+1]);
	}
	int n0=(B[0][0]+B[1][0])%MOD;
	int n1=B[2][0];
	//printf("\t%d %d\n",n0,n1);

	int ret=1%MOD;
	for(int i=0;i<n;++i,want>>=1) {
		bool one=(want&1)!=0;
		if(one) {
			ret=(ll)ret*n1%MOD;
		} else {
			ret=(ll)ret*n0%MOD;
		}
	}
	if(want!=0) ret=0;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}