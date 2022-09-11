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

const int MAXN=50;

int n;
int sz[MAXN];

int dp[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&sz[i]);
	int sum=0; REP(i,n) sum+=sz[i];
	dp[n]=0;
	for(int i=n-1;i>=0;--i) {
		dp[i]=INT_MIN;
		int oth=0;
		FOR(j,i,n) {
			int now=sz[j]-oth-dp[j+1]; if(now>dp[i]) dp[i]=now;
			//printf("\t%d->%d\n",j,now);
			oth+=sz[j];
		}
		//printf("dp%d=%d\n",i,dp[i]);
	}
	// b-a=dp[0] b+a=sum -> (sum+dp[0])/2=b, (sum-dp[0])/2=a
	printf("%d %d\n",(sum-dp[0])/2,(sum+dp[0])/2);
}

int main() {
	run();
	return 0;
}