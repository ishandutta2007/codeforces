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

const int MAXN=5000;

int n;
int a[MAXN];

short ic[MAXN][MAXN]; // inc[i][j] = first element k in [i..n) such that a[k]==a[j]+1
short dc[MAXN][MAXN]; // dec[i][j] = first element k in [i..n) such that a[k]==a[j]-1
short sm[MAXN][MAXN]; // sme[i][j] = first element k in [i..n) such that a[k]==a[j] (mod 7)

short dp[MAXN+1][MAXN+1]; // dp[i][j] = maximum sum of length when last element of first sequence is i-1 and last element of second sequence is j-1 (or not started if -1)

inline void upd(int i,int j,int v) { if(i>j) swap(i,j); if(dp[i][j]==-1||v>dp[i][j]) dp[i][j]=v; }
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	//n=MAXN; REP(i,n) a[i]=rand()%1;

	REP(j,n) for(int i=n-1;i>=0;--i) ic[j][i]=a[i]==a[j]+1?i:i+1<n?ic[j][i+1]:-1;
	REP(j,n) for(int i=n-1;i>=0;--i) dc[j][i]=a[i]==a[j]-1?i:i+1<n?dc[j][i+1]:-1;
	REP(j,n) for(int i=n-1;i>=0;--i) sm[j][i]=a[i]%7==a[j]%7?i:i+1<n?sm[j][i+1]:-1;

	REPE(i,n) REPE(j,n) dp[i][j]=-1;
	dp[0][0]=0;
	REP(i,n) FOR(j,i,n) if(dp[i][j]!=-1) {
		int k=j;
		if(i==0) FOR(ii,k,n) upd(ii+1,j,dp[i][j]+1);
		if(j==0) FOR(jj,k,n) upd(i,jj+1,dp[i][j]+1);
		if(i!=0) {
			if(ic[i-1][k]!=-1) upd(ic[i-1][k]+1,j,dp[i][j]+1);
			if(dc[i-1][k]!=-1) upd(dc[i-1][k]+1,j,dp[i][j]+1);
			if(sm[i-1][k]!=-1) upd(sm[i-1][k]+1,j,dp[i][j]+1);
		}
		if(j!=0) {
			if(ic[j-1][k]!=-1) upd(i,ic[j-1][k]+1,dp[i][j]+1);
			if(dc[j-1][k]!=-1) upd(i,dc[j-1][k]+1,dp[i][j]+1);
			if(sm[j-1][k]!=-1) upd(i,sm[j-1][k]+1,dp[i][j]+1);
		}
	}
	int ret=0; FORE(i,1,n) FORE(j,i,n) if(dp[i][j]!=-1) ret=max(ret,(int)dp[i][j]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}