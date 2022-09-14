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


double dp[101][101][101]; // dp[i][j][k] == the probability that species i wins (i beats j, j beats k, k beats i)

void run() {
	REPE(i,100) REPE(j,100) REPE(k,100) {
		if(i==0) { dp[i][j][k]=0; continue; }
		if(j==0&&k==0) { dp[i][j][k]=1; continue; }
		dp[i][j][k]=0;
		if(j>0) dp[i][j][k]+=i*j*dp[i][j-1][k];
		if(k>0) dp[i][j][k]+=j*k*dp[i][j][k-1];
		if(i>0) dp[i][j][k]+=k*i*dp[i-1][j][k];
		dp[i][j][k]/=i*j+j*k+k*i;
	}

	int r,s,p;
	scanf("%d%d%d",&r,&s,&p);
	printf("%.9lf %.9lf %.9lf\n",dp[r][s][p],dp[s][p][r],dp[p][r][s]);
}

int main() {
	run();
	return 0;
}