#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,nops;
int a[MAXN];


int C[MAXN+1][MAXN+1];

int dim;
vector<vector<int>> A;
vector<vector<int>> B;

void mmlt(vector<vector<int>> &A,const vector<vector<int>> &B) {
	vector<vector<int>> C(dim,vector<int>(dim));
	REP(i,dim) REP(j,dim) { int cur=0; REP(k,dim) cur=(cur+(ll)A[i][k]*B[k][j])%MOD; C[i][j]=cur; }
	REP(i,dim) REP(j,dim) A[i][j]=C[i][j];
}
vector<vector<int>> pw(vector<vector<int>> A,int n) {
	vector<vector<int>> ret(dim,vector<int>(dim,0)); REP(i,dim) ret[i][i]=1;
	while(true) { if(n&1) mmlt(ret,A); if((n>>=1)==0) return ret; mmlt(A,A); } 
}

int solve() {
	REPE(i,MAXN) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }

	int nzero=0,none=0; REP(i,n) if(a[i]==0) ++nzero; else ++none;
	int mxflips=min(nzero,none);
	int waystot=n*(n-1)/2,den=pw(waystot,MOD-2);
	
	dim=mxflips+1;
	A=vector<vector<int>>(dim,vector<int>(dim,0));
	REP(i,dim) {
		int norigzero=nzero-i,nflippedzero=i,norigone=none-i,nflippedone=i;
		int waysinc=norigzero*norigone;
		int waysdec=nflippedzero*nflippedone;
		int wayssame=waystot-waysinc-waysdec;
		//printf("%d -> %d / %d / %d\n",i,waysdec,wayssame,waysinc);
		if(waysinc>0) inc(A[i][i+1],(ll)waysinc*den%MOD);
		if(wayssame>0) inc(A[i][i],(ll)wayssame*den%MOD);
		if(waysdec>0) inc(A[i][i-1],(ll)waysdec*den%MOD);
	}
	B=pw(A,nops);

	int wantzeroflips=0,wantoneflips=0;
	REP(i,n) if(i<nzero) { if(a[i]==1) ++wantoneflips; } else { if(a[i]==0) ++wantzeroflips; }
	assert(wantzeroflips==wantoneflips&&wantzeroflips<=mxflips);
	return (ll)B[0][wantzeroflips]*pw(C[nzero][wantzeroflips],MOD-2)%MOD*pw(C[none][wantoneflips],MOD-2)%MOD;
}

void run() {
	scanf("%d%d",&n,&nops);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}