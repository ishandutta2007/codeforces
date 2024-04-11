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

const int MAXN=5000;

int n;
int a[MAXN];

int dp[MAXN][MAXN+1][2]; // dp[i][j][k] = min cost for j houses in [i+2..n) assuming there is no house at i+1 and a house at i iff k==1
int ans[MAXN+1];

void upd(int &a,const int &b) { a=min(a,b); }
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	for(int i=n-1;i>=0;--i) REPE(j,n) REP(k,2) {
		if(i+2>=n) {
			dp[i][j][k]=j==0?0:INT_MAX;
		} else {
			dp[i][j][k]=dp[i+1][j][0];
			if(j>0&&dp[i+2][j-1][1]!=INT_MAX) {
				int cost=dp[i+2][j-1][1];
				cost+=max(0,(k==0?a[i+1]:min(a[i+1],a[i]-1))-a[i+2]+1);
				if(i+3<n) cost+=max(0,a[i+3]-a[i+2]+1);
				upd(dp[i][j][k],cost);
			}
		}
	}

	REPE(j,n) ans[j]=j==0?0:INT_MAX;
	REP(i,n) REPE(j,n) if(dp[i][j][1]!=INT_MAX) {
		int cost=dp[i][j][1];
		if(i>0) cost+=max(0,a[i-1]-a[i]+1);
		if(i+1<n) cost+=max(0,a[i+1]-a[i]+1);
		upd(ans[j+1],cost);
	}
	FORE(i,1,(n+1)/2) { if(i!=1) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}